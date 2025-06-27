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

# Source lists
COMMON_SRC = ./src/main.c \
             ./src/memory.c \
             ./src/data.c \
             ./src/stats.c \
             ./src/course1.c

TARGET_SRC = ./src/system_msp432p401r.c \
             ./src/interrupts_msp432p401r_gcc.c \
             ./src/startup_msp432p401r_gcc.c


# Include lists
COMMON_INC = -I ./include/common/

TARGET_INC = -I ./include/CMSIS/ \
             -I ./include/msp432/ \
             -I ./
