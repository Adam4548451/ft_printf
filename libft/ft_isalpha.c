/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:58:22 by amaroni           #+#    #+#             */
/*   Updated: 2020/11/19 19:05:24 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (((c >= 'a') && (c <= 'z'))
	|| ((c >= 'A') && (c <= 'Z')))
		return (1024);
	return (0);
}
