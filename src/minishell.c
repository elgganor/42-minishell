/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:37:47 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/23 11:32:13 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/**
* Main loop for the shell
* Read, parse and execute commands
*/

void	shell_loop(void)
{
	char	*line;
	char	**commands;
	int		status;

	status = SUCCESS_STATUS;
	while (status)
	{
		show_prompt();
		line = take_input();
		commands = split_input(line);
		if (commands)
		{
			status = process_commands(commands);
			free_split(commands);
		}
		else
		{
			status = FAILURE_STATUS;
			ft_puterr("Impossible to treat commands");
		}
		free(line);
		g_status = status;
	}
	free_env();
}

int		main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	g_status = 0;
	init_env(envp);
	shell_loop();
	return (EXIT_SUCCESS);
}
