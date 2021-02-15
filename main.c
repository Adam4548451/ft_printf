#include "ft_printf.h"
//#define TEST


int main(void)
{
    #ifdef TEST
    #include <stdio.h>
    int a = 15;
    printf("The pointer with printf: int = %lu , hex = %p\n", &a, &a);
    #endif

    //ft_printf("Hello %%\n", "my friend!");
    //ft_printf("Hello %d %d %d\n", 15 ,16,17);
    ft_printf("%x", 4859);

    return (0);
}