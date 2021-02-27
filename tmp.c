#include "ft_printf.h"

int ft_printf(const char *string, ...)
{
    char *pt;
    char *output;
    char *tmp;
	int len;
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
            output = dupCatResize(output, convert(pt, negative, args), NULL);
        }
		pt++;
    }
	len = ft_strlen(output);
	free(output);
	return (len);
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

unsigned int ft_abs(int i)
{
	if (i >= 0)
		return ((unsigned int)i);
	return ((unsigned int)(-i));
}

char *convert(char *pt, int negative, va_list args)
{
	while (!ft_converter(pt))
	{
		int fw;
		int precision;
		char *rt;
		char *str_arg;

		fw = 0;
		precision = 0;
		if (ft_isdigit(*pt))
			fw = abs(atoi_next_pt(pt, &pt));
		if (*pt == '.')
		{
			if (ft_isdigit(*++pt))
				precision = abs(atoi_next_pt(pt, &pt));
			else if(*pt == '*')
			{
				precision = abs(va_arg(args, int));
				pt++;
			}
			else if (ft_isconverter(pt))
				break ;
			else
				return (NULL) // Chaine invalide
		}
		else if (*pt == '*')
		{
			fw = abs(atoi_next_pt(pt, &pt));
			if (*pt == '.')
				if (ft_isdigit(*++pt))
					precision = abs(atoi_next_pt(pt, &pt));
				else if (*pt == '*')
				{
					precision = abs(va_arg(args, int));
					pt++;
				}
				else if (ft_isconvert(pt))
					break ;

				else 
					return (NULL);
			else if (ft_isconverter(pt))
				break;
			else
				return (NULL);
		}
		else
			return (NULL) // chaine invalide
	}
	str_arg = va_arg(args, char *);
	if (negative)
		catnegative(fw - ft_strlen(str_arg), preicison - ft_strlen(str_arg), str_arg, rt);
	else
		catpositive(fw - ft_strlen(str_arg), preicison - ft_strlen(str_arg), str_arg, rt);
	return (rt);	
}
