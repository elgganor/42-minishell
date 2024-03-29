/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substitute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 10:19:56 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/29 10:20:12 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_substitute(char **old, char *new)
{
	free(*old);
	*old = ft_strdup(new);
}
