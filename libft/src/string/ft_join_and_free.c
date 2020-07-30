/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 11:18:02 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/30 11:18:04 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_join_and_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strdup(s1);
	free(s1);
	s1 = ft_strjoin(tmp, s2);
	free(tmp);
	return (s1);
}
