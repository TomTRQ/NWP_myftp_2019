/*
** EPITECH PROJECT, 2020
** cwd.c
** File description:
** myftp
*/

#include "myftp.h"
#include <dirent.h>
#include <errno.h>

void cwd(char *pathname, client_t *client, server_t server)
{
    if (!pathname)
        return send_message("xxx CWD command needs a directory path as parameter\r\n", client->socket);
    if (chdir(pathname) != 0)
        return send_message("xxx The directory can't be found\r\n", client->socket);
    send_message(command_array[2].message, client->socket);
    getcwd(client->directory, 4096);
    client->root_remoteness += 1;
}