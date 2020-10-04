/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:41:09 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/10/04 16:15:04 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*take_input(void)
{
	char	*input;

	if (get_next_line(0, &input) <= 0)
	{
		ft_puterr("Impossible to take input");
		exit(EXIT_FAILURE);
	}
	return (input);
}
