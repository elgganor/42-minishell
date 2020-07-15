/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 11:56:23 by astriddel         #+#    #+#             */
/*   Updated: 2020/07/15 09:36:48 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	builtin_env()
{
	t_env	*env;

	env = g_env;
	while (env != NULL)
	{
		ft_putstr(env->key);
		ft_putstr("=");
		ft_putstr(env->value);
        ft_putstr("\n");
		env = env->next;
	}
    return (1);
}
