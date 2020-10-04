/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:29:37 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/10/04 16:14:29 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	run_builtin(char **command)
{
	int	status;

	status = 0;
	if (!ft_strcmp(command[0], "pwd"))
		status = builtin_pwd();
	else if (!ft_strcmp(command[0], "cd"))
		status = builtin_cd(command);
	else if (!ft_strcmp(command[0], "echo"))
		status = builtin_echo(command);
	else if (!ft_strcmp(command[0], "export"))
		status = builtin_export(command);
	else if (!ft_strcmp(command[0], "unset"))
		status = builtin_unset(command);
	else if (!ft_strcmp(command[0], "env"))
		status = builtin_env();
	else if (!ft_strcmp(command[0], "exit"))
		status = builtin_exit(command);
	return (status);
}
