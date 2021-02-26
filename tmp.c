#include "ft_printf.h"

int ft_printf(const char *string, ...)
{
    char *pt;
    char *output;
    char *tmp;
    int negative;
    int nbspace;
    int nbzero;
    va_list args;
    va_start(args, string);

    negative = 0;
    pt = (char *)string;
    while (ft_strchr(pt, (int)'%'))
    {
        output = dupCatResize(output, pt, ft_strchr(pt, (int)'%'));
        pt = ft_strch(pt, (int)'%');
        if (*(++pt) != '%')
        {
            if (*pt == '-')
            {
                negative = 1;
                pt++;
            }
            if (is_converter(*pt))
            {
                while (!(is_cspdiuxX(*pt)))
                {
                    if (handle_ex2cases(pt) == 6)
                    {
                        nbspace = atoi_next_pt(pt, &pt);
                        if (negative)
                            catnegative(nbspace, 0, output, " ");
                        else
                            catpositive(nbspace, 0, output, " ");
                    }
                    else if (handle_ex2cases(pt) == 5)
                    {

                    }
                    else if (handle_ex2cases(pt) == 4)
                    {
                        if (ft_isdigit(pt[1]))
                            nbzero = atoi_next_pt(++pt, &pt);
                        else
                            nbzero = 
                    }
                    else if (handle_ex2cases(pt) == 3)
                    else if (handle_ex2cases(pt) == 2)
                    else
                        return (-1);
                }
            str_arg = convert_ex1(pt, args, &next_pt);
            output = dupCatResize(output, str_arg, NULL);
            free(str_arg);
            }
        }
    }
}





int atoi_next_pt(char *string, char **next_pt)
{
    char *tmp;
    int rt;

    rt = 0;
    tmp = string;
    while (ft_isdigit(*tmp))
        tmp++;
    if (tmp != string)
    {
        rt = ft_atoi(string);
        *next_pt = tmp;
    }
    return (rt);
}