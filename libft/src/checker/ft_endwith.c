/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endwith.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 10:12:42 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/29 10:14:18 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_endwith(char *str, int c)
{
	int	len;

	if (str != NULL)
	{
		len = ft_strlen(str);
		return (str[len - 1] == c);
	}
	return (0);
}
