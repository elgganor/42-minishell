/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:37:47 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/22 13:37:07 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	shell_loop(void)
{
	char	*line;
	char	**commands;
	int		status;

	status = 1;
	while (status)
	{
		show_prompt();
		if (get_next_line(0, &line) <= 0)
			status = 0;
		else
		{
			status = 0;
			commands = list_commands(line);
			if (commands != NULL)
			{
				status = execute_commands(commands);
				free_split(commands);
			}
			free(line);
		}
	}
}

int		main(void)
{
	shell_loop();
	return (EXIT_SUCCESS);
}
