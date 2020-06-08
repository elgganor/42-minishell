/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 13:09:13 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/06/08 13:24:07 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** @description
**
** @param
** @return
*/

static int is_redirection(char *command)
{
	if (!ft_strcmp(command, ">") || !ft_strcmp(command, ">>")
		|| !ft_strcmp(command, "<"))
		return (1);
	return (0);
}

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
		if (is_redirection(command[i]) && command[i + 1] != NULL)
			count++;
		i++;
	}
	return (count);
}

/*
** clear every redirection within the command
**
** @param char***: adress of the command
** @return bool: state of the instruction
*/

int		clear_command_of_redirection(char ***command)
{
	int		i;
	int		j;
	int		tmp_len;
	char	**tmp;

	tmp_len = ft_arrlen(*command) + 1 - count_redirection(*command) * 2;
	i = 0;
	j = 0;
	if (!(tmp = (char **)malloc(sizeof(char *) * tmp_len)))
		return (0);
	while ((*command)[i] != NULL)
	{
		if (is_redirection((*command)[i]) && (*command)[i + 1] != NULL)
			i++;
		else
			tmp[j++] = ft_strdup((*command)[i]);
		i++;
	}
	tmp[j] = NULL;
	free_split(*command);
	*command = tmp;
	return (1);
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
