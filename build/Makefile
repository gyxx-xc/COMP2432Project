default_target: PLS
.PHONY : default_target

# The shell in which to execute make rules.
SHELL = /bin/sh

# The command to remove a file.
RM = rm -rf

# Escaping for special characters.
EQUALS = =

CFLAGS = -std=c99 -I.
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

debug: $(OBJ:%=$(OBJ_DIR)/%)
	$(CC) -o PLS $(CFLAGS) $(DEBUGFLAG) $^
.PHONY : debug

$(OBJ_DIR)/%.o : %.c $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/$(OBJ): tools.h
$(OBJ_DIR)/main.o: input.h output.h runpls.h

$(OBJ_DIR):
	mkdir $@

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... PLS (the default if no target is provided)"
	@echo "... debug"
	@echo "... clean"
.PHONY : help

# The main clean target
clean:
	$(RM) PLS $(OBJ_DIR)
.PHONY : clean
