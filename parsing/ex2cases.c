/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex2cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:49:12 by amaroni           #+#    #+#             */
/*   Updated: 2021/02/17 13:49:14 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ex2case1(char *pt)
{
    if (ft_issign(pt[0])
        && isDorW(pt[1])
        && pt[2] == '.'
        && isDorW(pt[3])
        && is_diuxX(pt[4]))
        return (1);
    return (0);
}

int ex2case2(char *pt)
{
    if (isDorW(pt[0]) 
        && pt[1] == '.'
        && isDorW(pt[2]) 
        && is_diuxX(pt[3]))
        return (1);
    return (0);
}

int ex2case3(char *pt)
{
    if (isDorW(pt[0]) 
        && pt[1] == '.' 
        && is_diuxX(pt[2]))
        return (0);
    return (1);
}

int ex2case4(char *pt)
{
    if (pt[0] == '.' && isDorW(pt[1]) && is_diuxX(pt[2]))
        return (1);
    return (0);
}

int ex2case5(char *pt)
{
    if (pt[0] == '.' && is_diuxX(pt[1]))
        return (1);
    return (0);
}


int handle_ex2cases(char *pt)
{
    if (ex2case1(pt))
        return (1);
    if (ex2case2(pt))
        return (2);
    if (ex2case3(pt))
        return (3);
    if (ex2case4(pt))
        return (4);
    if (ex2case5(pt))
        return (5);
    else
        return (0);
}