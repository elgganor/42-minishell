/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astriddelcros <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 11:56:23 by astriddel         #+#    #+#             */
/*   Updated: 2020/05/28 14:30:16 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	builtin_env()
{
	t_env	*env;

	env = g_env;
	while (env != NULL)
	{
		ft_putstr(env->variable);
		env = env->next;
	}
}
