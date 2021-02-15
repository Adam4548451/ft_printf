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

    pt = (char *)string;
    output = NULL;
    va_list args;
    va_start(args, string);
    i = count_character((char*)string, '%');
    while (i-- > 0)
    {
        output = dupCatResize(output, pt, ft_strchr(pt, (int)'%'));
        if (!(pt = ft_strchr(pt, (int)'%')))
            break;
        if (isExigence1(*(pt++)))
            if (*pt == '%')
                i--;
            else if (ft_isspace((int)pt[1]) || !pt[1])
            {
                str_arg = convert(pt, args);
                output = dupCatResize(output, str_arg, NULL);
                free(str_arg);
            }
            else
                return (-1); /*ERROR WITH THE SYMBOL THAT COMES AFTER %X[] */
        //else if (/* OTHER EXIGENCES */)
        //;
        else
            return (-1); /* NO EXIGENCE MET, OPERATOR NOT RECOGNIZED */
        pt++;
    }
    if (pt)
        output = dupCatResize(output, pt, NULL);
    va_end(args);
    ft_putstr(output);
    i = ft_strlen(output);
    free(output);
    return (i);
}