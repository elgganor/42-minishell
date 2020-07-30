/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 10:22:14 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/30 12:14:21 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_key(char *command, int start, int end)
{
	char *var_name;

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

void	process_env(char **command, int start)
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
}
