/* ************************************************************************** */ /*                                                                            */ /*                                                        :::      ::::::::   */ /*   ft_printf.h                                        :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */ /*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:41:58 by amaroni           #+#    #+#             */
/*   Updated: 2021/02/10 14:42:01 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
int ft_printf(const char *string, ...);

int count_character(char *string, char character);
int isExigence1(char ch);
int isExigence2(char ch);
int count_character(char *string, char character);
int isExigence1(char ch);
int isExigence2(char ch);
char *dupCatResize(char *old, char *start, char *end);
char *convert_s(char *arg);
char convert_c(char arg);
char convert_p(char arg);
char convert_d(char arg);
char convert_percent(char arg);
char convert_i(char arg);
char convert_u(char arg);
char convert_x(char arg);
char convert_X(char arg);
#endif