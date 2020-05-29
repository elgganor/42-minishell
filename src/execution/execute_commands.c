/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:25:19 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/29 11:25:02 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Check if the command is a builtin or a system program and execute it
*/

int	execute_commands(char **commands)
{
	int		len;
	char	**command;
	int		status;

	len = 0;
	status = 1;
	while (commands[len] != NULL)
	{
		if ((command = split_command(commands[len])) != NULL)
		{
			if (is_builtin(command[0]))
				status = run_builtin(command);
			else
			{
				get_absolute_path(&command[0]);
				if (command[0] == NULL)
					ft_puterr("Command not found");
				else
					status = run_system_program(command);
			}
			free_split(command);
		}
		len++;
	}
	return (status);
}
