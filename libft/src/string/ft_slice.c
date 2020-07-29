/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:55:04 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/29 14:20:43 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_slice(char *str, int start, int end)
{
	char	*dest;

	if (!str || start > end)
		return (NULL);
	dest = ft_substr(str, start, (end - start) + 1);
	return (dest);
}
