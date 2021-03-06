/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:20:25 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/09 09:00:34 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int is_digit_or_wildcard(char *pt)
{
	int i;

	i = 0;
	if (*pt == '*')
		return (1);
	while (ft_isdigit(pt[i]))
		i++;
	return (i);
}

int is_diuxX(char ch)
{
	if (ch == 'd'
			|| ch == 'i'
			|| ch == 'u'
			|| ch == 'x'
			|| ch == 'X')
		return (1);
	return (0);
}

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


char    *strchr_whitespace(char *pt)
{
	int i;

	i = 0;
	while(pt[i] && !ft_isspace(pt[i]))
		i++;
	if (pt[i])
		return (pt + i);
	else 
		return (NULL);
}






