/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:23:49 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/08/17 11:02:16 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**split_command(char *command)
{
	char	**split;
	char	**command_arguments;

	split = ft_split(command, ' ');
	if (split != NULL)
	{
		command_arguments = join_quotes(split);
		free_split(split);
	}
	else
		command_arguments = NULL;
	return (command_arguments);
}
