/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 10:22:14 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/29 14:50:51 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// void	parse_env_var(char **command)
// {
// 	int		i;
// 	int		len;
// 	char	*var;
// 	char	*var_name;

// 	i = 0;
// 	while (command[i] != NULL)
// 	{
// 		if (!ft_strncmp(command[i], "$", 1))
// 		{
// 			len = ft_strlen(command[i]);
// 			var_name = ft_substr(command[i], 1, len - 1);
// 			var = get_env_var(var_name) == NULL ? "" : get_env_var(var_name);
// 			ft_substitute(&command[i], var);
// 			free(var_name);
// 		}
// 		i++;
// 	}
// }

char	*get_key(char *command, int start, int end)
{
	char *var_name;

	var_name = ft_substr(command, start + 1, end - (start + 1));
	return (var_name);
}

void	substitute_env_variable(char **command, char *key, int start, int end)
{
	char	*first_part;
	char	*last_part;
	// char	*dest;
	(void)key;

	first_part = ft_slice(*command, 0, start - 1);
	last_part = ft_slice(*command, end, ft_strlen(*command));
}

void	process_env(char **command, int start)
{
	char	*key;
	char	*value;
	int		end;

	end = start + 1;
	while ((*command)[end] != '\0' && (ft_isalnum((*command)[end]) || (*command)[end] == '_'))
		end++;
	key = get_key(*command, start, end);
	value = get_env_var(key);
	substitute_env_variable(command, key, start, end);
}
