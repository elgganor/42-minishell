/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 13:09:13 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/10/11 14:01:31 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	is_redirection(char *command)
{
	if (ft_startwith(command, ">>") || ft_startwith_char(command, '>')
		|| ft_endwith_char(command, '<'))
		return (1);
	return (0);
}

static int	is_space_redirection(char *command)
{
	if (!ft_strcmp(command, ">") || !ft_strcmp(command, ">>")
		|| !ft_strcmp(command, "<"))
		return (1);
	return (0);
}

static char	**allocate_tmp_command(char **command)
{
	int		len;
	int		i;
	char	**tmp;

	len = ft_arrlen(command) + 1;
	i = 0;
	while (command[i] != NULL)
	{
		if (is_redirection(command[i]))
		{
			len--;
			if (is_space_redirection(command[i]) && command[i + 1] != NULL)
			{
				len--;
				i++;
			}
		}
		i++;
	}
	if (!(tmp = (char **)malloc(sizeof(char *) * len)))
		return (NULL);
	return (tmp);
}

int			clear_command_of_redirection(char ***command)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	if (!(tmp = allocate_tmp_command(*command)))
		return (0);
	while ((*command)[i] != NULL)
	{
		if (is_redirection((*command)[i]))
		{
			if (is_space_redirection((*command)[i]) && (*command)[i + 1])
				i++;
		}
		else
			tmp[j++] = ft_strdup((*command)[i]);
		i++;
	}
	tmp[j] = NULL;
	free_split(*command);
	*command = tmp;
	return (1);
}

void	reset_redirection(void)
{
	int	stdout;
	int	stdin;

	stdout = open("/dev/tty", O_RDWR);
	dup2(stdout, 1);
	stdin = open("/dev/tty", O_RDWR);
	dup2(stdin, 0);
}
