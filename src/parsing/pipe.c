/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 09:55:26 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/08 18:01:38 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**parse_pipe(char *command)
{
	char **piped_commands;
	char *tmp;
	int i;

	i = 0;
	if ((piped_commands = ft_split(command, '|')) == NULL)
		return (NULL);
	if (ft_arrlen(piped_commands) == 1)
	{
		free_split(piped_commands);
		return (NULL);
	}
	while (piped_commands[i] != NULL)
	{
		tmp = ft_strtrim(piped_commands[i], " ");
		free(piped_commands[i]);
		piped_commands[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	return (piped_commands);
}