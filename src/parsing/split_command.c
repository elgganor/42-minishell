/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:23:49 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/06/03 10:00:53 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** @description
**
** @param
** @return
*/

char	**split_command(char *command)
{
	char **command_arguments;

	command_arguments = ft_split(command, ' ');
	return (command_arguments);
}
