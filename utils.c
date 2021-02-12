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

int count_character(char *string, char character)
{
   char *pt;
   int i;

   pt = string;
   i = 0;
   while (pt = ft_strch(pt, (int)character))
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