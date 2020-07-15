/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:40:10 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/07/15 10:15:26 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SYSPROG 0
# define BUILTIN 1

# define EXIT_STATUS 0
# define SUCCESS_STATUS 1
# define FAILURE_STATUS 2

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
# include <errno.h>

/*
**----------------------------------------**
** STRUCTURES
**----------------------------------------**
*/

typedef struct	s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}				t_env;

/*
**----------------------------------------**
** GLOBAL VARIABLES
**----------------------------------------**
*/

t_env			*g_env;

/*
**----------------------------------------**
** MINISHELL PROTOTYPES
**----------------------------------------**
*/

void			shell_loop();

/*
**----------------------------------------**
** EXECUTION PROTOTYPES
**----------------------------------------**
*/

int				execute_commands(char *commands);
int				process_commands(char **commands);
int				execute_piped_commands(char **piped_commands);
int				run_builtin(char **command);
int				run_system_program(char **command);
int				is_executable(char *bin);
void			get_absolute_path(char **command);
char			*join_path(char *path, char *command);

/*
**----------------------------------------**
** INITIALISATION PROTOTYPES
**----------------------------------------**
*/

void			show_prompt(void);
void			init_env(char **env);
char			*get_env_var(char *key);
void			append_env(char *var);

/*
**----------------------------------------**
** PARSING PROTOTYPES
**----------------------------------------**
*/

char			*take_input(void);
char			**split_input(char *input);
char			**split_command(char *command);
int				is_builtin(char *command);
int				redirection(char ***command);
int				redirect_output(char **command, int pos, int type);
int				redirect_input(char **command, int pos);
void			clear_redirection(void);
void			parse_env_var(char **command);
char			**parse_pipe(char *command);

/*
**----------------------------------------**
** UTILS PROTOTYPES
**----------------------------------------**
*/

void			ft_puterr(char *err);
void			free_env(void);
void			free_split(char **str);
int				clear_command_of_redirection(char ***command);
void			close_pipes(int *pipes, int nb_command);
void			dup_pipe(int *pipes, int len, int nb_command);
int				*init_pipes(int nb_command);

/*
**----------------------------------------**
** BUILT-INS PROTOTYPES
**----------------------------------------**
*/

int				builtin_pwd(void);
int				builtin_cd(char **command);
int				builtin_env(void);
int				builtin_exit(void);
int				builtin_echo(char **command);
int				builtin_export(char **command);

#endif
