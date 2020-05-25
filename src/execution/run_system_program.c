/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_system_program.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:29:32 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/25 22:09:01 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	run_system_program(char **command)
{
	pid_t	pid;
	// int		status;

	printf("system program: %s\n", command[0]);
	pid = fork();
	if (pid == 0)
	{
		// execute
	}
	else if (pid < 0)
	{
		// error handling
	}
	else
	{
		// parent process
	}
	return (0);
}