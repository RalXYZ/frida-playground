.PHONY: all clean run

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -fPIC -Wall

# Library flags
LDFLAGS = -shared

# Target names
LIB_TARGET = libmylib.so
MAIN_TARGET = frida-hook-target

# Source files
LIB_SRC = mylib.c
MAIN_SRC = main.c

# Object files
LIB_OBJ = $(LIB_SRC:.c=.o)
MAIN_OBJ = $(MAIN_SRC:.c=.o)

# Default target
all: $(LIB_TARGET) $(MAIN_TARGET)

# Build the shared library
$(LIB_TARGET): $(LIB_OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

# Build the main program
$(MAIN_TARGET): $(MAIN_OBJ) $(LIB_TARGET)
	$(CC) -o $@ $(MAIN_OBJ) -L. -lmylib

# Compile the library source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build files
clean:
	rm -f $(LIB_OBJ) $(MAIN_OBJ) $(LIB_TARGET) $(MAIN_TARGET)

# Run the main program
run: $(MAIN_TARGET)
	LD_LIBRARY_PATH=. ./$(MAIN_TARGET)
