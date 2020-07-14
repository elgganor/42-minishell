/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:05:10 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/14 16:39:25 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	process_commands(char **commands)
{
	int	len;
	int status;
	char **piped_commands;

	len = 0;
	status = 1;
	while (commands[len] != NULL)
	{
		if ((piped_commands = parse_pipe(commands[len])) != NULL)
		{
			status = execute_piped_commands(piped_commands);
			free_split(piped_commands);
		}
		else
			status = execute_commands(commands[len]);
		len++;
	}
	return (status);
}
