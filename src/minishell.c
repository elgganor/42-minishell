/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:13:41 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/10/04 16:04:30 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	signal_handler(int signal)
{
	int status;

	status = 0;
	while (wait(&status) > 0)
		;
	if (signal == SIGINT)
	{
		g_status = 130;
		write(1, "\n", 1);
		if (status == 0)
			show_prompt();
	}
	else if (status == 131)
	{
		g_status = 131;
		wait(&status);
		write(1, "Quit (core dumped)\n", 19);
	}
}

void	shell_loop(void)
{
	char	*line;
	char	**commands;

	while (g_status)
	{
		show_prompt();
		line = take_input();
		commands = split_input(line);
		if (commands)
		{
			g_status = process_commands(commands);
			free_split(commands);
		}
		else
			ft_puterr("Impossible to treat commands");
		free(line);
	}
	free_env();
}

int		main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	g_status = SUCCESS_STATUS;
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	init_env(envp);
	shell_loop();
	return (EXIT_SUCCESS);
}
