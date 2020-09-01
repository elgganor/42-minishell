/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astriddelcros <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 23:44:45 by astriddel         #+#    #+#             */
/*   Updated: 2020/09/01 01:02:08 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
#include <stdio.h>

static int     exec_unset(char *key)
{
    t_env *env;
    t_env *to_rm;
    env = g_env;
    if (ft_strcmp(env->key, key) == 0)
    {
        g_env = g_env->next;
        free(env->key);
        free(env->value);
        free(env);
        return (1);
    }
    while (env->next) {
        if (ft_strcmp(env->next->key, key) == 0)
		{
			to_rm = env->next;
			env->next = to_rm->next;
            free(to_rm->key);
            free(to_rm->value);
            free(to_rm);
		    return (1);
		}
		else
			env = env->next;
    }
    return (1);
}

int     builtin_unset(char **command)
{
    int i;
    i = 0;
    while (command[++i])
    {
        if (valid_key(command[i]))
            exec_unset(command[i]);
        else
        {
            ft_putstr("unset: ");
            ft_putstr(command[i]);
            ft_putstr(": not a valid identifier\n");
            continue;
        }
    }
    return (1);
}
