/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:37:47 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/26 12:01:32 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Main loop for the shell
**
** Show the prompt, take the user input, parse the input and execute commands
*/

void	shell_loop(char **env)
{
	char	*line;
	char	**commands;
	int		status;

	status = 1;
	while (status)
	{
		status = 0;
		show_prompt();
		line = take_input();
		commands = list_commands(line);
		if (commands != NULL)
		{
			status = execute_commands(commands, env);
			free_split(commands);
		}
		else
			ft_printerror("Impossible to treat commands");
		free(line);
	}
}

int		main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	shell_loop(envp);
	return (EXIT_SUCCESS);
}
