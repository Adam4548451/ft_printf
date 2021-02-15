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
    int x;
    char *pt;
    char *output;
    char *str_arg;

    pt = (char*)string;
    output = NULL;
    va_list args;
    va_start(args, string);
    i = count_character((char*)string, '%');
    x = 0;
    while (x < i)
    {
        output = dupCatResize(output, pt, ft_strchr(pt, (int)'%'));
        pt = ft_strchr(pt, (int)'%');
        pt++;
        if (isExigence1(*pt))
            if (*pt == '%')
            {
                x++;
                break ;
            }
            else if (ft_isspace((int)pt[1]) || !pt[1])
            {
                str_arg = convert(pt, args);
                output = dupCatResize(output, str_arg, NULL);
                free(str_arg);
            }
            else
                break; /* EROOR */
       else if (isExigence2(*pt))
           /* DO SOMETHING */;
       else
           break; /* EROOR */
        x++;
    }
    va_end(args);
    ft_putstr(output);
    return (0);
}