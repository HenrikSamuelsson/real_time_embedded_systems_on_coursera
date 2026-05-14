# Compiler used to build the program.
CC = gcc

# Optional include and library directories.
# These are empty for this program because pthread and syslog are provided
# by the standard Linux system libraries.
INCLUDE_DIRS =
LIB_DIRS =

# Optional preprocessor definitions.
CDEFS =

# Compiler flags:
# -O0      Disable optimization to make debugging easier.
# -g       Include debug information.
# -Wall    Enable common warnings.
# -Wextra  Enable additional warnings.
CFLAGS = -O0 -g -Wall -Wextra $(INCLUDE_DIRS) $(CDEFS)

# Linker flags and libraries.
# -pthread is preferred over -lpthread because it sets both compile-time
# and link-time options required for POSIX threads.
LDFLAGS =
LIBS = -pthread

# Source files for this program.
CFILES = hello_thread.c
HFILES =

# Derived object files.
SRCS = $(HFILES) $(CFILES)
OBJS = $(CFILES:.c=.o)

# Default target.
all: hello_thread

# Remove generated files.
clean:
	-rm -f *.o *.d
	-rm -f hello_thread

# Link the final executable.
hello_thread: $(OBJS)
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

# Compile each .c file into a .o file.
.c.o:
	$(CC) $(CFLAGS) -c $<

# Placeholder target kept from the original example.
depend: