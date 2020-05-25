/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:25:19 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/25 03:10:07 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	execute_commands(char **commands)
{
	int		len;
	char	**command;

	len = 0;
	while (commands[len] != NULL)
	{
		if ((command = split_command(commands[len])) != NULL)
		{
			// check si builtin ou system program
//			if (!ft_strcmp(command[0], "pwd"))
//				builtin_pwd();
			if (!ft_strcmp(command[0], "cd"))
				builtin_cd();
			// execute la commande
		}
		len++;
	}
	return (1);
}
