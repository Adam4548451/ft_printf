/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exigences.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:36:34 by amaroni           #+#    #+#             */
/*   Updated: 2021/02/17 09:36:38 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int isExigence1(char ch)
{
    if (ch == 'c'
    || ch == 's'
    || ch == 'p'
    || ch == 'd'
    || ch == 'i'
    || ch == 'u'
    || ch == 'x'
    || ch == 'X'
    || ch == '%')
        return (1);
    return (0);
}

int isExigence2(char ch)
{
    if (ch == '+'
    || ch == '-'
    || ch == '*'
    || ft_isdigit((int)ch)
    || ch == '.')
        return (1);
    return (0);
}
