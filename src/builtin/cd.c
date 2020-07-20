/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astriddelcros <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 15:52:16 by astriddel         #+#    #+#             */
/*   Updated: 2020/07/20 13:50:50 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_cd(char **command)
{
    int     new_dir;
    t_env   *directory;

	new_dir = chdir(command[1]);
    directory = g_env;

    if (new_dir == -1)
    {
        printf("ERREUR : %s", strerror(errno));
        return (0);
    }
    else if (ft_strcmp(directory->key, "OLDPWD") == 0)
    {
        directory->value = getcwd(directory->value, ft_strlen(directory->value));
    }
    else if (ft_strcmp(directory->key, "PWD") == 0)
    {
        chdir(command[1]);
        directory->value = getcwd(directory->value, ft_strlen(directory->value));
    }
	return (1);
}
