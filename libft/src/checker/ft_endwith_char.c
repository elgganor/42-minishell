/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endwith_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 15:03:05 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/08/23 15:03:43 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int ft_endwith_char(char *str, int c)
{
	int len;

	if (str != NULL)
	{
		len = ft_strlen(str);
		return (str[len - 1] == c);
	}
	return (0);
}
