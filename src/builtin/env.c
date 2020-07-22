/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 11:56:23 by astriddel         #+#    #+#             */
/*   Updated: 2020/07/22 23:23:45 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	builtin_env()
{
	t_env	*env;
	env = g_env;
	while (env != NULL)
	{
		if (env->value)
		{
			ft_putstr(env->key);
			ft_putstr("=");
			ft_putstr(env->value);
        	ft_putstr("\n");
		}
		env = env->next;
	}
    return (1);
}
