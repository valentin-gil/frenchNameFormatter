/*
** EPITECH PROJECT, 2023
** my
** File description:
** yes very useful
*/

#include <unistd.h>

#ifndef MY_H_
    #define MY_H_

int my_strlen(char const *str);
int my_putchar(char c);
int my_putstr(char const *str);
int format_check(char const *str);
int fn_check(char const *str);
int ln_check(char const *str, int i);
int is_alpha(char c);
void display(char const *str);
void display_ln(char const *str, int i);
void print_upper(char c);
void print_lower(char c);

#endif
