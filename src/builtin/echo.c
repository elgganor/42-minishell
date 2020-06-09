/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astriddelcros <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 18:53:43 by astriddel         #+#    #+#             */
/*   Updated: 2020/06/10 00:23:07 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int builtin_echo(char **command)
{
  int i;

  i = 1;
  while (command[i] != NULL)
  {
    write(1, command[i], ft_strlen(command[i]));
    i++;
  }
  return (1);
}
