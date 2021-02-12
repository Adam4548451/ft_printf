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

    i = count_character(string, '%');
    x = 0;

    pt = string;
    while (x < i)
    {
        pt = ft_strchr(pt, (int)'%');
        pt++;
        if (isExigence1(*pt))
        else if (isExigence2(*pt))
        else
            break;
        x++;
    }
}