/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:25:19 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/02 10:04:36 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/**
* call the right function to execute the command
*
* @param char** command to execute
* @return int status of execution
*/

int	execute_command(char **command)
{
	int	status;

	status = 1;
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
	return (status);
}

/**
* Check if the command is a builtin or a system program and execute it
*
* @param    char** the command to execute
* @return   int status of the execution
*/

int	execute_commands(char *command)
{
	char		**commandArgs;
	int			status;

	status = 1;
	if ((commandArgs = split_command(command)) != NULL)
	{
		parse_env_var(commandArgs);
		if (redirection(&commandArgs))
			status = execute_command(commandArgs);
		free_split(commandArgs);
		clear_redirection();
	}
	return (status);
}

/**
* Execute commands with pipe
*
* @param char** list of piped commands
* @return int status of the execution
*/

int	execute_piped_commands(char **piped_commands)
{
	int len;

	len = 0;
	while (piped_commands[len] != NULL)
	{
		/*
		** On split la command avec les espaces
		** On parse les variable d'environnement
		*/
		ft_putstr("piped => ");
		ft_putendl_fd(piped_commands[len], 1);
		len++;
	}
	return (1);
}