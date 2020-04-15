/*
** EPITECH PROJECT, 2020
** struct.h
** File description:
** myftp
*/

#ifndef STRUCT_
#define STRUCT_

#include <stdbool.h>

typedef struct client_s
{
    int socket;
    int data_socket;
    int data_port;
    char *directory;
    char *username;
    char *previous_command;
    int port;
    int root_remoteness;
    bool passwd;
    bool is_connected;
    bool is_set;
    bool is_passive;
} client_t;

typedef struct server_s
{
    int port;
    char *directory;
} server_t;

typedef struct command_s
{
    char *name;
    char *message;
    void (*func)(char *, client_t *, server_t);
    int reply_code;
} command_t;

#endif /* !STRUCT_ */
