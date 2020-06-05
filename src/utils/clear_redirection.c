/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 13:09:13 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/06/04 15:42:25 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** @description
**
** @param
** @return
*/

static int	count_redirection(char **command)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (command[i] != NULL)
	{
		if (!ft_strcmp(command[i], ">") && command[i + 1] != NULL)
			count++;
		else if (!ft_strcmp(command[i], ">>") && command[i + 1] != NULL)
			count++;
		else if (!ft_strcmp(command[i], "<") && command[i + 1] != NULL)
			count++;
		i++;
	}
	return (count);
}

/*
** @description
**
** @param
** @return
*/

char		**clear_command_of_redirection(char **command)
{
	int		i;
	int		j;
	int		tmp_len;
	char	**tmp;

	tmp_len = ft_arrlen(command) - 2 * count_redirection(command) + 1;
	if (!(tmp = (char **)malloc(sizeof(char *) * tmp_len)))
		return (NULL);
	i = 0;
	j = 0;
	while (command[i] != NULL)
	{
		if ((!ft_strcmp(command[i], ">") || !ft_strcmp(command[i], ">>")
			|| !ft_strcmp(command[i], "<")) && command[i + 1] != NULL)
			i++;
		else
			tmp[j++] = ft_strdup(command[i]);
		i++;
	}
	tmp[j] = NULL;
	free_split(command);
	return (tmp);
}

/*
** @description
**
** @param
** @return
*/

void		clear_redirection(void)
{
	int	stdout;
	int	stdin;

	stdout = open("/dev/tty", O_RDWR);
	dup2(stdout, 1);
	stdin = open("/dev/tty", O_RDWR);
	dup2(stdin, 0);
}
