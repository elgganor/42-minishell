/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_system_program.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:29:32 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/26 19:38:45 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*join_path(char *path, char *command)
{
	char	*bin;
	char	*tmp;

	bin = (char *)ft_calloc(sizeof(char),
					ft_strlen(command) + ft_strlen(path) + 2);
	if (bin == NULL)
		return (NULL);
	tmp = ft_strjoin(path, "/");
	bin = ft_strjoin(tmp, command);
	free(tmp);
	return (bin);
}

void	get_absolute_path(char **command)
{
	char	*path;
	char	*bin;
	char	**path_split;
	int		i;

	if ((path = get_env_var("PATH")) == NULL)
		path = ft_strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");
	if (command[0][0] != '/' && ft_strncmp(command[0], "./", 2) != 0)
	{
		path_split = split(path, ":");
		i = -1;
		while (path_split[++i] != NULL)
		{
			bin = join_path(path_split[i], command[0]);
			if (bin == NULL)
				break ;
			// check l'existence du binaire et on quitte la boucle si existe
		}
		free_split(path_split);
		free(command[0]);
		command[0] = bin;
	}
	free(path);
}

int		run_system_program(char **command)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(command[0], command, NULL) == -1)
			ft_printerror("Shell: No such file or directory");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		ft_printerror("Error with forking");
	else
	{
		waitpid(pid, &status, WUNTRACED);
		kill(pid, SIGTERM);
	}
	return (1);
}
