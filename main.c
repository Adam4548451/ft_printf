#include "ft_printf.h"
#include <stdio.h>
#define TEST

int main(void)
{
    #ifdef TEST
    ft_printf("%-6.d\n",1);
    printf("%-6.d\n",1);
    ft_printf("%6.d\n",1);
    printf("%6.d\n",1);
    #endif
/*
    ft_printf("Hello %%\n", "my friend!");
    ft_printf("Hello %d %d %d\n", 15 ,16,17);
    printf("Hello %d %d %d\n", 15 ,16,17);
    ft_printf("%x\n", 4859);
    printf("%x\n", 4859);
    ft_printf("%u\n",45468465);
    printf("%u\n",45468465);
    ft_printf("%.6d test %.6d test\n", 15, 15);
    printf("%.6d test %.6d test\n", 15, 15);
    ft_printf("%6.d\n",15);
    printf("%6.d\n",15);
ft_printf("%6.d %6.d\n",15,15);
printf("%6.d %6.d\n",15,15);
ft_printf("%*.*d\n",9,6,486);
printf("%*.*d\n",9,6,486);
ft_printf("%-*.*d\n", 9,6,486);
printf("%-*.*d\n", 9,6,486);
*/
    return (0);
}
