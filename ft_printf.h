/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:58:00 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/09 09:00:45 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
int ft_printf(const char *string, ...);

int isConvertor(char ch);
int count_character(char *string, char character);
char *dupCatResize(char *old, char *start, char *end);
char *conversion(char *pt, va_list args);
char conversion_hex_table(unsigned long input, char *pt);
char *int2hexstring(unsigned long input, char *pt, size_t size);

int ex2case1(char *pt);
int ex2case2(char *pt);
int ex2case3(char *pt);
int ex2case4(char *pt);
int ex2case5(char *pt);
int handle_ex2cases(char *pt);
int is_digit_or_wildcard(char *pt);
int is_diuxX(char ch);
char    *strchr_whitespace(char *pt);
int atoi_next_pt(char *string, char **next_pt);
unsigned int ft_abs(int i);
char *handle(char *pt, int negative, va_list args, char **next_pt);
char *conversion_zero_flag(int fw, va_list args, char *pt);
char *conversion_wildcard(int fw, va_list args, char *pt, int negative);
char *conversion_wildcard_dot(int fw, va_list args, char *pt, int negative);
char *conversion_wildcard_dot_digit(int fw, int precision, va_list args, char *pt, int negative);
#endif
