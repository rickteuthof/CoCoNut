mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(dir $(mkfile_path))

LDFLAGS += -L.$(current_dir)/bin/
LDLIBS += -lcoconutlib

COCONUT_INCLUDE := -I$(current_dir)include/ 
COCONUT_HEADER_DIR := $(current_dir)include/
COCONUT_SOURCE_DIR := $(current_dir)src/
COCONUT_DIR := $(current_dir)
COCONUT_LIB := $(current_dir)/bin/libcoconutlib.a
