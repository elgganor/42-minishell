/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:40:10 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/27 17:49:15 by mrouabeh         ###   ########.fr       */
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
# include <sys/stat.h>

/*
** STRUCTURES
*/

typedef struct	s_env
{
	char			*variable;
	struct s_env	*next;
}				t_env;

/*
** MINISHELL PROTOTYPES
*/

// char	**g_env;
t_env	*g_env;

void	shell_loop();

void	show_prompt(void);

char	*take_input(void);
char	**list_commands(char *line);
char	**split_command(char *command);
int		is_builtin(char *command);

int		execute_commands(char **commands);
int		run_builtin(char **command);
int		run_system_program(char **command);
int		is_executable(char *bin);
void	get_absolute_path(char **command);
char	*join_path(char *path, char *command);

void	init_env(char **env);
char	*get_env_var(char *var);
void	append_env(char *var);

void	ft_printerror(char *err);

void	free_env(void);
void	free_split(char **str);

/*
** BUILT-INS PROTOTYPES
*/

int		builtin_pwd(void);
int		builtin_cd(void);
#endif
