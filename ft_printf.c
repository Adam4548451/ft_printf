/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:40:36 by amaroni           #+#    #+#             */
/*   Updated: 2021/02/23 11:33:06 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *string, ...)
{
    int i;
    char *pt;
    char *output;
    char *str_arg;
    char *tmp;
    int x;
	int field_width;
	int precision;
	int nb_space;
	int nb_zero;
    int negative;

    tmp = NULL;
    negative = 0;
    pt = (char *)string;
    output = NULL;
    va_list args;
    va_start(args, string);
    i = count_character((char *)string, '%');
    while (i-- > 0)
    {
        output = dupCatResize(output, pt, ft_strchr(pt, (int)'%'));
        if (!(pt = ft_strchr(pt, (int)'%')))
            break;
        if (isExigence1(*(++pt)))
        {
            if (*pt == '%')
                i--;
            else if (ft_isspace((int)pt[1]) || !pt[1])
			{
                str_arg = convert_ex1(pt, args);
                output = dupCatResize(output, str_arg, NULL);
                free(str_arg);
			}
            else
                return (-1); /*ERROR WITH THE SYMBOL THAT COMES AFTER %X[] */
        }
        else if (isExigence2(*pt))
        {
            //ajouter gestion des negatifs
            if (*pt == '-')
            {
                negative = 1;
                pt++;
            }
            //-----------------------------------
			if (handle_ex2cases(pt) == 6)
			{
                tmp = ft_itoa(va_arg(args, int));
                if ((nb_space = ft_atoi(pt) - ft_strlen(tmp)) < 0)
                    nb_space = 0;
                str_arg = (char *)ft_calloc(nb_space + ft_strlen(tmp) + 1, sizeof(char));
                if (negative)
                    catnegative(nb_space,0,str_arg,tmp);
                else
                    catpositive(nb_space,0,str_arg,tmp);
			}
			else if (handle_ex2cases(pt) == 5)
                str_arg = convert_ex1(++pt, args);
            else if (handle_ex2cases(pt) == 4)
            {
                if (ft_isdigit(pt[1]))
                {
                    tmp = ft_itoa(va_arg(args, int));
                    if ((precision = ft_atoi(pt + 1) - ft_strlen(tmp)) < 0)
                        precision = 0;
                }
                else
                {
                    precision = va_arg(args, int);
                    tmp = ft_itoa(va_arg(args, int));
                    if ((precision = precision - ft_strlen(tmp)) < 0)
                        precision = 0;
                }
                    str_arg = (char *)ft_calloc(precision + ft_strlen(tmp) + 1, sizeof(char));
                    while (precision-- > 0)
                        ft_strlcat(str_arg, "0", ft_strlen(str_arg) + 2);
                    ft_strlcat(str_arg, tmp, ft_strlen(tmp) + ft_strlen(str_arg) + 2);
            }
            else if (handle_ex2cases(pt) == 3)
            {
                if (ft_isdigit(*pt))
                {
                    tmp = ft_itoa(va_arg(args, int));
                    if ((precision = ft_atoi(pt) - ft_strlen(tmp)) < 0)
                        precision = 0;
                }
                else
                {
                    precision = va_arg(args, int);
                    tmp = ft_itoa(va_arg(args, int));
                    if ((precision = precision - ft_strlen(tmp)) < 0)
                        precision = 0;
                }
                    str_arg = (char *)ft_calloc(precision + ft_strlen(tmp) + 1, sizeof(char));
                if (negative)
                    catnegative(precision,0,str_arg,tmp);
                else
                    catpositive(precision,0,str_arg,tmp);
            }
            else if (handle_ex2cases(pt) == 2)
            {

                if(ft_isdigit(pt[0]))
                    field_width = ft_atoi(pt);
                else
                    field_width = va_arg(args, int);
                if(ft_isdigit(pt[2]))
                    precision = ft_atoi(pt + 2);
                else
                    precision = va_arg(args, int);
                tmp = ft_itoa(va_arg(args, int));
                if ((nb_zero = precision - ft_strlen(tmp)) < 0)
                    nb_zero = 0;
                if ((nb_space = field_width - precision) < 0)
                    nb_space = 0;
                str_arg = (char *)ft_calloc(nb_zero + nb_space + ft_strlen(tmp) + 1, sizeof(char));
                while (nb_space-- > 0)
                    ft_strlcat(str_arg, " ", ft_strlen(str_arg) + 2);
                while (nb_zero-- > 0)
                    ft_strlcat(str_arg, "0", ft_strlen(str_arg) + 2);
                ft_strlcat(str_arg, tmp, ft_strlen(tmp) + ft_strlen(str_arg) + 2);
            }
			else 
			{
                if(ft_isdigit(pt[1]))
                    field_width = ft_atoi(pt);
                else
                    field_width = va_arg(args, int);
                if(ft_isdigit(pt[3]))
                    precision = ft_atoi(pt + 3);
                else
                    precision = va_arg(args, int);
                tmp = ft_itoa(va_arg(args, int));
                if ((nb_zero = precision - ft_strlen(tmp)) < 0)
                    nb_zero = 0;
                if ((nb_space = field_width - precision) < 0)
                    nb_space = 0;
                str_arg = (char *)ft_calloc(nb_zero + nb_space + ft_strlen(tmp) + 1, sizeof(char));
                while (nb_space-- > 0)
                    ft_strlcat(str_arg, " ", ft_strlen(str_arg) + 2);
                while (nb_zero-- > 0)
                    ft_strlcat(str_arg, "0", ft_strlen(str_arg) + 2);
                ft_strlcat(str_arg, tmp, ft_strlen(tmp) + ft_strlen(str_arg) + 2);
				
			}
            output = dupCatResize(output, str_arg, NULL);
            if (tmp)
                free(tmp);
            if (str_arg)
                free(str_arg);
        }
        else
            return (-1); /* NO EXIGENCE MET, OPERATOR NOT RECOGNIZED */
    pt = strchr_whitespace(pt);
    }
    output = dupCatResize(output, pt, NULL);
    va_end(args);
    ft_putstr(output);
    i = ft_strlen(output);
    free(output);
    return (i);
}
