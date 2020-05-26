/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_system_program.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:29:32 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/26 12:28:22 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	run_system_program(char **command, char **env)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	printf("system program: %s\n", command[0]);
	pid = fork();
	if (pid == 0)
	{
		// execute
		(void)env;
	}
	else if (pid < 0)
		ft_printerror("Error with forking");
	else
		while (!WIFEXITED(status) || !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	return (1);
}
