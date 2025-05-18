# Generic C makefile - 2025 - BlivionIaG

TARGET = $(notdir $(CURDIR))

CFLAGS = -std=gnu23 -Wall -Wextra -Os -g -MMD -MP

# Basic library configuration (libraries that don't use pkg-config)
LIBS = m
LDFLAGS = $(addprefix -l,$(LIBS))

# pkg-config libraries
PKG_CONFIG_LIBS =

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
DEP_DIR = $(OBJ_DIR)

# Check for compiler availability if CC is not explicitly set
ifeq ($(origin CC),default)
    CLANG_AVAILABLE := $(shell which clang >/dev/null 2>&1 && echo yes || echo no)
    ifeq ($(CLANG_AVAILABLE),yes)
        CC = clang
    else
        $(warning clang not found, falling back to gcc)
        CC = gcc
    endif
endif

# Add pkg-config support if available and if PKG_CONFIG_LIBS is not empty
ifneq ($(strip $(PKG_CONFIG_LIBS)),)
    # Check if pkg-config is available
    PKG_CONFIG ?= pkg-config
    PKG_CONFIG_AVAILABLE := $(shell which $(PKG_CONFIG) >/dev/null 2>&1 && echo yes || echo no)

    ifeq ($(PKG_CONFIG_AVAILABLE),yes)
        LDFLAGS += $(shell $(PKG_CONFIG) --libs $(PKG_CONFIG_LIBS))
        CFLAGS += $(shell $(PKG_CONFIG) --cflags $(PKG_CONFIG_LIBS))
    else
        $(warning pkg-config not found. Some libraries might not be properly configured.)
    endif
endif

# Source discovery
SRC = $(wildcard $(SRC_DIR)/*.c)
NOM = $(basename $(notdir $(SRC)))
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(NOM)))
DEP = $(addprefix $(DEP_DIR)/, $(addsuffix .d, $(NOM)))

# Enable parallel builds
MAKEFLAGS += -j$(shell nproc)

all: $(TARGET)

.NOTPARALLEL: rebuild
rebuild: clean all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $< -I$(INC_DIR) -o $@ $(CFLAGS)

# Include dependency files
-include $(DEP)

clean: clear
	rm -f $(TARGET)

clear:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d
	rm -rf $(OBJ_DIR)
	rm -f *.out *.gch

.PHONY: all clean rebuild