/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startwith.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 10:10:03 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/08/23 15:16:49 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_startwith(char *str, char *start)
{
	int	start_length;
	int str_length;

	if (start != NULL && str != NULL)
	{
		start_length = ft_strlen(start);
		str_length = ft_strlen(str);
		if (start_length <= str_length)
		{
			if (!ft_strncmp(str, start, start_length))
				return (1);
		}
	}
	return (0);
}
