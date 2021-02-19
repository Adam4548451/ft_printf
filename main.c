#include "ft_printf.h"
#include <stdio.h>
#define TEST


int main(void)
{
    #ifdef TEST
    printf("%-.5d\n",5);
    printf("%+.5d\n",5);
    printf("%+2.1d\n",5655);
    #endif

    //ft_printf("Hello %%\n", "my friend!");
    //ft_printf("Hello %d %d %d\n", 15 ,16,17);
    //ft_printf("%x", 4859);
    //ft_printf("%u",45468465);

    return (0);
}
