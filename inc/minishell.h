/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:40:10 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/25 22:14:34 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SYSPROG 0
# define BUILTIN 1

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include <limits.h>

void	shell_loop(void);
void	show_prompt(void);
char	**list_commands(char *line);
void	free_split(char **str);
int		execute_commands(char **commands);
int		check_command_type(char *command);
char	**split_command(char *command);
int		run_builtin(char **command);
int		run_system_program(char **command);
int		builtin_pwd(void);
int		builtin_cd(void);
#endif
