/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:23:49 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/30 12:08:02 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		handle_state_of_quotes(char *str, int state_of_quote)
{
	if (ft_startwith(str, '"') && state_of_quote == 0)
		state_of_quote = 1;
	if (ft_startwith(str, '\'') && state_of_quote == 0)
		state_of_quote = 2;
	if (ft_endwith(str, '"') && state_of_quote == 1)
		state_of_quote = 0;
	if (ft_endwith(str, '\'') && state_of_quote == 2)
		state_of_quote = 0;
	return (state_of_quote);
}

char	**join_quotes(char **split)
{
	int	i;
	int	j;
	int state_of_quote;
	int old_state_of_quote;
	char *join;
	char **dest;
	char *tmp;

	i = 0;
	j = 0;
	state_of_quote = 0;
	old_state_of_quote = 0;
	if (!(dest = (char **)malloc(sizeof(char *) * (ft_arrlen(split) + 1))))
		return (NULL);
	while (split[i] != NULL)
	{
		state_of_quote = handle_state_of_quotes(split[i], state_of_quote);
		if (state_of_quote != 0 && old_state_of_quote == 0)
		{
			tmp = ft_slice(split[i], 1, ft_strlen(split[i]));
			join = ft_strdup(tmp);
			free(tmp);
		}
		else if (state_of_quote != 0 && old_state_of_quote != 0)
		{
			join = ft_join_and_free(join, " ");
			join = ft_join_and_free(join, split[i]);
		}
		else if (state_of_quote == 0 && old_state_of_quote != 0)
		{
			join = ft_join_and_free(join, " ");
			tmp = ft_slice(split[i], 0, ft_strlen(split[i]) - 2);
			join = ft_join_and_free(join, tmp);
			dest[j++] = join;
			free(tmp);
		}
		else
			dest[j++] = ft_strdup(split[i]);
		old_state_of_quote = state_of_quote;
		i++;
	}
	dest[j] = NULL;
	while (j++ < ft_arrlen(split))
		free(dest[j]);
	return (dest);
}

char	**split_command(char *command)
{
	char	**split;
	char	**command_arguments;

	split = ft_split(command, ' ');
	if (split != NULL)
	{
		command_arguments = join_quotes(split);
		free_split(split);
	}
	else
		command_arguments = NULL;
	return (command_arguments);
}
