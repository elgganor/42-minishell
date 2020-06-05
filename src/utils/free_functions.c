/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 17:17:49 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/06/03 10:02:23 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** @description
**
** @param
** @return
*/

void	free_split(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		free(str[len++]);
	free(str);
}

/*
** @description
**
** @param
** @return
*/

void	free_env(void)
{
	t_env *next;
	t_env *current;

	next = g_env;
	while (next != NULL)
	{
		current = next;
		next = current->next;
		free(current->variable);
		free(current);
		current = NULL;
	}
}
