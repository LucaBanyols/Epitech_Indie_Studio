/*
** EPITECH PROJECT, 2020
** my_ftp
** File description:
** test output
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/Game/Map.hpp"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(indie_studio, test_create_error_handling1, .init = redirect_all_std)
{
    Map map;
    int i = map.getRandom();

    cr_expect_lt(i, 9);
}

Test(indie_studio, test_create_error_handling2, .init = redirect_all_std)
{
    Map map;
    int i = map.getRandom();

    cr_expect_gt(i, 0);
}