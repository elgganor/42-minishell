/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 16:20:38 by astriddel         #+#    #+#             */
/*   Updated: 2020/05/28 15:32:19 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(void)
{
	char	*path;
	char	buf[PATH_MAX];

	if ((path = getcwd(buf, PATH_MAX)) == NULL)
		ft_putendl_fd("Impossible to get current path;", 2);
	else
		ft_putendl_fd(path, 1);
	return (1);
}
