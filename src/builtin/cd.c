/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astriddelcros <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 15:52:16 by astriddel         #+#    #+#             */
/*   Updated: 2020/07/22 23:24:08 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     builtin_cd(char **command)
{
    int     new_dir;
    t_env   *directory;
    char    *oldpwd_value;
    oldpwd_value = getcwd(NULL, 0);
	new_dir = chdir(command[1]);
    directory = g_env;
    if (new_dir == -1)
    {
        printf("ERREUR : %s", strerror(errno));
        return (0);
    }
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
