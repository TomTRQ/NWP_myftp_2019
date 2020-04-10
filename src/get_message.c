/*
** EPITECH PROJECT, 2020
** get_message.c
** File description:
** myftp
*/

#include "myftp.h"

char *get_message(int from)
{
    char *message = calloc(MAX_BUFFER, MAX_BUFFER);

    if (message == NULL)
        return (NULL);
    read(from, message, MAX_BUFFER);
    return (message);
}