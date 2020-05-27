/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:29:37 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/27 14:31:53 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	run_builtin(char **command)
{
	// if (!ft_strcmp(command[0], "cd"))
	// 	builtin_cd(command);
	// else if (!ft_strcmp(command[0], "echo"))
	// 	builtin_echo(command);
	// else if (!ft_strcmp(command[0], "pwd"))
	// 	builtin_pwd(command);
	// else if (!ft_strcmp(command[0], "export"))
	// 	builtin_export(command);
	// else if (!ft_strcmp(command[0], "unset"))
	// 	builtin_unset(command);
	// else if (!ft_strcmp(command[0], "env"))
	// 	builtin_env(command);
	// else if (!ft_strcmp(command[0], "exit"))
	// {
	// 	builtin_exit(command);
	// 	return (0);
	// }
	(void)command;
	return (1);
}
