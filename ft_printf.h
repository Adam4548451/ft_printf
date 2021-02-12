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
char *ft_strchr(char *s, int c);
int ft_isdigit(int c);
int ft_isspace(int c);

int count_character(char *string, char character);
int isExigence1(char ch);
int isExigence2(char ch);
#endif