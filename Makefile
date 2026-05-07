CC = gcc
CFLAGS = -Wall -Wextra -I./include
SRCDIR = src
OBJDIR = obj
BINDIR = bin
TARGET = $(BINDIR)/program

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/=$(OBJDIR)/)

$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) -o $@ $(OBJECTS)

$(OBJDIR)/: $(SRCDIR)/ | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf $(OBJDIR)/*.o $(BINDIR)/*

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
