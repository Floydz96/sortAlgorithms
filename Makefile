# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Source and object directories
SRCDIR = src
OBJDIR = build

# List of source files
SOURCES = $(wildcard $(SRCDIR)/*.c)

# Generate a list of object files from source files
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

# Binary name
TARGET = $(OBJDIR)/sortAlgorithms

# Build rule
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
	rm -f $(OBJECTS)

# Compile each source file into an object file
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Create the build directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean rule
clean:
	rm -rf $(OBJDIR)

.PHONY: clean