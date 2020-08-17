/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 10:22:14 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/08/17 11:00:41 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_key(char *command, int start, int end)
{
	char	*var_name;

	var_name = ft_substr(command, start + 1, end - (start + 1));
	return (var_name);
}

void	substitute_env_variable(char **command, char *value, int start, int end)
{
	char	*first_part;
	char	*last_part;
	char	*dest;
	char	*tmp;

	first_part = ft_slice(*command, 0, start - 1);
	last_part = ft_slice(*command, end, ft_strlen(*command));
	tmp = ft_strjoin(first_part, value);
	dest = ft_strjoin(tmp, last_part);
	free(tmp);
	free(first_part);
	free(last_part);
	free(*command);
	*command = dest;
}

void	substitute_env(char **command, int start)
{
	char	*key;
	char	*value;
	int		end;

	end = start + 1;
	while ((*command)[end] != '\0' && (ft_isalnum((*command)[end])
		|| (*command)[end] == '_'))
		end++;
	key = get_key(*command, start, end);
	value = get_env_var(key);
	substitute_env_variable(command, value, start, end);
	free(key);
}

int		handle_state_of_quote(char c, int state_of_quote)
{
	if (c == '"')
	{
		if (state_of_quote == 1)
			state_of_quote = 0;
		else if (state_of_quote == 0)
			state_of_quote = 1;
	}
	else if (c == '\'')
	{
		if (state_of_quote == 2)
			state_of_quote = 0;
		else if (state_of_quote == 0)
			state_of_quote = 2;
	}
	return (state_of_quote);
}

void	process_env(char **command)
{
	int	i;
	int	state_of_quote;

	i = 0;
	state_of_quote = 0;
	while ((*command)[i] != '\0')
	{
		state_of_quote = handle_state_of_quote((*command)[i], state_of_quote);
		if ((*command)[i] == '$' && state_of_quote != 2)
			substitute_env(command, i);
		i++;
	}
	if (state_of_quote != 0)
		ft_puterr("Unclosed quotes");
}
