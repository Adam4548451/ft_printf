/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:58:00 by amaroni           #+#    #+#             */
/*   Updated: 2021/02/17 09:58:14 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
int ft_printf(const char *string, ...);

int isExigence1(char ch);
int isExigence2(char ch);
int count_character(char *string, char character);
char *dupCatResize(char *old, char *start, char *end);
char *convert(char *pt, va_list args);
char convert_hex_table(unsigned long input, char *pt);
char *int2hexstring(unsigned long input, char *pt, size_t size);
#endif
