/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:25:19 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/09/01 08:58:13 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	reset_redirection(void)
{
	int	stdout;
	int	stdin;

	stdout = open("/dev/tty", O_RDWR);
	dup2(stdout, 1);
	stdin = open("/dev/tty", O_RDWR);
	dup2(stdin, 0);
}

int		execute_command(char **command)
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

int		execute_commands(char *command)
{
	char		**command_args;
	int			status;

	status = 1;
	if ((command_args = split_command(command)) != NULL)
	{
		if (redirection(&command_args))
			status = execute_command(command_args);
		reset_redirection();
		free_split(command_args);
	}
	return (status);
}

int		execute_piped_commands(char **piped_commands)
{
	int	len;
	int	status;
	int	nb_command;
	int	*pipes;

	len = -1;
	nb_command = ft_arrlen(piped_commands);
	pipes = init_pipes(nb_command);
	while (piped_commands[++len] != NULL)
	{
		if (fork() == 0)
		{
			dup_pipe(pipes, len, nb_command);
			close_pipes(pipes, nb_command);
			execute_commands(piped_commands[len]);
		}
	}
	close_pipes(pipes, nb_command);
	len = -1;
	while (++len < nb_command)
		wait(&status);
	return (1);
}
