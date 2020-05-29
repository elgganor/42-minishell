/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_system_program.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:29:32 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/27 12:50:28 by mrouabeh         ###   ########.fr       */
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

int		is_executable(char *bin)
{
	struct stat f;

	if (lstat(bin, &f) == -1)
		return (0);
	if (f.st_mode & S_IFREG)
	{
		if (f.st_mode & S_IXUSR)
			return (1);
		else
			ft_printerror("Permission denied;");
	}
	return (0);
}

void	get_absolute_path(char **command)
{
	char	*path;
	char	*bin;
	char	**path_split;
	int		i;

	if ((path = ft_strdup(get_env_var("PATH"))) == NULL)
		path = ft_strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");
	if (*command[0] != '/' && ft_strncmp(*command, "./", 2) != 0)
	{
		path_split = ft_split(path, ':');
		i = -1;
		while (path_split[++i] != NULL)
		{
			bin = join_path(path_split[i], *command);
			if (bin == NULL)
				break ;
			if (is_executable(bin))
				break ;
		}
		free_split(path_split);
		free(*command);
		*command = bin;
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
			ft_putstr("Shell: No such file or directory\n");
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
