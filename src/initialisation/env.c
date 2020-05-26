/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:52:05 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/26 15:07:02 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		env_len(char **env)
{
	int	len;

	len = 0;
	while (env[len] != NULL)
		len++;
	return (len);
}

void	init_env(char **env)
{
	int	i;

	if (!(g_env = (char **)malloc(sizeof(char *) * (env_len(env) + 1))))
		return ;
	i = 0;
	while (env[i] != NULL)
	{
		g_env[i] = ft_strdup(env[i]);
		i++;
	}
	g_env[i] = NULL;
}

char	*get_env_var(char *var)
{
	char	*tmp_var;
	int		i;

	i = 0;
	tmp_var = ft_strjoin(var, "=");
	while (g_env[i] != NULL)
	{
		if (ft_strncmp(g_env[i], tmp_var, ft_strlen(tmp_var)) == 0)
		{
			free(tmp_var);
			return (ft_strchr(g_env[i], '=') + 1);
		}
		i++;
	}
	free(tmp_var);
	return (NULL);
}
