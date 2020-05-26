/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:40:10 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/26 19:23:18 by mrouabeh         ###   ########.fr       */
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
# include <signal.h>

/*
** MINISHELL PROTOTYPES
*/

char	**g_env;

void	shell_loop();
void	show_prompt(void);
char	**list_commands(char *line);
void	free_split(char **str);
int		execute_commands(char **commands);
int		is_builtin(char *command);
char	**split_command(char *command);
int		run_builtin(char **command);
int		run_system_program(char **command);
char	*take_input(void);
void	ft_printerror(char *err);
char	*get_env_var(char *var);
void	init_env(char **env);
int		env_len(char **env);
void	get_absolute_path(char **command);

/*
** BUILT-INS PROTOTYPES
*/

int		builtin_pwd(void);
int		builtin_cd(void);
#endif
