/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 09:59:26 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/28 10:39:09 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int has_quotes(char *command)
{
	int len;

	len = 0;
	while (command[len])
	{
		if (ft_isquote(command[len]))
			return (command[len] == 34 ? 1 : 2);
		len++;
	}
	return (0);
}

int		check_closed_quotes(char *command)
{
	int len;
	int nb_simple_quotes;
	int nb_double_quotes;

	len = 0;
	nb_simple_quotes = 0;
	nb_double_quotes = 0;
	while (command[len])
	{
		if (ft_isquote(command[len]))
		{
			if (command[len] == 34)
				nb_double_quotes++;
			else
				nb_simple_quotes++;
		}
		len++;
	}
	return (nb_double_quotes % 2 == 0 && nb_simple_quotes % 2 == 0);
}

void	parse_quotes(char *command)
{
	int	quote_type;

	if ((quote_type = has_quotes(command)) != 0)
	{
		if (!check_closed_quotes(command))
			ft_puterr('Unclosed quotes');
		if (quote_type == 1) // double quotes
		{
			// on substitue les var d'env
		}
		else // simple quotes
		{
			// on ne substitue pas les var d'env
		}
	}
	else
	{
		// parse_env
	}
}
