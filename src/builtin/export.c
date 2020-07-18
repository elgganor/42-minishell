/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astriddelcros <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 15:40:59 by astriddel         #+#    #+#             */
/*   Updated: 2020/07/18 23:20:19 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int    display_export(t_env *new)
{
/*    
    char    *equal;
    char    *last_var;

    equal = ft_strchr(&command[1], '=');
    new = g_env;
    last_var = "/usr/bin/env";

    while (new != NULL)
    {
        if (!equal)
        {
            ft_putstr("declare -x ");
            ft_putstr(new->key);
            ft_putstr("\n");
            new = new->next;
        }
        if (ft_strcmp(last_var, new->value) == 0)
        {
            last_var = "\0";
            ft_putstr("declare -x ");
            ft_putstr(new->key);
            ft_putstr("=");
            ft_putstr(new->value);
            ft_putstr("\n");
            new = new->next;
        }
    }
    return (1);
*/
    new = g_env;
    while (new != NULL)
    {
        ft_putstr("declare -x ");
        ft_putstr(new->key);
        ft_putstr("=");
        ft_putstr(new->value);
        ft_putstr("\n");
        new = new->next;
    }
    return (0);
}

int     valid_key()
{
    char    *key;
    int     i;

    key = NULL;
    i = 0;
    if (!key)
        return (0);
    if (!ft_isalpha(key[0] || !ft_strncmp(&key[0], "_", 2)))
    {
        ft_putstr("key must begin by a letter or _");
        return (0);
    }
    while (key[i++])
    {
        if (!ft_isalpha(key[i]) || !ft_isdigit(key[i]) || !ft_strncmp(&key[i], "_", 2))
        {
            ft_putstr("variable must contain only letters, digits or _");
            return (0);
        }
    }
    return (1);
}

int    add_export_builtin(char *command, t_env *new)
{
    char    *equal;

    new = g_env;
    equal = ft_strchr(&command[1], '=');
    if (valid_key() == 1)
    {
        new->key = equal ? ft_substr(&command[1], 0, equal - &command[1]) : ft_strdup(&command[1]);
        new->value = equal ? ft_strdup(equal) : NULL;
    }
    return (0);
}

int     builtin_export(char *command, t_env *new)
{
    if (!command[1])
    {
        return (display_export(new));
    }
    if (command[1])
    {
        return (add_export_builtin(&command[1], new));
    }
    return (0);
}
