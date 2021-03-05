#include "ft_printf.h"
#include <stdio.h>
#define TEST

int main(void)
{
#ifdef TEST
ft_printf("%0*d\n", 3, -12);
#endif
    /*
	printf("|%2.d|\n",0);
	printf("|%1.0d|\n",0);
	printf("|%0.0d|\n",0);
	printf("|%.0d|\n",0);
	printf("\n");
	printf("%0d\n", 0);
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
