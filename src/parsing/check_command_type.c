/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:54:40 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/25 22:08:45 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char *g_builtins[] = {
	"echo",
	"cd",
	"pwd",
	"export",
	"unset",
	"env",
	"exit"
};

/*
** Check si il s'agit d'une commande valide et si il s'agit d'un builtin
** ou bien d'un system program
** return: 0 error, 1 sysprog, 2 builtin
*/
int	check_command_type(char *command)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (ft_strcmp(command, g_builtins[i]) == 0)
			return (BUILTIN);
		i++;
	}
	return (SYSPROG);
}