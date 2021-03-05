/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 07:13:09 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/05 19:46:50 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	tmp = NULL;
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
	free(tmp);
	pt = next_pt;
    }
    if (pt)
	    output = dupCatResize(output, pt, NULL);
    len = ft_strlen(output);
    ft_putstr(output);
    if(output)
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
	int dot;
	int zero;
	fw = 0;
	precision = 0;
	dot = 0;
	zero = 0;


	while (!isConvertor(*pt))
	{
		if (*pt == '0' && *(pt + 1) == '*' && isConvertor(*(pt + 2)))
		{
			if ((fw = va_arg(args, int)) < 0)
			{
				negative = 1;
				fw = ft_abs(fw);
			}
			else
			{
				precision = fw;
				fw = 0;
			}
			pt+=2;
			zero = 1;
		}
		if (ft_isdigit(*pt))
			fw = ft_abs(atoi_next_pt(pt, &pt));
		if(isConvertor(*pt))
			break;
		if (*pt == '.')
		{
			dot = 1;
			if (ft_isdigit(*++pt))
				precision = ft_abs(atoi_next_pt(pt, &pt));
			else if(*pt == '*')
			{
				if (((precision = va_arg(args, int)) < 0))
					precision = 1;
				pt++;
			}
			else if (isConvertor(*pt))
				break ;
			else
				return (NULL); // Chaine invalide
		}
		else if (*pt == '*')
		{
			fw = (va_arg(args, int));
			if (*++pt == '.')
			{
				dot = 1;
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
			}
			else if (isConvertor(*pt))
				break;
			else
				return (NULL);
		}
		else if(*pt == '-')
			pt++;
		else
			return (NULL); // chaine invalide
	}
	str_arg = conversion(pt,args);
	*next_pt = ++pt;
	//GESTION DES ZEROS
	if (fw < 0)
		negative = 1;
	fw = ft_abs(fw);
	if (negative)
		rt = catnegative(fw, precision, str_arg, dot);
	else
		rt = catpositive(fw, precision, str_arg, dot, zero);
	free(str_arg);
	return (rt);	
}
