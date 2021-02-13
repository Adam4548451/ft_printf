/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 10:21:59 by amaroni           #+#    #+#             */
/*   Updated: 2021/02/13 10:22:01 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
This function converts va_arg into a string.
To do this, it must switch to the next va_arg.
Switching require that you know the type the argument used, the only way we have to get this info is by beliving user with the type of oeprator conversion it used.
Thus this function must accept two entries: the operator as a char and the list or arguments as a va_list.
It will be necessary to free the memory allocated for str_arg after concatenation (certainly in the caller)
*/
char *convert(char *pt, va_list args)
{
    char *str_arg;
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
        /* Convert int to hex */;
    else if (*pt == '%')
        str_arg = ft_strdup("");
    //OTHER CASES
    return (str_arg);
}


