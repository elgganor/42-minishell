/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:52:05 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/15 09:58:35 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/**
* @description
*
* @param char* key of the variable
* @return char* value of the variable
*/

char	*get_env_var(char *key)
{
	t_env	*env;

	env = g_env;
	while (env != NULL)
	{
		if (ft_strcmp(env->key, key) == 0)
		{
			return (env->value);
		}
		env = env->next;
	}
	return (NULL);
}

/**
* Append a new variable to the global env linked list
*
* @param char* The variable to append
*/

void	append_env(char *var)
{
	t_env	*new;
	t_env	*last;
	char	**tmp;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		return ;
	if ((tmp = ft_split(var, '=')) != NULL && tmp[0] != NULL && tmp[1] != NULL)
	{
		new->key = ft_strdup(tmp[0]);
		new->value = ft_strdup(tmp[1]);
		free_split(tmp);
		new->next = NULL;
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
}

/**
* initialise the global environment linked list wich containes variables
*
* @param char** array of environment variable
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
