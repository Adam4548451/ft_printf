#include "ft_printf.h"

int ft_printf(const char *string, ...)
{
    char *pt;
    char *output;
    char *tmp;
	int len;
    int negative;
    va_list args;
    va_start(args, string);
	char *next_pt;

    negative = 0;
    pt = (char *)string;
	next_pt = NULL;
	output = NULL;
    while (ft_strchr(pt, (int)'%'))
    {
        output = dupCatResize(output, pt, ft_strchr(pt, (int)'%'));
        pt = ft_strchr(pt, (int)'%');
        if (*(++pt) != '%')
        {
            if (*pt == '-')
            {
                negative = 1;
                pt++;
            }
			tmp = handle(pt, negative, args, &next_pt);
            output = dupCatResize(output, tmp, NULL);
        }
		pt = next_pt;
    }
	if (pt)
        output = dupCatResize(output, pt, NULL);
	len = ft_strlen(output);
	ft_putstr(output);
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

char *handle(char *pt, int negative, va_list args, char **next_pt)
{
	int fw;
	int precision;
	char *rt;
	char *str_arg;

	while (!isConvertor(*pt))
	{
		fw = 0;
		precision = 0;
		if (ft_isdigit(*pt))
			fw = ft_abs(atoi_next_pt(pt, &pt));
		if (*pt == '.')
		{
			if (ft_isdigit(*++pt))
				precision = ft_abs(atoi_next_pt(pt, &pt));
			else if(*pt == '*')
			{
				precision = ft_abs(va_arg(args, int));
				pt++;
			}
			else if (isConvertor(*pt))
				break ;
			else
				return (NULL); // Chaine invalide
		}
		else if (*pt == '*')
		{
			fw = ft_abs(atoi_next_pt(pt, &pt));
			if (*pt == '.')
				if (ft_isdigit(*++pt))
					precision = ft_abs(atoi_next_pt(pt, &pt));
				else if (*pt == '*')
				{
					precision = ft_abs(va_arg(args, int));
					pt++;
				}
				else if (isConvertor(*pt))
					break ;

				else 
					return (NULL);
			else if (isConvertor(*pt))
				break;
			else
				return (NULL);
		}
		else
			return (NULL); // chaine invalide
	}
	str_arg = conversion(pt,args);
	*next_pt = ++pt;
	if ((precision = precision - ft_strlen(str_arg)) < 0)
		precision = 0;
	if ((fw = fw - ft_strlen(str_arg)) < 0)
		fw = 0;
	rt = (char*)ft_calloc(fw + precision + ft_strlen(str_arg) + 1, sizeof(*rt));
	if (negative)
		catnegative(fw, precision, rt, str_arg);
	else
		catpositive(fw, precision, rt, str_arg);
	return (rt);	
}
