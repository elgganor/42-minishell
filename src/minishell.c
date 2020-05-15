/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:37:47 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/15 17:53:31 by mrouabeh         ###   ########.fr       */
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
	ft_putstr(" > ");
}

void	shell_loop(void)
{
	char	*line;
	char	**commands;
	int		status;

	status = 1;
	while (status)
	{
		show_prompt();
		if (get_next_line(1, &line) <= 0)
			status = 0;
		else
		{
			commands = split_command(line);
			// TODO: parser chaque commande et l'executer
			if (commands != NULL)
				free_split(commands);
			free(line);
		}
	}
}

int		main(void)
{
	shell_loop();
	return (EXIT_SUCCESS);
}
