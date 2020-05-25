/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:25:19 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/25 20:56:36 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	execute_commands(char **commands)
{
	int		len;
	char	**command;

	len = 0;
	while (commands[len] != NULL)
	{
		if ((command = split_command(commands[len])) != NULL)
		{
			if (check_command_type(command[0]) == BUILTIN)
				run_builtin(command);
			else
				run_system_program(command);
			free_split(command);
			command = NULL;
		}
		len++;
	}
	return (1);
}
