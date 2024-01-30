/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Day04 Task02
*/

#include "../include/my.h"

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
    return (my_strlen(str));
}
