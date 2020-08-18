/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 09:59:26 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/08/18 07:56:14 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*trim_quotes(char *tmp, char q)
{
	char	set[3];

	set[0] = ' ';
	set[1] = q;
	set[2] = '\0';
	return (ft_strtrim(tmp, set));
}

char	*process_quotes(char **split, int *i, char q)
{
	int		j;
	char	*join;
	char	*tmp;

	j = *i;
	tmp = ft_strdup(split[j]);
	if (!ft_endwith(split[j], q))
	{
		j++;
		while (split[j] != NULL)
		{
			tmp = ft_join_and_free(tmp, " ");
			tmp = ft_join_and_free(tmp, split[j]);
			if (ft_endwith(split[j], q))
				break;
			j++;
		}
	}
	*i = j + 1;
	join = trim_quotes(tmp, q);
	free(tmp);
	return (join);
}

char	**join_quotes(char **split)
{
	int		i;
	int		j;
	char	**dest;

	i = 0;
	j = 0;
	if (!(dest = (char **)malloc(sizeof(char *) * (ft_arrlen(split) + 1))))
		return (NULL);
	while (split[i] != NULL)
	{
		if (ft_startwith(split[i], '"'))
			dest[j++] = process_quotes(split, &i, '"');
		else if (ft_startwith(split[i], '\''))
			dest[j++] = process_quotes(split, &i, '\'');
		else
			dest[j++] = ft_strdup(split[i++]);
	}
	dest[j] = NULL;
	while (j++ < ft_arrlen(split))
		free(dest[j]);
	return (dest);
}
