/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:21:29 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/26 10:39:18 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	show_prompt(void)
{
	char	directory[256];

	if (getcwd(directory, sizeof(directory)) == NULL)
		ft_putstr("Error:\nImpossible to get current directory;\n");
	else
		ft_putstr(directory);
	ft_putstr("> ");
}