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
