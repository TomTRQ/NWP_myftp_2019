/*
** EPITECH PROJECT, 2020
** list.c
** File description:
** myftp
*/

#include "myftp.h"
#include <dirent.h>
#include <errno.h>

void print_files_in_folder(char *folder, client_t *client)
{
    DIR *directory;
    struct dirent *dir;
    directory = opendir(folder);

    if (directory) {
        dir = readdir(directory);
        while (dir != NULL) {
            printf("%s\n", dir->d_name);
            dir = readdir(directory);
        }
        closedir(directory);
    }
    else
        return (send_message("550 The directory can't be \
        found\r\n", client->socket));
}

void list(char *path, client_t *client, server_t server)
{
    if (!client->is_connected)
        return (send_message("532 Need account for storing \
        files\r\n", client->socket));
    if (path)
        return (print_files_in_folder(path, client));
    if (!path)
        return (print_files_in_folder(".", client));
    send_message(command_array[13].message, client->socket);
}