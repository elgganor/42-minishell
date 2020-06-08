/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 10:16:49 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/06/08 11:00:38 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	parse_env_var(char **command)
{
	int		i;
	int		len;
	char	*var;
	char	*var_name;

	i = 0;
	while (command[i] != NULL)
	{
		if (!ft_strncmp(command[i], "$", 1))
		{
			len = ft_strlen(command[i]);
			var_name = ft_substr(command[i], 1, len - 1);
			var = get_env_var(var_name) == NULL ? "" : get_env_var(var_name);
			ft_substitute(&command[i], var);
			free(var_name);
		}
		i++;
	}
}