/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astriddelcros <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 15:52:16 by astriddel         #+#    #+#             */
/*   Updated: 2020/06/09 18:14:53 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_cd(char **command)
{
	int	new_dir;

	new_dir = chdir(command[1]);
  if (new_dir == -1)
  {
    printf("ERREUR : %s", strerror(errno));
		return (0);
  }
	return (1);
}
