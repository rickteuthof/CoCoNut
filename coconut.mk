MODULES := framework core ccnstd generated
MKDIR := mkdir -p
VPATH := src/

CC ?= gcc

BUILD_DIR := build
BIN_DIR := bin

AR := ar
AR_FLAGS := rcs

CFLAGS += -std=gnu11
INCLUDE_DIRS = -Iinclude/framework -Iinclude

SRC := $(foreach module, $(MODULES), $(addprefix $(module)/, $(notdir $(wildcard src/$(module)/*.c))))
SRC := $(sort $(SRC)) # Create reproducible builds.
DEPS := $(SRC:.c=.d)
OBJS := $(SRC:.c=.o)
OBJS := $(addprefix $(BUILD_DIR)/, $(OBJS))
DEPS := $(addprefix $(BUILD_DIR)/, $(DEPS))

DEPFLAGS = -MT $@ -MD -MP -MF $(BUILD_DIR)/$*.d

$(BIN_DIR)/libcoconutlib.a: $(OBJS)
	$(SILENCED)$(AR) $(AR_FLAGS) $@ $^


$(OBJS): | $(BUILD_DIR) $(BIN_DIR)

$(BUILD_DIR):
	$(SILENCED)$(MKDIR) $(BUILD_DIR)
	$(MKDIR) $(foreach module, $(MODULES), $(BUILD_DIR)/$(module))

$(BIN_DIR):
	$(SILENCED)$(MKDIR) $(BIN_DIR)

$(BUILD_DIR)/%.o: %.c
	$(SILENCED)$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE_DIRS) -o $@ -c $<

.PHONY += clean
clean:
	rm -rf $(BIN_DIR)
	rm -rf $(BUILD_DIR)

.PHONY += totalclean
totalclean: clean
	rm -rf src/generated
	rm -rf include/generated

-include $(DEPS)
