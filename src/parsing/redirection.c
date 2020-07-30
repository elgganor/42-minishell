/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:18:52 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/30 12:17:26 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	redirect_input(char **command, int pos)
{
	int	in;

	in = 0;
	if ((in = open(command[pos + 1], O_RDONLY)) == -1)
	{
		ft_puterr("No such file or directory");
		return (0);
	}
	dup2(in, 0);
	return (1);
}

int	redirect_output(char **command, int pos, int type)
{
	int	out;

	out = 1;
	if (command[pos + 1] != NULL)
	{
		if (type == 0)
		{
			if ((out = open(command[pos + 1], O_CREAT | O_WRONLY,
				S_IWUSR | S_IRUSR)) == -1)
			{
				ft_puterr("Impossible to redirect output");
				return (0);
			}
		}
		else if (type == 1)
		{
			if ((out = open(command[pos + 1], O_CREAT | O_WRONLY | O_APPEND,
				S_IWUSR | S_IRUSR)) == -1)
			{
				ft_puterr("Impossible to redirect output");
				return (0);
			}
		}
	}
	dup2(out, 1);
	return (1);
}

int	redirection(char ***command)
{
	int	i;

	i = -1;
	while ((*command)[++i] != NULL)
	{
		if (!ft_strcmp((*command)[i], ">"))
		{
			if (!redirect_output((*command), i, 0))
				return (0);
		}
		else if (!ft_strcmp((*command)[i], ">>"))
		{
			if (!redirect_output((*command), i, 1))
				return (0);
		}
		else if (!ft_strcmp((*command)[i], "<"))
		{
			if (!redirect_input((*command), i))
				return (0);
		}
	}
	return (clear_command_of_redirection(command));
}
