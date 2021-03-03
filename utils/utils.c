/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:20:25 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/03 10:52:09 by amaroni          ###   ########.fr       */
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

char  *catpositive(int fw, int precision, char *src, int dot)
{
	char *dst;

	if (!ft_strncmp(src, "0", ft_strlen(src)) && dot)
	{
		dst = (char*)ft_calloc(fw + precision + ft_strlen(src) + 1, sizeof(*dst));
		if (!fw && !precision)
			dst[0] = '\0';
		else if (!precision)
			while (fw-- > 0)
				ft_strlcat(dst, " ", ft_strlen(dst) + 2);
		else if (!fw)
			while (precision-- > 0)
				ft_strlcat(dst, "0", ft_strlen(dst) + 2);
	}
	else 
	{
		if ((precision = precision - ft_strlen(src)) < 0)
			precision = 0;
		if ((fw = fw - (precision + ft_strlen(src))) < 0)
			fw = 0;
		dst = (char*)ft_calloc(fw + precision + ft_strlen(src) + 1, sizeof(*dst));
		while (fw-- > 0)
			ft_strlcat(dst, " ", ft_strlen(dst) + 2);
		while (precision-- > 0)
			ft_strlcat(dst, "0", ft_strlen(dst) + 2);
		ft_strlcat(dst, src, ft_strlen(src) + ft_strlen(dst) + 1);
	}
	return dst;
}

char *catnegative(int fw, int precision, char *src, int dot)
{
	char *dst;

	if (!ft_strncmp(src, "0", ft_strlen(src)) && dot)
	{
		dst = (char*)ft_calloc(fw + precision + ft_strlen(src) + 1, sizeof(*dst));
		if (!fw && !precision)
			dst[0] = '\0';
		else if (!precision)
			while (fw-- > 0)
				ft_strlcat(dst, " ", ft_strlen(dst) + 2);
	}
	else
	{
		if ((precision = precision - ft_strlen(src)) < 0)
			precision = 0;
		if ((fw = fw - (precision + ft_strlen(src))) < 0)
			fw = 0;
		dst = (char*)ft_calloc(fw + precision + ft_strlen(src) + 1, sizeof(*dst));
		while (precision-- > 0)
			ft_strlcat(dst, "0", ft_strlen(dst) + 2);
		ft_strlcat(dst, src, ft_strlen(src) + ft_strlen(dst) + 2);
		while (fw-- > 0)
			ft_strlcat(dst, " ", ft_strlen(dst) + 2);
	}
		return (dst);
}





