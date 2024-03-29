/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_system_program.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:29:32 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/10/04 16:24:13 by mrouabeh         ###   ########.fr       */
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
			ft_puterr("Permission denied");
	}
	return (0);
}

char	*get_absolute_path2(char *path, char *command)
{
	char	**path_split;
	char	*bin;
	int		i;

	path_split = ft_split(path, ':');
	i = -1;
	while (path_split[++i] != NULL)
	{
		bin = join_path(path_split[i], command);
		if (bin == NULL || is_executable(bin))
			break ;
	}
	free_split(path_split);
	return (bin);
}

void	get_absolute_path(char **command)
{
	char	*path;
	char	*bin;

	if ((path = ft_strdup(get_env_var("PATH"))) == NULL)
		path = ft_strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");
	if (*command[0] != '/' && ft_strncmp(*command, "./", 2) != 0)
	{
		bin = join_path("/", *command);
		if (!is_executable(bin))
			bin = get_absolute_path2(path, *command);
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
			ft_puterr("No such file or directory");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		ft_puterr("Error with forking");
	else
	{
		waitpid(pid, &status, WUNTRACED);
		kill(pid, SIGTERM);
	}
	return (1);
}
