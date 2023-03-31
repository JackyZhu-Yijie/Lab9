# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRCDIR = src
BUILDDIR = build
DOCDIR = documentation
DOCSUBDIR = docs
SCRIPTSDIR = scripts

# Source files
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))

# Rules
.PHONY: all clean docs

all: $(BUILDDIR)/main

$(BUILDDIR)/main: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR):
	mkdir -p $@

clean:
	rm -rf $(BUILDDIR)

docs: $(DOCDIR)/Doxyfile | $(DOCDIR)
	doxygen $<

$(DOCDIR)/Doxyfile: | $(DOCDIR)
	doxygen -g $@

$(DOCDIR):
	mkdir -p $@

$(DOCDIR)/$(DOCSUBDIR): | $(DOCDIR)
	mkdir -p $@

$(BUILDDIR)/main: | $(DOCDIR)/$(DOCSUBDIR)

# Variables for testing purposes
test:
	echo $(SRCS)
	echo $(OBJS)