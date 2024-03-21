default_target: PLS
.PHONY : default_target

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# The shell in which to execute make rules.
SHELL = /bin/sh

# The command to remove a file.
RM = rm -f

# Escaping for special characters.
EQUALS = =

CFLAGS = -I.
DEBUGFLAG = -g
CC = gcc

VPATH = ../src

OBJ =  main.o
OBJ += tools.o
OBJ += input.o
OBJ += output.o
OBJ += runpls.o

OBJ_DIR = objects

PLS: $(OBJ:%=$(OBJ_DIR)/%)
	$(CC) -o PLS $(CFLAGS) $^

debug:
	$(CC) -o PLS $(CFLAGS) $(DEBUGFLAG) $(OBJ)
.PHONY : debug

$(OBJ_DIR)/%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/$(OBJ): tools.h
$(OBJ_DIR)/main.o: input.h output.h runpls.h

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... PLS (the default if no target is provided)"
	@echo "... debug"
	@echo "... clean"
.PHONY : help

# The main clean target
clean:
	$(RM) PLS $(OBJ_DIR)/*
.PHONY : clean
