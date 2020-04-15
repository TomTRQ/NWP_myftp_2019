/*
** EPITECH PROJECT, 2020
** concatenate_commands.c
** File description:
** myftp
*/

#include <prototypes.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char **concatenate_commands(char *previous_command, char *actual_command)
{
    int size = strlen(previous_command) + strlen(actual_command);
    char *new_command = calloc(size, size);
    char **command_array = NULL;

    if (new_command == NULL)
        return (NULL);
    for (int i = 0; previous_command[i] != '\0'; i++)
        if (previous_command[i] == '\r' || previous_command[i] == '\n')
            previous_command[i] = '\0';
    strcpy(new_command, previous_command);
    strcat(new_command, actual_command);
    command_array = my_str_to_word_array(new_command);
    return (command_array);
}
