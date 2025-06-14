#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

OUT_FILE = c1m2.out
MAP_FILE = c1m2.map

# Platform should be defined when calling 'make'
PLATFORM = HOST

# ARM specific details
LINKER_FILE = msp432p401r.lds
CPU         = cortex-m4
ARCH        = armv7e-m
SPECS       = nosys.specs

# Common compiler flags
CFLAGS = -Wall -Werror -g -O0 -std=c99 
CPPFLAGS := -D$(PLATFORM)

# Separate object list for 'clean' command
# so that the clean list does not depend on the defined platform
ALL_OBJS := $(TARGET_SRC:.c=.o) $(COMMON_SRC:.c=.o)

# == Conditional defines ==
ifeq ($(PLATFORM), HOST)
	# HOST
	CC        = gcc
	SOURCES  := $(COMMON_SRC)
	OBJS     := $(COMMON_SRC:.c=.o)
	INCLUDES := $(COMMON_INC)
else
	# ARM
	CC          = arm-none-eabi-gcc
	LDFLAGS    := -T ../$(LINKER_FILE)
	ARCH_FLAGS := -mcpu=$(CPU) -march=$(ARCH) -specs=$(SPECS) -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
	SOURCES    := $(TARGET_SRC) $(COMMON_SRC)
	OBJS       := $(TARGET_SRC:.c=.o) $(COMMON_SRC:.c=.o)
	INCLUDES   := $(TARGET_INC) $(COMMON_INC)
endif

# Targets

.PHONY: build
build: $(OBJS)
	$(CC) $(ARCH_FLAGS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(INCLUDES) -o $(OUT_FILE) $(SOURCES) -Wl,-Map=$(MAP_FILE)
	size -A $(OBJS)


.PHONY: compile-all
compile-all: $(OBJS)


.PHONY: clean
clean: 
	rm -f $(ALL_OBJS) $(ALL_OBJS:.o=.d) $(ALL_OBJS:.o=.i) $(ALL_OBJS:.o=.asm) $(OUT_FILE) $(MAP_FILE)

%.i: %.c
	$(CC) -E $< -o $@

%.asm: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -S $< -o $@

# === Dependency generation options used ===
# MMD - Generate dependencies for user headers (skip system headers).
# MP - Add phony rules for each header, so make doesn’t fail if headers are deleted.
# MF - Used to specify the output (.d) file.
# MT - Used to specify the target for the rule (the object file).
%.o: %.c
	$(CC) $(ARCH_FLAGS) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -c $< -o $@ -MMD -MP -MF $(@:.o=.d) -MT $@
