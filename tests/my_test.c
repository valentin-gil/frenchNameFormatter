/*
** EPITECH PROJECT, 2023
** solo_stumper3
** File description:
** my_test.c
*/

#include "../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(display, simple_name)
{
    cr_redirect_stdout();
    display("vALeNtIN gIl");
    cr_assert_stdout_eq_str("Valentin GIL\n");
}

Test(display, complex_name)
{
    cr_redirect_stdout();
    display("JeAN-MICHEL don diEgo De la vega");
    cr_assert_stdout_eq_str("Jean-Michel DON DIEGO DE LA VEGA\n");
}
