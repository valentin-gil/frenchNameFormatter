/*
** EPITECH PROJECT, 2024
** frenchNameFormatter
** File description:
** display
*/

#include "../include/my.h"

void display(char const *str)
{
    int i = 1;

    print_upper(str[0]);
    while (str[i] != ' ') {
        if (str[i] == '-') {
            my_putchar('-');
            i += 1;
            print_upper(str[i]);
        } else {
            print_lower(str[i]);
        }
        i += 1;
    }
    display_ln(str, i);
    my_putchar('\n');
}

void display_ln(char const *str, int i)
{
    while (str[i] != '\0') {
        if (str[i] == ' ')
            my_putchar(' ');
        print_upper(str[i]);
        i += 1;
    }
}

void print_upper(char c)
{
    if (c >= 65 && c <= 90)
        my_putchar(c);
    if (c >= 97 && c <= 122)
        my_putchar(c - 32);
}

void print_lower(char c)
{
    if (c >= 97 && c <= 122)
        my_putchar(c);
    if (c >= 65 && c <= 90)
        my_putchar(c + 32);
}
