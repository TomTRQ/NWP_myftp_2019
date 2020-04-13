/*
** EPITECH PROJECT, 2020
** get_actual_relative_directory.c
** File description:
** myftp
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *get_actual_relative_directory(char *full_path, char *root)
{
    char *relative_directory = malloc(strlen(full_path));

    relative_directory = strstr(full_path, root);
    return (relative_directory);
}