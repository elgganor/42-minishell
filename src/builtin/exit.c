/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:32:32 by astriddel         #+#    #+#             */
/*   Updated: 2020/09/21 11:56:12 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_command(char *num)
{
    int i;

    i = 0;
    if (!num)
        return (0);
    if (num[i] == '-' || num[i] == '+')
        i++;
    while (num[i])
        if (!ft_isdigit(num[i++]))
            return (0);
    return (1);
}

int	builtin_exit(char **command)
{
    int i;

    i = 0;
    while (command[i])
        i++;
    if (i == 1)
        exit(0);
    if (i > 2)
        ft_puterr("too many arguments");
    else
    {
        if (!(check_command(command[1])))
        {
            ft_puterr("must be a digit");
            exit(255);
        }
        exit(ft_atoi(command[1]));
    }
    return (0);
}
