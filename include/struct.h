/*
** EPITECH PROJECT, 2020
** struct.h
** File description:
** myftp
*/

#ifndef STRUCT_
#define STRUCT_

#include "prototypes.h"

typedef struct command_s
{
	char *name;
	char *message;
	void (*func)(char *, client_t *);
	int reply_code;
} command_t;

static command_t command_array[] = {
	{"USER", "331 User name okay, need password.\r\n", &user, 331},
	{"PASS", "332 Need account for login.\r\n", &pass, 332},
	{"CWD", "250 Requested file action okay, completed.\r\n", &cwd, 250},
	{"CDUP", "200 Command okay.\r\n", &cdup, 200},
	{"QUIT", "221 Service closing control connection.\nLogged out if appropriate.\r\n", &quit, 221},
	{"DELE", "250 Requested file action okay, completed.\r\n", &dele, 250},
	{"PWD", "257 \"PATHNAME\" created.\r\n", &pwd, 257},
	{"PASV", "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).\r\n", &pasv, 227},
	{"PORT", "200 Command okay.\r\n", &port, 200},
	{"HELP", "214 Help message.\nOn how to use the server or the meaning of a particular \
	non-standard command. This reply is useful only to the human user.\r\n", &help, 214},
	{"NOOP", "200 Command okay.\r\n", &noop, 200},
	{"RETR", "150 File status okay; about to open data connection.\r\n", &retr, 150},
	{"STOR", "150 File status okay; about to open data connection.\r\n", &stor, 150},
	{"LIST", "150 File status okay; about to open data connection.\r\n", &list, 150}
};

#endif /* !STRUCT_ */
