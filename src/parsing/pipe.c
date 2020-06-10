/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 09:55:26 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/06/10 11:04:24 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**parse_pipe(char *command)
{
	char **piped_commands;

	if ((piped_commands = ft_split(command, '|')) == NULL)
		return (NULL);
	if (ft_arrlen(piped_commands) <= 1)
		return (NULL);
	return (piped_commands);
}