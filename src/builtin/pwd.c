/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astriddelcros <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 16:20:38 by astriddel         #+#    #+#             */
/*   Updated: 2020/05/28 14:52:42 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(char *command)
{
	char	*path;
	char	buf[PATH_MAX + 1];
	(void)command;
	int	i;

	i = 0;
	if (command[i] > 0)
	{
		ft_putstr("Wrong number of arguments");
		return (0);
	}
	path = getcwd(buf, PATH_MAX);
	ft_putstr(path);
	return (0);
}
