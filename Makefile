##
## EPITECH PROJECT, 2024
## frenchNameFormatter
## File description:
## Makefile
##

# NAME: Name of the executable
NAME	=	frenchNameFormatter

# CC: Compiler
CC := gcc

# SRC: Source files
SRC	=	$(wildcard src/*.c)	\

# OBJ: Object files
OBJ	=	$(SRC:src/%.c=$(BUILDDIR)/%.o)

# TESTSRC: Source files for tests
TESTSRC	=	$(wildcard tests/*.c)	\

# TESTOBJ: Object files for tests
TESTOBJ	=	$(TESTSRC:tests/%.c=$(BUILDDIR)/%.o)

# BUILDDIR: Directory where object files will be stored
BUILDDIR	=	obj

# TESTDIR: Directory where tests files are stored
TESTDIR	=	tests

# CFLAGS: Flags for the compiler
CFLAGS	=	-I./include

# Rules for make all
all:	$(NAME)

# Create the build directory
$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

# Build rules
$(BUILDDIR)/%.o:	src/%.c | $(BUILDDIR)
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo -e "\e[01m\e[33m    Compiling...\
		\e[00m\e[39m$<\e[032m [OK]\e[00m"

# Rules for make
$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

# Rules for make clean
clean:
	@rm -rf $(BUILDDIR)
	@echo -e "\x1B[31;1mAll object files have been removed.\e[0m"

# Rules for make fclean
fclean:	clean
	@rm -rf $(NAME)
	@echo -e "\x1B[38;5;210m$(NAME)\e[0m\e[38;5;196m has been removed.\e[0m"
	@rm -rf unit_tests
	@echo -e "\x1B[38;5;210munit_tests\e[0m\e[38;5;196m has been removed.\e[0m"

# Build rules for tests
$(BUILDDIR)/%.o:	tests/%.c | $(BUILDDIR)
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo -e "\e[01m\e[33m    Compiling...\
		\e[00m\e[39m$<\e[032m [OK]\e[00m"

# Rules for make unit_tests
unit_tests:	CFLAGS += -lcriterion --coverage -g3
unit_tests: SRC := $(filter-out src/main.c, $(SRC))
unit_tests: clean $(OBJ) $(TESTOBJ)
	@$(CC) -o unit_tests $(TESTOBJ) $(OBJ) $(CFLAGS)

# Rules for make tests_run
tests_run: unit_tests
	@./unit_tests

# Rules for make re
re:	fclean all
	@echo -e "\x1B[38;5;42m$(NAME)\e[0m\e[32;1m has been recompiled.\e[0m"

.PHONY: all clean fclean unit_tests tests_run re
