/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 10:21:59 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/08 17:18:14 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char conversion_hex_table(unsigned long input, char *pt)
{
    if (input > 9 && *pt == 'x')
        return ('a' + (input - 10));
    if (input > 9 && *pt == 'X')
        return ('A' + (input - 10));
    return ('0' + input);
}

char *int2hexstring(unsigned long input, char *pt, size_t size)
{
    char *str;
    char *output;
    int i;
    int y;

    i = 0;
    str = (char*)ft_calloc(size, sizeof(*str));
    while (input % 16 > 0)
    {
        if (*pt == 'p')
            str[i] = conversion_hex_table(input % 16, "x");
        else
            str[i] = conversion_hex_table(input % 16, pt);
        input /= 16;
        i++;
    }
    i = ft_strlen(str);
    y = 0;
    output = ft_strdup(str);
    while (i-- > 0)
    {
        output[y] = str[i];
        y++;
    }
    free (str);
    return (output);
}




/*
This function conversions va_arg into a string.
To do this, it must switch to the next va_arg.
Switching require that you know the type the argument used, the only way we have to get this info is by beliving user with the type of oeprator conversion it used.
Thus this function must accept two entries: the operator as a char and the list or arguments as a va_list.
It will be necessary to free the memory allocated for str_arg after concatenation (certainly in the caller)
*/
char *conversion(char *pt, va_list args)
{
    char *str_arg;
    unsigned long addr;
    if (*pt == 'c')
    {
        str_arg = (char*)ft_calloc(2,sizeof(*str_arg));
        str_arg[0] = (char)va_arg(args, int);
    }
    else if (*pt == 'd' || *pt == 'i')
        str_arg = ft_itoa(va_arg(args, int));
    else if (*pt == 's')
        str_arg = ft_strdup(va_arg(args, char*));
    else if (*pt == 'x' || *pt == 'X')
        str_arg = int2hexstring((unsigned long)va_arg(args, unsigned int), pt, 8);
    else if(*pt == 'p')
    {
        addr = (unsigned long)va_arg(args, void *);
        str_arg = ft_strjoin("0x",int2hexstring(addr, pt, 20));
    }
    else if (*pt == 'u')
        str_arg = ft_uitoa(va_arg(args, unsigned int));
    else 
        /* Error */ return (NULL);
    return (str_arg);
}

char *conversion_zero_flag(int fw, int precision, va_list args, char *pt)
{
	char *src;
	char *dst;
	int negative;

	negative = 0;
	if (fw < 0)
		negative = 1;
	src = conversion(pt, args);
	if ((fw = ft_abs(fw) - ft_strlen(src)) < 0)
		fw = 0;
	dst = (char*)ft_calloc(ft_strlen(src) + fw + 1, sizeof(char*));
	if (negative)
	{
		if (src[0] == '-')
			ft_strlcat(dst, src, ft_strlen(dst) + ft_strlen(src) + 2);
		while (fw--)
			ft_strlcat(dst, " ", ft_strlen(dst) + 2);
	}	
	else
	{
		if (src[0] == '-')
			ft_strlcat(dst, "-", ft_strlen(dst) + 2);
		while (fw--)
			ft_strlcat(dst, "0", ft_strlen(dst) + 2);
		ft_strlcat(dst, src + 1, ft_strlen(dst) + ft_strlen(src) + 2);
	}
	free(src);
	return (dst);	
}

char *conversion_wildcard(int fw, int precision, va_list args, char *pt, int negative)
{
	char *src;
	char *dst;
	
	if (fw < 0)
		negative = 1;
	src = conversion(pt, args);
	if ((fw = ft_abs(fw) - ft_strlen(src)) < 0)
		fw = 0;
	dst = (char*)ft_calloc(ft_strlen(src) + fw + 1, sizeof(char*));
	if (negative)			
	{
		ft_strlcat(dst, src, ft_strlen(dst) + ft_strlen(src) + 2);
		while (fw--)
			ft_strlcat(dst, " ", ft_strlen(dst) + 2);
	}
	else
	{
		while (fw--)
			ft_strlcat(dst, " ", ft_strlen(dst) + 2);
		ft_strlcat(dst, src, ft_strlen(dst) + ft_strlen(src) + 2);
	}	
	free(src);
	return (dst);	
}

char *conversion_wildcard_dot(int fw, int precision, va_list args, char *pt, int negative)
{
	char *src;
	char *dst;
	
	if (fw < 0)
		negative = 1;
	src = conversion(pt, args);
	if ((fw = ft_abs(fw) - ft_strlen(src)) < 0)
		fw = 0;
	dst = (char*)ft_calloc(ft_strlen(src) + fw + 1, sizeof(char*));
	if (negative)			
	{
		ft_strlcat(dst, src, ft_strlen(dst) + ft_strlen(src) + 2);
		while (fw--)
			ft_strlcat(dst, " ", ft_strlen(dst) + 2);
	}
	else
	{
		while (fw--)
			ft_strlcat(dst, " ", ft_strlen(dst) + 2);
		ft_strlcat(dst, src, ft_strlen(dst) + ft_strlen(src) + 2);
	}	
	free(src);
	return (dst);	
}

char *conversion_wildcard_dot_digit(int fw, int precision, va_list args, char *pt, int negative)
{
	char *src;
	char *dst;
	
	if (fw < 0)
		negative = 1;
	src = conversion(pt, args);
	if ((fw = ft_abs(fw) - ft_strlen(src)) < 0)
		fw = 0;
	dst = (char*)ft_calloc(ft_strlen(src) + fw + 1, sizeof(char*));
	if (negative)			
	{
		ft_strlcat(dst, src, ft_strlen(dst) + ft_strlen(src) + 2);
		while (fw--)
			ft_strlcat(dst, " ", ft_strlen(dst) + 2);
	}
	else
	{
		while (fw--)
			ft_strlcat(dst, " ", ft_strlen(dst) + 2);
		ft_strlcat(dst, src, ft_strlen(dst) + ft_strlen(src) + 2);
	}	
	free(src);
	return (dst);	
}
