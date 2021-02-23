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
char *convert_ex1(char *pt, va_list args);
char convert_ex1_hex_table(unsigned long input, char *pt);
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
void catpositive(int nb_space, int nb_zero, char *dst, char *src);
void catnegative(int nb_space, int nb_zero, char *dst, char *src);
#endif
