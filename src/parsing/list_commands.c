/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:19:29 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/06/03 10:01:00 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** @description
**
** @param
** @return
*/

char	**list_commands(char *line)
{
	char	**commands;
	char	*tmp;
	int		i;

	i = 0;
	commands = ft_split(line, ';');
	while (commands[i] != NULL)
	{
		tmp = ft_strtrim(commands[i], " ");
		free(commands[i]);
		commands[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	return (commands);
}
