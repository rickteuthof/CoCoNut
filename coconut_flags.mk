mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(dir $(mkfile_path))

coconut_lflags := -L.$(current_dir)/bin/
coconut_ldflags := -lcoconutlib

coconut_include := -I$(current_dir)include/ 
