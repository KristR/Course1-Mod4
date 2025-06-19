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
# Makefile for Course 1 Module 4 Peer-Assessed Assignment.
# This builds the main application and runs predefined tests from course1.c
# Author: Kristaps R
#
# Use: make build <BUILD TARGET (optional)> <OVERRIDE (optional)>
#
# Build Targets:
#      PLATFORM=HOST
#      PLATFORM=MSP432
#
# Platform Overrides:
#      V=Y or V=N 		(toggles -DVERBOSE flag; adds debug print statements)	DISABLED by default
#      DEV=Y or DEV=N 	(toggles -DDEV flag; runs development test function)	DISABLED by default
#      C1=Y or C1=N 	(toggles -DCOURSE1 flag; runs main course function)		ENABLED by default
#
#
# Note: Requires gcc and make
# Written and tested on Ubuntu 17.04
#------------------------------------------------------------------------------
include sources.mk

OUT_FILE = c1m4.out
MAP_FILE = c1m4.map

# ===== Commandline flags =====
# PLATFORM - Indicates target platform for the build. ARM target build can be done by setting 'PLATFORM' to 'MSP432' value.
# V   - Adds debug print statements, DISABLED by default. Can enable by adding 'V=Y' to 'make build' in commandline
# DEV - Runs development test function, DISABLED by default. Can enable by adding 'DEV=Y' to 'make build' in commandline
# C1  - Runs main course function, ENABLED by default. Can disable by adding 'C1=N' to 'make build' in commandline
PLATFORM = HOST
V   = N
DEV = N
C1  = Y

# ===== ARM specific details =====
LINKER_FILE = msp432p401r.lds
CPU         = cortex-m4
ARCH        = armv7e-m
SPECS       = nosys.specs

# ===== Common compiler flags =====
CFLAGS = -Wall -Werror -g -O0 -std=c99 
CPPFLAGS = -D$(PLATFORM)
ifeq ($(V), Y)
	CPPFLAGS += -DVERBOSE
endif
ifeq ($(DEV), Y)
	CPPFLAGS += -DDEV
endif
ifeq ($(C1), Y)
	CPPFLAGS += -DCOURSE1
endif

# Separate object list for 'clean' command
# so that the clean list does not depend on the defined platform
ALL_OBJS := $(TARGET_SRC:.c=.o) $(COMMON_SRC:.c=.o)

# ===== Conditional defines =====
ifeq ($(PLATFORM), HOST)
	# HOST
	CC        = gcc
	SOURCES  := $(COMMON_SRC)
	OBJS     := $(COMMON_SRC:.c=.o)
	INCLUDES := $(COMMON_INC)
else
	# ARM
	CC          = arm-none-eabi-gcc
	LDFLAGS    := -T ./$(LINKER_FILE)
	ARCH_FLAGS := -mcpu=$(CPU) -march=$(ARCH) -specs=$(SPECS) -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
	SOURCES    := $(TARGET_SRC) $(COMMON_SRC)
	OBJS       := $(TARGET_SRC:.c=.o) $(COMMON_SRC:.c=.o)
	INCLUDES   := $(TARGET_INC) $(COMMON_INC)
endif

# ===== Targets =====

# Builds main application
.PHONY: build
build: $(OBJS)
	$(CC) $(ARCH_FLAGS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(INCLUDES) -o $(OUT_FILE) $(SOURCES) -Wl,-Map=$(MAP_FILE)
	size -A $(OBJS)

# Compiles all .c files but does not link
.PHONY: compile-all
compile-all: $(OBJS)

# Removes all generated files
.PHONY: clean
clean: 
	rm -f $(ALL_OBJS) $(ALL_OBJS:.o=.d) $(ALL_OBJS:.o=.i) $(ALL_OBJS:.o=.asm) $(OUT_FILE) $(MAP_FILE)

# Preprocesses given .c file
%.i: %.c
	$(CC) -E ./src/$< -o $@

# Compiles given .c file into assembly
%.asm: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -S $< -o $@

# Compiles given .c file
# = Dependency generation options used =
# MMD - Generate dependencies for user headers (skip system headers).
# MP - Add phony rules for each header, so make doesn’t fail if headers are deleted.
# MF - Used to specify the output (.d) file.
# MT - Used to specify the target for the rule (the object file).
%.o: %.c
	$(CC) $(ARCH_FLAGS) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -c $< -o $@ -MMD -MP -MF $(@:.o=.d) -MT $@
