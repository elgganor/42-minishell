/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 11:50:34 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/26 15:08:41 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*g_builtins[] = {
	"echo",
	"cd",
	"pwd",
	"export",
	"unset",
	"env",
	"exit"
};

/*
** Check if the command is a builtin or a system program
*/

int	is_builtin(char *command)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (ft_strcmp(command, g_builtins[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
