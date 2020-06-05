/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:52:05 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/06/03 10:01:31 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** @description
**
** @param
** @return
*/

char	*get_env_var(char *var)
{
	t_env	*env;
	char	*tmp_var;

	tmp_var = ft_strjoin(var, "=");
	env = g_env;
	while (env != NULL)
	{
		if (ft_strncmp(env->variable, tmp_var, ft_strlen(tmp_var)) == 0)
		{
			free(tmp_var);
			return (ft_strchr(env->variable, '=') + 1);
		}
		env = env->next;
	}
	free(tmp_var);
	return (NULL);
}

/*
** @description
**
** @param
** @return
*/

void	append_env(char *var)
{
	t_env	*new;
	t_env	*last;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		return ;
	new->next = NULL;
	new->variable = ft_strdup(var);
	last = g_env;
	if (!g_env)
		g_env = new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

/*
** @description
**
** @param
** @return
*/

void	init_env(char **env)
{
	int	i;

	if (!(g_env = (t_env *)malloc(sizeof(t_env))))
		exit(EXIT_FAILURE);
	g_env = NULL;
	i = -1;
	while (env[++i] != NULL)
		append_env(env[i]);
}
