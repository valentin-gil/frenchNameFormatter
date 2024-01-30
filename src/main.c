/*
** EPITECH PROJECT, 2024
** golf_scorecard
** File description:
** main
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    char error[] = "Usage: frenchNameFormatter string\n";

    if (ac != 2) {
        write(2, &error, 34);
        return (84);
    }
    if (format_check(av[1]) == 84) {
        write(2, &error, 34);
        return (84);
    }
    display(av[1]);
    return (0);
}
