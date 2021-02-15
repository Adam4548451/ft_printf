#include "ft_printf.h"
//#define TEST


int main(void)
{
    #ifdef TEST
    #include <stdio.h>
    int a = 42;
    printf("%x", a);
    #endif

    //ft_printf("Hello %%", "my friend!");
    //ft_printf("Hello %d\n", 16);
    ft_printf("42 en hex donne : %X", 142);
    return (0);
}