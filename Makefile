### Build Options ###

BASEROM      := baserom.us.z64
TARGET       := megaman64
COMPARE      ?= 1
NON_MATCHING ?= 0
CHECK        ?= 1
VERBOSE      ?= 0
MOD 		 ?= 0

# Fail early if baserom does not exist
ifeq ($(wildcard $(BASEROM)),)
$(error Baserom `$(BASEROM)' not found.)
endif

# NON_MATCHING=1 implies COMPARE=0
ifeq ($(NON_MATCHING),1)
override COMPARE=0
endif

ifeq ($(VERBOSE),0)
V := @
endif

ifeq ($(OS),Windows_NT)
  DETECTED_OS=windows
else
  UNAME_S := $(shell uname -s)
  ifeq ($(UNAME_S),Linux)
    DETECTED_OS=linux
  endif
  ifeq ($(UNAME_S),Darwin)
    DETECTED_OS=macos
    MAKE=gmake
    CPPFLAGS += -xc++
  endif
endif


### Output ###

BUILD_DIR := build
LIBULTRA_DIR := lib/libultra
LIBMUS_DIR   := lib/libmus
ROM       := $(BUILD_DIR)/$(TARGET).z64
ELF       := $(BUILD_DIR)/$(TARGET).elf
LD_SCRIPT := $(TARGET).ld
LD_MAP    := $(BUILD_DIR)/$(TARGET).map


### Tools ###

PYTHON		:= venv/bin/python
N64CKSUM	:= $(PYTHON) tools/n64cksum.py
SPLAT_YAML	:= megaman64.yaml
MOD_YAML	:= megaman64_mod.yaml
SPLAT	:= $(PYTHON) -m splat split $(SPLAT_YAML)
MOD_SPLAT	:= $(PYTHON) -m splat split $(MOD_YAML)
EMULATOR   := mupen64plus
DIFF       := diff

CROSS    := mips-linux-gnu-
AS       := $(CROSS)as
LD       := $(CROSS)ld
OBJCOPY  := $(CROSS)objcopy
STRIP    := $(CROSS)strip

CC       := tools/gcc_kmc/$(DETECTED_OS)/2.7.2/gcc
CC_HOST  := gcc
CPP      := cpp -P

PRINT := printf '
 ENDCOLOR := \033[0m
 WHITE     := \033[0m
 ENDWHITE  := $(ENDCOLOR)
 GREEN     := \033[0;32m
 ENDGREEN  := $(ENDCOLOR)
 BLUE      := \033[0;34m
 ENDBLUE   := $(ENDCOLOR)
 YELLOW    := \033[0;33m
 ENDYELLOW := $(ENDCOLOR)
 PURPLE    := \033[0;35m
 ENDPURPLE := $(ENDCOLOR)
ENDLINE := \n'

### Compiler Options ###

ASFLAGS        := -G 0 -I include -mips3 -mabi=32
CFLAGS         := -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C -D_FINALROM=0 -DNDEBUG
CPPFLAGS       := -I include -I $(BUILD_DIR)/include -I src -I $(LIBULTRA_DIR)/include -DF3DEX_GBI_2 -D_LANGUAGE_C -D_MIPS_SZLONG=32
LDFLAGS        := -T undefined_syms.txt -T undefined_funcs_auto.txt -T undefined_syms_auto.txt -T $(LD_SCRIPT) -Map $(LD_MAP) --no-check-sections
CHECK_WARNINGS := -Wall -Wextra -Wunused-but-set-variable -Wno-format-security -Wno-unused-parameter -Wno-sign-compare -Wno-unused-variable -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast -m32
CFLAGS_CHECK   := -fcommon -fsyntax-only -fsigned-char -nostdinc -fno-builtin -D CC_CHECK -D _LANGUAGE_C -std=gnu90 $(CHECK_WARNINGS)

ifneq ($(CHECK),1)
CFLAGS_CHECK += -w
endif

ifeq ($(MOD),1)
CFLAGS += -DMOD
CPPFLAGS += -DMOD
endif

OPTFLAGS := -O3

### Sources ###

# Object files
OBJECTS := $(shell grep -E 'build.+\.o' $(LD_SCRIPT) -o)
OBJECTS := $(OBJECTS:build/%=$(BUILD_DIR)/%)
DEPENDS := $(OBJECTS:=.d) 

### Targets ###
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/%.o: OPTFLAGS := -O3 -g0
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/%.o: CPPFLAGS += -I $(LIBULTRA_DIR)/src -I $(LIBULTRA_DIR)/include/PR -I $(LIBULTRA_DIR)/include/libc

$(BUILD_DIR)/$(LIBMUS_DIR)/src/%.o: OPTFLAGS := -O3 -G0
$(BUILD_DIR)/$(LIBMUS_DIR)/src/%.o: CPPFLAGS += -I $(LIBULTRA_DIR)/include/PR -I $(LIBMUS_DIR)/include -DSUPPORT_NAUDIO

all: $(ROM)

objects: $(OBJECTS)

-include $(DEPENDS)

clean:
	$(V)rm -rf build

distclean: clean
	$(V)rm -rf asm
	$(V)rm -rf assets
	$(V)rm -f *auto.txt
	$(V)rm -f megaman64.ld
	$(V)rm -f include/ld_addrs.h

setup: distclean split

split:
	$(V)rm -rf asm
	$(V)$(SPLAT)
	
test: $(ROM)
	$(V)$(EMULATOR) $<

# Compile .c files with kmc gcc
$(BUILD_DIR)/%.c.o: %.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_kmc/$(DETECTED_OS)/2.7.2 && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

# Assemble .s files with modern gnu as
$(BUILD_DIR)/%.s.o: %.s
	@$(PRINT)$(GREEN)Assembling asm file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	$(V)$(AS) $(ASFLAGS) -o $@ $<

# Create .o files from .bin files.
$(BUILD_DIR)/%.bin.o: %.bin
	@$(PRINT)$(GREEN)objcopying binary file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	$(V)$(LD) -r -b binary -o $@ $<

$(BUILD_DIR)/$(LD_SCRIPT): $(LD_SCRIPT)
	@$(PRINT)$(GREEN)Preprocessing linker script: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	$(V)$(CPP) -P -DBUILD_PATH=$(BUILD_DIR) $< -o $@

# Link the .o files into the .elf
$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) $(BUILD_DIR)/$(LD_SCRIPT)
	@$(PRINT)$(GREEN)Linking elf file: $(ENDGREEN)$(BLUE)$@$(ENDBLUE)$(ENDLINE)
	$(V)$(LD) $(LDFLAGS) -o $@

# Convert the .elf to the final rom
$(ROM): $(BUILD_DIR)/$(TARGET).elf
	@$(PRINT)$(GREEN)Creating z64: $(ENDGREEN)$(BLUE)$@$(ENDBLUE)$(ENDLINE)
	$(V)$(OBJCOPY) $< $@ -O binary
	$(V)$(N64CKSUM) $@
ifeq ($(COMPARE),1)
	@$(DIFF) $(BASEROM) $(ROM) && printf "OK\n" || (echo 'The build succeeded, but did not match the base ROM. This is expected if you are making changes to the game. To skip this check, use "make COMPARE=0".' && false)
endif

### Make Settings ###

.PHONY: all clean distclean test setup split

# Remove built-in implicit rules to improve performance
MAKEFLAGS += --no-builtin-rules

# Print target for debugging
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true