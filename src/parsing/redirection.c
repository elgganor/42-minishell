/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:18:52 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/08/26 12:20:02 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	redirect_output(char **command, int pos)
{
	int		out;
	char	*output;

	out = 1;
	if (!ft_strcmp(command[pos], ">") && command[pos + 1] != NULL)
		output = ft_strdup(command[pos + 1]);
	else
		output = ft_slice(command[pos], 1, ft_strlen(command[pos]));
	if (output != NULL)
	{
		if ((out = open(output, OUT_MOD, OUT_RIGHT)) == -1)
		{
			ft_puterr("[1] Impossible to redirect output");
			return (0);
		}
		free(output);
	}
	if (dup2(out, 1) == -1)
	{
		ft_puterr("[2] Impossible to redirect output");
		return (0);
	}
	return (1);
}

int	append_redirect_output(char **command, int pos)
{
	int		out;
	char	*output;

	out = 1;
	if (!ft_strcmp(command[pos], ">>") && command[pos + 1] != NULL)
		output = ft_strdup(command[pos + 1]);
	else
		output = ft_slice(command[pos], 2, ft_strlen(command[pos]));
	if (output != NULL)
	{
		if ((out = open(output, APPEND_OUT_MOD, OUT_RIGHT)) == -1)
		{
			ft_puterr("[3] Impossible to redirect output");
			return (0);
		}
		free(output);
	}
	if (dup2(out, 1) == -1)
	{
		ft_puterr("[4] Impossible to redirect output");
		return (0);
	}
	return (1);
}

int redirect_input(char **command, int pos)
{
	int		in;
	char	*input;

	in = 0;
	if (!ft_strcmp(command[pos], "<") && command[pos + 1] != NULL)
		input = ft_strdup(command[pos + 1]);
	else
		input = ft_slice(command[pos], 1, ft_strlen(command[pos]));
	if (input != NULL)
	{
		if ((in = open(input, O_RDONLY)) == -1)
		{
			ft_puterr("Impossible to redirect intput");
			return (0);
		}
		free(input);
	}
	if (dup2(in, 0) == -1)
	{
		ft_puterr("Impossible to redirect input");
		return (0);
	}
	return (1);
}

int	redirection(char ***command)
{
	int	i;

	i = 0;
	while ((*command)[i++] != NULL)
	{
		if (ft_startwith((*command)[i], ">>"))
		{
			if (!append_redirect_output((*command), i))
				return (0);
		}
		else if (ft_startwith_char((*command)[i], '>'))
		{
			if (!redirect_output((*command), i))
				return (0);
		}
		else if (ft_endwith_char((*command)[i], '<'))
		{
			if (!redirect_input((*command), i))
				return (0);
		}
	}
	clear_command_of_redirection(command);
	return (1);
}
