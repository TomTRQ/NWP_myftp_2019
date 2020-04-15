/*
** EPITECH PROJECT, 2020
** reset_after_command.c
** File description:
** myftp
*/

#include "myftp.h"

void reset_after_command(int root_remoteness, char **array, \
char *line, client_t *client)
{
    for (int i = 0; i < root_remoteness; i++)
        chdir("../");
    if (client->previous_command)
        free(client->previous_command);
    if (array[1])
        free(array[1]);
    free(array[0]);
    free(array);
}