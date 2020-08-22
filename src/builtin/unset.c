/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astriddelcros <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 23:44:45 by astriddel         #+#    #+#             */
/*   Updated: 2020/08/22 17:16:53 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int     builtin_unset(char **command)
{
    t_env   *env;
    t_env *to_rm;

    env = g_env;
    if (!valid_key(command[1]))
    {
        ft_putstr("unset: ");
        ft_putstr(command[1]);
        ft_putstr(": not a valid identifier\n");
        return (1);
    }
    while (env != NULL)
    {
        if (ft_strcmp(command[1], env->next->key) == 0)
        {
            to_rm = env->next;
            env->next = to_rm->next;
            free(to_rm->key);
            free(to_rm->value);
            free(to_rm);
        }
        env = env->next;
    }
    return (1);
}
