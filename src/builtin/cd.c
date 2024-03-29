/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astriddelcros <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 15:52:16 by astriddel         #+#    #+#             */
/*   Updated: 2020/08/05 19:22:01 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     builtin_cd(char **command)
{
    int     new_dir;
    t_env   *directory;
    char    *oldpwd_value;
    
    oldpwd_value = getcwd(NULL, 0);
    directory = g_env;
    if (!command[1])
        new_dir = chdir(get_env_var("HOME"));
    else
        new_dir = chdir(command[1]);
    while (directory != NULL)
    {
        if (ft_strcmp(directory->key, "OLDPWD") == 0)
        {
            free(directory->value);
            directory->value = oldpwd_value;
        }
        if (ft_strcmp(directory->key, "PWD") == 0)
        {
            free(directory->value);
            directory->value = getcwd(NULL, 0);
        }
        directory = directory->next;
    }
    return (1);
}
