/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:05:10 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/08 17:19:44 by mohamed          ###   ########.fr       */
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