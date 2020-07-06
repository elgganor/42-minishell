/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astriddelcros <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 15:40:59 by astriddel         #+#    #+#             */
/*   Updated: 2020/07/06 16:30:38 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

/*

int     builtin_export(char **command)
{
    char    *equal;
    t_env   *env;

    equal = ft_strchr(command[1], '=');
    env = g_env;
    if  (equal)
        builtin_env();
    else
    {
        builtin_env();
        ft_putstr(command[1]);
    }
    return (1);
}

*/

int     builtin_export(char **command)
{
    t_new   *new;
    t_env   *env;

    env = g_env;
    new = g_new;
    new->next = NULL;
    while (env != NULL)
    {
        if (command[1])
        {
            if (!(new = malloc(sizeof(t_new))))
                return (0);
            if (!(new->cmd = ft_strdup(command[1])))
                return (0);
            while (env->next != NULL)
                env = env->next;
            env->next = new;
        }
        ft_putstr("declare -x ");
        ft_putstr(env->variable);
        ft_putstr("\n");
        env = env->next;
    }
    return (1);
}
