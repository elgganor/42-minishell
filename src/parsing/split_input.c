/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:17:27 by mohamed           #+#    #+#             */
/*   Updated: 2020/07/08 17:17:32 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>


char	**split_input(char *input)
{
	char	**commands;
	char	*tmp;
	int		i;

	i = 0;
	commands = ft_split(input, ';');
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
