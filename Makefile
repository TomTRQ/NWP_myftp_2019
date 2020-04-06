##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## NanoTekSpice
##

SRCFOLDER = ./src/
COMFOLDER = ./src/commands/

SRC =	$(SRCFOLDER)my_str_to_word_array.c	\
		$(COMFOLDER)cdup.c					\
		$(COMFOLDER)cwd.c					\
		$(COMFOLDER)dele.c					\
		$(COMFOLDER)help.c					\
		$(COMFOLDER)list.c					\
		$(COMFOLDER)noop.c					\
		$(COMFOLDER)pass.c					\
		$(COMFOLDER)pasv.c					\
		$(COMFOLDER)port.c					\
		$(COMFOLDER)pwd.c					\
		$(COMFOLDER)quit.c					\
		$(COMFOLDER)retr.c					\
		$(COMFOLDER)stor.c					\
		$(COMFOLDER)user.c					\


SRCMAIN =	$(SRCFOLDER)main.c

CXX = gcc
CFLAGS = -W -Wextra -I./include -g3

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