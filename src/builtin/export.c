/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 15:40:59 by astriddel         #+#    #+#             */
/*   Updated: 2020/07/30 17:09:57 by mrouabeh         ###   ########.fr       */
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

int add_export_builtin(char **command)
{
	char	*equal;
	t_env	*current;
	t_env	*new_var;

	current = g_env;
	new_var = ft_calloc(1, sizeof(t_env)); // pour initialiser en meme temps. Equivaut à  current->next = malloc(sizeof(t_env)); new_var = current->next; new_var->next = NULL / current->next->next = NULL
	equal = ft_strchr(command[1], '=');
	new_var->key = equal ? ft_substr(command[1], 0, equal - command[1]) : ft_strdup(command[1]);
	if (ft_strcmp(new_var->key, "_"))
	// (valid_key(new_var->key) == 1 &&
	{
		current = g_env;
		while (current)
		{
			new_var->value = equal ? ft_strdup(equal + 1) : NULL;
			if (ft_strcmp(new_var->key, current->key) == 0)
			{
				if (new_var->value)
				{
					free(current->value);
					current->value = ft_strdup(equal + 1);
					free(new_var->key);
					free(new_var);
				}
				return (1);
			}
			current = current->next;
		}
	}
	current = g_env;
	while (current->next)
		current = current->next;
	current->next = new_var;
	return (1);
}

int		export_variable(char *variable)
{
	char	**split_variable;
	char	*value;
	t_env	*new_env;
	t_env	*current;

	split_variable = ft_split(variable, '=');
	current = g_env;
	new_env = ft_calloc(1, sizeof(t_env));
	if (split_variable != NULL)
	{
		new_env->key = split_variable[0];
		new_env->value = split_variable[1]; // value ou NULL;
		new_env->next = NULL;
		while (current != NULL)
		{
			if (ft_strcmp(current->key, new_env->key))
			{
				// on remplace current par new_env
				return (1);
			}
			current = current->next;
		}
		// on ajoute new_env à g_env
		current->next = new_env;
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
		// return (add_export_builtin(command));
		i = 0;
		while (command[i])
		{
			export_variable(command[i]);
			i++;
		}
	}
	return (1);
}
