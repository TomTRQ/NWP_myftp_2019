/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** remove_client
*/

#include "myftp.h"

client_t *remove_client(client_t *client)
{
    free(client->username);
    free(client->directory);
    free(client);
    return (NULL);
}