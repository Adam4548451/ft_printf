/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex2cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:49:12 by amaroni           #+#    #+#             */
/*   Updated: 2021/02/23 11:48:14 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ex2case1(char *pt)
{
    if (ft_issign(pt[0])
        && is_digit_or_wildcard(pt + 1)
        && pt[2] == '.'
        && is_digit_or_wildcard(pt + 3)
        && is_diuxX(pt[4]))
        return (1);
    return (0);
}

int ex2case2(char *pt)
{
    int field_width;
    int precision;

    field_width = is_digit_or_wildcard(pt);
    precision = is_digit_or_wildcard(pt + 2);
    if (field_width
        && pt[1] == '.'
        && precision
        && is_diuxX(pt[3]))
        return (1);
    return (0);
}

int ex2case3(char *pt)
{ 
    int i;
    
    i = is_digit_or_wildcard(pt);
    if (i && pt[i] == '.' 
        && is_diuxX(pt[i + 1]))
        return (1);
    return (0);
}

int ex2case4(char *pt)
{
    int i;
    
    i = is_digit_or_wildcard(pt + 1);
    if (pt[0] == '.' && i && is_diuxX(pt[i + 1]))
        return (1);
    return (0);
}

int ex2case5(char *pt)
{
    if (pt[0] == '.' && is_diuxX(pt[1]))
        return (1);
    return (0);
}

int ex2case6(char *pt)
{
	int i;
	i = is_digit_or_wildcard(pt);
	if (i && is_diuxX(pt[i]))
		return (1);
	return (0);
}

int handle_ex2cases(char *pt)
{
    if (ex2case1(pt))
        return (1);
    else if (ex2case2(pt))
        return (2);
    else if (ex2case3(pt))
        return (3);
    else if (ex2case4(pt))
        return (4);
    else if (ex2case5(pt))
        return (5);
	else if (ex2case6(pt))
		return (6);
    else
        return (0);
}
