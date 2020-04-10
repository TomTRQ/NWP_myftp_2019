/*
** EPITECH PROJECT, 2020
** send_message.c
** File description:
** myftp
*/

#include <string.h>
#include <unistd.h>

void send_message(char *message, int dest)
{
    int size = strlen(message);

    write(dest, message, size);
}