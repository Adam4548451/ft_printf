/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:40:36 by amaroni           #+#    #+#             */
/*   Updated: 2021/02/10 14:40:38 by amaroni          ###   ########.fr       */
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
            if (handle_ex2cases(pt) == 5)
            {
                pt++;
                str_arg = convert_ex1(pt, args);
                output = dupCatResize(output, str_arg, NULL);
                free(str_arg);
            }
            else if (handle_ex2cases(pt) == 4)
            {
                x = 0;
                if (ft_isdigit(pt[1]))
                {
                    tmp = ft_itoa(va_arg(args, int));
                    x= ft_atoi(pt + 1) - ft_strlen(tmp);
                    if (x< 0)
                        x= 0;
                    str_arg = (char *)ft_calloc(x+ ft_strlen(tmp) + 1, sizeof(char));
                    while (x-- > 0)
                        ft_strlcat(str_arg, "0", ft_strlen(str_arg) + 2);
                    ft_strlcat(str_arg, tmp, ft_strlen(tmp) + ft_strlen(str_arg) + 2);
                }
                else
                {
                    x= va_arg(args, int);
                    tmp = ft_itoa(va_arg(args, int));
                    x= x- ft_strlen(tmp);
                    if (x< 0)
                        x= 0;
                    str_arg = (char *)ft_calloc(x+ ft_strlen(tmp) + 1, sizeof(char));
                    while (x-- > 0)
                        ft_strlcat(str_arg, "0", ft_strlen(str_arg) + 2);
                    ft_strlcat(str_arg, tmp, ft_strlen(tmp) + ft_strlen(str_arg) + 2);
                }
                output = dupCatResize(output, str_arg, NULL);
                free(str_arg);
            }
            else
                return (-1); /* NO EXIGENCE MET, OPERATOR NOT RECOGNIZED */
        }
        pt = strchr_whitespace(pt);
    }
    if (pt)
        output = dupCatResize(output, pt, NULL);
    va_end(args);
    ft_putstr(output);
    i = ft_strlen(output);
    free(output);
    return (i);
}