/*
** EPITECH PROJECT, 2020
** list.c
** File description:
** myftp
*/

#include "myftp.h"
#include <dirent.h>
#include <errno.h>

void message_loop(FILE *fp, int csock)
{
    char file[4096];

    while (fgets(file, 4096, fp) != NULL)
        send_message(file, csock);
}

void print_files_in_folder(char *command, char *path, client_t *client)
{
    DIR *directory = opendir(path);
    FILE *fp;
    struct sockaddr_in cin;
    socklen_t len_cin = sizeof(cin);
    int csock = accept(client->data_socket, (struct sockaddr *)&cin, &len_cin);

    if (directory) {
        closedir(directory);
        send_message(command_array[13].message, client->socket);
        fp = popen(command, "r");
        message_loop(fp, csock);
        send_message("226 Closing data connection\r\n", client->socket);
        close(csock);
    } else
        send_message("550 The directory can't be found\r\n", client->socket);
}

void list(char *path, client_t *client, server_t server)
{
    char *commands = NULL;

    if (!client->is_connected)
        return (send_message("532 Need account for storing \
files\r\n", client->socket));
    if (path) {
        commands = calloc(strlen(path) + 6, strlen(path) + 6);
        if (commands == NULL)
            return (send_message("500 An error occured\r\n", client->socket));
        strcpy(commands, "ls -l ");
        strcat(commands, path);
        print_files_in_folder(commands, path, client);
    } else if (!path) {
        commands = calloc(7, 7);
        if (commands == NULL)
            return (send_message("500 An error occured\r\n", client->socket));
        strcpy(commands, "ls -l .");
        print_files_in_folder(commands, ".", client);
    }
    free(commands);
}