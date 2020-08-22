/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 15:40:59 by astriddel         #+#    #+#             */
/*   Updated: 2020/08/22 17:27:55 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int display_export()
{
	t_env *current;

	current = g_env;
	while (current != NULL)
	{
		ft_putstr("declare -x ");
		ft_putstr(current->key);
		if (current->value)
		{
			ft_putstr("=\"");
			ft_putstr(current->value);
			ft_putstr("\"");
		}
		ft_putstr("\n");
		current = current->next;
	}
	return (1);
}

int  valid_key(char *key)
{
	int  i;

	i = 0;
	if (!key)
		return (0);
	if (!ft_isalpha(key[0]) && key[0] != '_')
	{
		ft_putstr("key must begin by a letter or _\n");
		return (0);
	}
	while (key[++i])
	{
		if (!ft_isalpha(key[i]) && !ft_isdigit(key[i]) && key[i] != '_')
		{
			ft_putstr("variable must contain only letters, digits or _\n");
			return (0);
		}
	}
	return (1);
}

static int		env_size(t_env *env)
{
    int i;

    i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}

static t_env	*get_by_id(t_env *env, int n)
{
    int i;

    i = -1;
	while (++i < n)
		env = env->next;
	return (env);
}

static void     sort_by_ascii(t_env *env, int *t, int size)
{
    int i;
	int tmp;
    int is_sorted;

    i = -1;
	is_sorted = 0;
	while (++i < size)
		t[i] = i;
	while (is_sorted == 0)
	{
		is_sorted = 1;
		i = -1;
		while (++i < size - 1)
        {
			if (ft_strcmp(get_by_id(env, t[i])->key, get_by_id(env, t[i + 1])->key) > 0)
            {
				tmp = t[i];
				t[i] = t[i + 1];
				t[i + 1] = tmp;
				is_sorted = 0;
			}
		}
	}
}

int     display_export()
{
	t_env *current;
	int t[env_size(g_env)];
	int size;
	int i;

    size = env_size(g_env);
    i = -1;  
	sort_by_ascii(g_env, t, env_size(g_env));
	while (++i < size)
	{
		current = get_by_id(g_env, t[i]);
		if (ft_strcmp(current->key, "_") == 0)
			continue ;
		ft_putstr("declare -x ");
		ft_putstr(current->key);
		if (current->value)
		{
			ft_putstr("=\"");
			ft_putstr(current->value);
			ft_putstr("\"");
		}
		ft_putstr("\n");
		current = current->next;
	}
	return (1);
}

int		export_variable(char *variable)
{
	char	**split_variable;
	t_env	*new_env;
	t_env	*current;

	split_variable = ft_split(variable, '=');
	current = g_env;
	if (split_variable != NULL && valid_key(split_variable[0]))
	{
		while (current != NULL)
		{
			if (!ft_strcmp(current->key, split_variable[0]))
			{
                if (current->value != NULL && split_variable[1] != NULL)
                    free(current->value);
                current->value = split_variable[1] || ft_endwith(variable, '=') ? split_variable[1] : current->value; // vaut null si il n'y a pas de = et vaut value sinon
				return (1);
			}
			current = current->next;
		}
		new_env = ft_calloc(1, sizeof(t_env));
		current = g_env;
		while (current->next != NULL)
			current = current->next;
		new_env->key = split_variable[0];
		new_env->value = split_variable[1];
		new_env->next = NULL;
		current->next = new_env;
		return (1);
	}
	return (0);
}

int  builtin_export(char **command)
{
	int	i;

	if (!command[1])
	{
		return (display_export());
	}
	else
	{
		i = 1;
		while (command[i])
		{
			export_variable(command[i]);
			i++;
		}
	}
	return (1);
}
