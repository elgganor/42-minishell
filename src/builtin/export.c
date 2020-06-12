/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astriddelcros <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 15:40:59 by astriddel         #+#    #+#             */
/*   Updated: 2020/06/12 16:37:13 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

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
