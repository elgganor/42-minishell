/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endwith.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 10:12:42 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/08/23 15:19:29 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int ft_endwith(char *str, char *end)
{
	int end_length;
	int str_length;
	int	start_position;

	if (end != NULL && str != NULL)
	{
		end_length = ft_strlen(end);
		str_length = ft_strlen(str);
		if (end_length <= str_length)
		{
			start_position = str_length - end_length;
			if (!ft_strncmp(&str[start_position], end, end_length))
				return (1);
		}
	}
	return (0);
}
