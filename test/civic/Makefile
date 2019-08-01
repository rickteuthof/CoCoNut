MODULES = src/generated src/passes src/traversal src/generated/internal src/core
MKDIR = mkdir -p
VPATH := $(MODULES)

CC ?= gcc

BUILD_DIR = build
BIN_DIR = bin

CFLAGS ?= --std=gnu11 -Wall -g -fPIC -DPIC -D_POSIX_SOURCE -D_DEFAULT_SOURCE -Dlint
include ../../coconut_flags.mk

INCLUDE_DIRS += -Iinclude/ -I./CoCoNut/include/ -I./CoCoNut/include/ccnstd

SRC := $(foreach module, $(MODULES), $(notdir $(wildcard $(module)/*.c)))
SRC := $(sort $(SRC)) # Create reproducible builds.
OBJS := $(SRC:.c=.o)
OBJS := $(addprefix $(BUILD_DIR)/, $(OBJS))

LDFLAGS += -lcoconutlib
LFLAGS += -L./CoCoNut/bin

BIN := bin

compiler: $(BIN)/civcc 

$(BIN)/civcc: $(OBJS) CoCoNut/bin/libcoconutlib.a
	$(SILENCED)$(CC) -o $@ $^ $(LFLAGS) $(LDFLAGS)

$(OBJS): | $(BUILD_DIR) $(BIN_DIR)

$(BUILD_DIR):
	$(SILENCED)$(MKDIR) $(BUILD_DIR)

$(BIN_DIR):
	$(SILENCED)$(MKDIR) $(BIN_DIR)

$(BUILD_DIR)/%.o: %.c
	$(SILENCED)$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o $@ -c $<


cocogen: CoCoNut/dsl/main.coconut
	python3 ../../coconut.py build
	make -C CoCoNut

src/generated:
	$(MKDIR) src/generated

include/generated:
	$(MKDIR) include/generated

.PHONY += clean
clean:
	rm -rf $(BUILD_DIR)
	rm -rf src/generated
	rm -rf include/generated
