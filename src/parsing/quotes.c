/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 09:59:26 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/29 18:15:12 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
* @description
*
* @param
* @return
*/

int		handle_state_of_quote(char c, int state_of_quote)
{
	if (c == '"')
	{
		if (state_of_quote == 1)
		{
			state_of_quote = 0;
		}
		else if (state_of_quote == 0)
		{
			state_of_quote = 1;
		}
	}
	else if (c == '\'')
	{
		if (state_of_quote == 2)
		{
			state_of_quote = 0;
		}
		else if (state_of_quote == 0)
		{
			state_of_quote = 2;
		}
	}
	return (state_of_quote);
}

/*
* @description
*
* @param
*/

void	process_quotes(char **command)
{
	int	i;
	int	state_of_quote;

	i= 0;
	state_of_quote = 0;
	while ((*command)[i] != '\0')
	{
		state_of_quote = handle_state_of_quote((*command)[i], state_of_quote);
	
		if ((*command)[i] == '$' && state_of_quote != 2)
		{
			process_env(command, i);
		}
		i++;
	}
	if (state_of_quote != 0)
		ft_puterr("Unclosed quotes");
}
