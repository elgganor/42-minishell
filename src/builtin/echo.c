/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 18:53:43 by astriddel         #+#    #+#             */
/*   Updated: 2020/07/24 11:24:25 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int     builtin_echo(char **command)
{
    int i;

    i = 1;
    while (command[i] != NULL)
    {
        ft_putstr(command[i]);
        if (command[i + 1] != NULL)
            ft_putchar(' ');
        i++;
    }
    ft_putchar('\n');
    return (1);
}
