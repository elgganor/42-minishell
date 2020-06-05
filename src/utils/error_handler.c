/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:44:48 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/06/03 10:02:29 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** @description
**
** @param
** @return
*/

void	ft_puterr(char *err)
{
	ft_putstr_fd("Shell: ", 2);
	ft_putendl_fd(err, 2);
}
