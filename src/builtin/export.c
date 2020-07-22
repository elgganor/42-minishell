/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 15:40:59 by astriddel         #+#    #+#             */
/*   Updated: 2020/07/22 23:25:23 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int    display_export()
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

int     valid_key(char *key)
{
    int     i;
    i = 0;
    if (!key)
        return (0);
    if (!ft_isalpha(key[0]) && key[0] != '_')
    {
        ft_putstr("key must begin by a letter or _");
        return (0);
    }
    while (key[++i])
    {
        if (!ft_isalpha(key[i]) && !ft_isdigit(key[i]) && key[i] != '_')
        {
            ft_putstr("variable must contain only letters, digits or _");
            return (0);
        }
    }
    return (1);
}

int    add_export_builtin(char **command)
{
    char    *equal;
    t_env   *current;
    t_env   *new_var;
    current = g_env;
    while (current->next)
        current = current->next;
    current->next = ft_calloc(1, sizeof(t_env)); // pour initialiser en meme temps. Equivaut à  current->next = malloc(sizeof(t_env)); new_var = current->next; new_var->next = NULL / current->next->next = NULL 
    new_var = current->next;
    equal = ft_strchr(command[1], '=');
    new_var->key = equal ? ft_substr(command[1], 0, equal - command[1]) : ft_strdup(command[1]);
    if (valid_key(new_var->key) == 1 && ft_strcmp(new_var->key, "_"))
    {
        new_var->value = equal ? ft_strdup(equal + 1) : NULL;
    }
    return (1);
}

int     builtin_export(char **command)
{
    if (!command[1])
    {
        return (display_export());
    }
    if (command[1])
    {
        return (add_export_builtin(command));
    }
    return (1);
}
