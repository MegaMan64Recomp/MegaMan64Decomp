def apply(config, args):
    config["baseimg"] = "baserom.us.z64"
    config["myimg"] = "build/megaman64.z64"
    config["mapfile"] = "build/megaman64.map"
    config["source_directories"] = ['./src','./include']
    config["expected_dir"] = "." # needed for -o
    # config["makeflags"] = []
    # config["objdump_executable"] = ""