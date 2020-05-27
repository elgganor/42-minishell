/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 17:17:49 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/27 17:46:19 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_split(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		free(str[len++]);
	free(str);
}

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
	free(g_env);
	g_env = NULL;
}
