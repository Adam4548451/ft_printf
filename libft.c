/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 08:37:06 by amaroni           #+#    #+#             */
/*   Updated: 2021/02/12 08:37:10 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strchr(char *s, int c)
{
        int i;

        i = 0;
        while ((*(s + i) != (char)c) && (*(s + i) != '\0'))
                i++;
        if (*(s + i) == (char)c)
                return (s + i);
        else
                return (NULL);
}

int	ft_isdigit(int c)
{
	if (((c >= '0') && (c <= '9')))
		return (2048);
	return (0);
}

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' ||
	c == '\f' || c == '\r' || c == ' ');
}

size_t	ft_strlen(const char *s)
{
	unsigned long rt;

	rt = 0;
	while (*(s + rt) != '\0')
		rt++;
	return (rt);
}

size_t		ft_strlcat(char *dst, char *src, size_t size)
{
	size_t i;
	size_t y;
	size_t rt;

	i = 0;
	y = ft_strlen(dst);
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	rt = ft_strlen(dst) + ft_strlen(src);
	while (src[i] && y < (size - 1))
	{
		dst[y] = src[i];
		y++;
		i++;
	}
	*(dst + y) = '\0';
	return (rt);
}

char	*ft_strdup(char *s)
{
	char		*rt_pointer;
	size_t		i;

	if ((rt_pointer = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))) == NULL)
	{
		free(rt_pointer);
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		rt_pointer[i] = s[i];
		i++;
	}
	rt_pointer[i] = '\0';
	return (rt_pointer);
}
