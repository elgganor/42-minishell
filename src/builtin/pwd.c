/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astriddelcros <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 16:20:38 by astriddel         #+#    #+#             */
/*   Updated: 2020/05/24 22:41:30 by astriddel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	buitlin_pwd(void)
{
	char	*path;
	char	buf[PATH_MAX + 1];

	path = getcwd(buf, PATH_MAX);
	ft_putstr(path);
	return (0);
}
