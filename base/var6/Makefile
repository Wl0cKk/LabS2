CC = gcc
CFLAGS = -Wall

SRCDIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
BINDIR = bin

SOURCES = $(wildcard $(SRCDIR)*.c)
EXECUTABLES = $(patsubst $(SRCDIR)%.c,$(BINDIR)/%,$(SOURCES))

.PHONY: all clean

all: $(EXECUTABLES)

$(BINDIR)/%: $(SRCDIR)%.c | $(BINDIR)
	$(CC) $(CFLAGS) $< -o $@

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf $(BINDIR)