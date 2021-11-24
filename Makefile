#
# [Application Name]
# 
# Author  : name <email>
# Readme  : README.md
# Website : http://website.com
# TODO    : A todo note example
# Fix     : A fix note example
#

CC := g++
SRCDIR := src
BUILDDIR := build
SRCEXT := cpp
TARGET := bin/gendoku
BINDIR := bin

SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall -W -Werror
LIB := -pthread
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..." # Description
	@echo " $(CC) $^ -o $(TARGET) $(LIB)" # Command
	$(CC) $^ -o $(TARGET) $(CFLAGS) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo "$(CC) $(CFLAGS) $(INC) -c -o $@ $<";
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)";
	$(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean