/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:20:25 by amaroni           #+#    #+#             */
/*   Updated: 2021/02/10 15:20:29 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int count_character(char *string, char character)
{
   char *pt;
   int i;

   pt = string;
   i = 0;
   while ((pt = ft_strchr(pt, (int)character)))
   {
      i++; 
      pt++;
   }
   return (i);
}


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

char    *dupCatResize(char *old, char *start, char *end)
{
    char *rt;
    char *tmp;

    tmp = old;
    if (!start)
        return (old);
    else if (!end)
        rt = ft_strjoin(old, start);
    else if (!old)
    {
        rt = (char *)ft_calloc((end - start) + 2, sizeof(*rt));
        ft_strlcat(rt, start, end - start + 1);
    }
    else
    {
        rt = (char *)ft_calloc((end - start) + ft_strlen(old) + 2, sizeof(*rt));
        ft_strlcpy(rt, old, ft_strlen(old) + 1);
        ft_strlcat(rt, start, end - start + 1 + ft_strlen(rt));
    }
    if (tmp)
        free(tmp);
    return (rt);
}
