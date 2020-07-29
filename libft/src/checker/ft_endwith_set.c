/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endwith_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 10:15:55 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/29 10:18:58 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_endwith_set(char *str, char *set)
{
	int i;

	if (str != NULL && set != NULL)
	{
		i = 0;
		while (set[i] != '\0')
		{
			if (ft_endwith(str, set[i]))
				return (1);
			i++;
		}
	}
	return (0);
}
