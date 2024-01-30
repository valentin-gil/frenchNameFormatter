/*
** EPITECH PROJECT, 2024
** frenchNameFormatter
** File description:
** format_check
*/

#include "../include/my.h"

int format_check(char const *str)
{
    int res = 0;

    if (is_alpha(str[0]) == 0)
        return (84);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            res += 1;
    }
    if (res == 0)
        return (84);
    if (fn_check(str) == 84)
        return (84);
    return (0);
}

int fn_check(char const *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != ' ') {
        if (is_alpha(str[i]) == 0 && str[i] != '-') {
            return (84);
        }
        if (str[i] == '-')
            count += 1;
        i += 1;
    }
    if (count > 1)
        return (84);
    if (ln_check(str, i + 1) == 84)
        return (84);
    return (0);
}

int ln_check(char const *str, int i)
{
    while (str[i] != '\0') {
        if (is_alpha(str[i]) == 0 && str[i] != ' ') {
            return (84);
        }
        i += 1;
    }
    return (0);
}

int is_alpha(char c)
{
    if (c >= 65 && c <= 90 ||
        c >= 97 && c <= 122) {
        return (1);
    }
    return (0);
}
