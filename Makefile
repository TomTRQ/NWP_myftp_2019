##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## NanoTekSpice
##

SRCFOLDER = ./src/

SRC =

SRCMAIN =	$(SRCFOLDER)main.c

CXX = gcc
CFLAGS = -W -Wextra -I./include

BINARYNAME = myftp

TESTNAME = unit_tests

OBJ = $(SRC:.c=.o)

OBJMAIN = $(SRCMAIN:.c=.o)

all: $(BINARYNAME)

$(BINARYNAME): $(OBJ) $(OBJMAIN)
	$(CXX) -o $(BINARYNAME) $(OBJMAIN) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJMAIN)
	$(RM) *.gcno
	$(RM) *.gcda
	$(RM) *.o

fclean: clean
	$(RM) $(BINARYNAME)
	$(RM) $(TESTNAME)

re: fclean all

tests_run: fclean
	@gcc $(SRC) -c --coverage $(CFLAGS)
	@gcc tests/*.c -c $(CFLAGS)
	@gcc -o $(TESTNAME) *.o --coverage -lcriterion
	@./$(TESTNAME)

.PHONY: all clean fclean re test

debug:	CFLAGS += -g3
debug:	fclean all