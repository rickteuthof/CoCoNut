MODULES = src/framework src/core src/ccnstd
MKDIR = mkdir -p
VPATH := $(MODULES)

CC ?= gcc

BUILD_DIR = build/coconutlib
BIN_DIR = bin

AR := ar
AR_FLAGS := rcs

CFLAGS ?= --std=gnu11
INCLUDE_DIRS = -Iinclude/framework -Iinclude

SRC := $(foreach module, $(MODULES), $(notdir $(wildcard $(module)/*.c)))
SRC := $(sort $(SRC)) # Create reproducible builds.
OBJS := $(SRC:.c=.o)
OBJS := $(addprefix $(BUILD_DIR)/, $(OBJS))

BIN := bin

$(BIN_DIR)/libcoconutlib.a: $(OBJS)
	$(SILENCED)$(AR) $(AR_FLAGS) $@ $^


$(OBJS): | $(BUILD_DIR) $(BIN_DIR)

$(BUILD_DIR):
	$(SILENCED)$(MKDIR) $(BUILD_DIR)

$(BIN_DIR):
	$(SILENCED)$(MKDIR) $(BIN_DIR)

$(BUILD_DIR)/%.o: %.c
	$(SILENCED)$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o $@ -c $<

.PHONY += clean
clean:
	rm -rf $(BUILD_DIR)
