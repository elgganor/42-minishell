/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:13:41 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/08/12 09:13:45 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
