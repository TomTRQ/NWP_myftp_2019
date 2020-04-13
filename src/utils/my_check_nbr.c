/*
** EPITECH PROJECT, 2020
** my_check_nbr
** File description:
** myftp
*/

int my_char_isnum(char c)
{
    if (c < 48 || c > 57)
        return (0);
    return (1);
}

int my_check_nbr(char *str)
{
    int a = 0;

    if (str[a] == '-')
        a++;
    while (str[a] != '\0') {
        if (my_char_isnum(str[a]) == 0)
            return (0);
        a++;
    }
    return (1);
}