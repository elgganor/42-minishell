/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astriddelcros <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 18:53:43 by astriddel         #+#    #+#             */
/*   Updated: 2020/06/23 17:46:31 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int     builtin_echo(char **command)
{
    int i;

    i = 1;
    while (command[i] != NULL)
    {
        if (command[i + 1] == NULL)
        {
            ft_putstr(command[i]);
            return (1);
        }
        ft_putstr(command[i]);
        write(1, " ", 1);
        i++;
    }
    return (1);
}
