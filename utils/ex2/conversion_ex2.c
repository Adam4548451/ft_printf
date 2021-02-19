/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_ex2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 07:57:37 by amaroni           #+#    #+#             */
/*   Updated: 2021/02/19 07:57:38 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char *convert_ex2(char *pt, va_list args)
{
    char *str_arg;
    unsigned long addr;
    if (*pt == 'c')
    {
        str_arg = (char*)ft_calloc(1,sizeof(*str_arg));
        str_arg[0] = (char)va_arg(args, int);
    }
    else if (*pt == 'd' || *pt == 'i')
        str_arg = ft_itoa(va_arg(args, int));
    else if (*pt == 's')
        str_arg = ft_strdup(va_arg(args, char*));
    else if (*pt == 'x' || *pt == 'X')
        str_arg = int2hexstring((unsigned long)va_arg(args, unsigned int), pt, 8);
    else if(*pt == 'p')
    {
        addr = (unsigned long)va_arg(args, void *);
        str_arg = ft_strjoin("0x",int2hexstring(addr, pt, 20));
    }
    else if (*pt == 'u')
        str_arg = ft_uitoa(va_arg(args, unsigned int));
    else 
        /* Error */ ;
    return (str_arg);
}