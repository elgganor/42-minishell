/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 10:02:56 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/30 12:06:50 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		*init_pipes(int nb_command)
{
	int *pipes;
	int	i;

	if (!(pipes = (int *)malloc(sizeof(int) * (nb_command - 1) * 2)))
	{
		return (NULL);
	}
	i = 0;
	while (i < (nb_command - 1))
	{
		pipe(pipes + (i * 2));
		i++;
	}
	return (pipes);
}

void	close_pipes(int *pipes, int nb_command)
{
	int	j;

	j = 0;
	while (j < (nb_command - 1) * 2)
	{
		close(pipes[j]);
		j++;
	}
}

void	dup_pipe(int *pipes, int len, int nb_command)
{
	if (len == 0)
		dup2(pipes[(len * 2) + 1], 1);
	else if (len == nb_command - 1)
		dup2(pipes[(len - 1) * 2], 0);
	else
	{
		dup2(pipes[(len - 1) * 2], 0);
		dup2(pipes[(len * 2) + 1], 1);
	}
}
