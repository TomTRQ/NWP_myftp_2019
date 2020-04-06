/*
** EPITECH PROJECT, 2020
** prototypes.c
** File description:
** myftp
*/

#ifndef PROTOTYPES_
#define PROTOTYPES_

#include "struct.h"
#include <stdbool.h>

typedef struct client_s
{
	int socket;
	char *directory;
	char *username;
	bool passwd;
	bool is_connected;
} client_t;

char **my_str_to_word_array(char const *str);
void send_message(char *message, int dest);


void cdup(char *, client_t *);
void cwd(char *, client_t *);
void dele(char *, client_t *);
void help(char *, client_t *);
void list(char *, client_t *);
void noop(char *, client_t *);
void pass(char *, client_t *);
void pasv(char *, client_t *);
void port(char *, client_t *);
void pwd(char *, client_t *);
void quit(char *, client_t *);
void retr(char *, client_t *);
void stor(char *, client_t *);
void user(char *, client_t *);

#endif /* !PROTOTYPES_ */
