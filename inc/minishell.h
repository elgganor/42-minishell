/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:40:10 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/08/26 12:20:00 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>
# include <get_next_line.h>
# include <limits.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <errno.h>

# define SYSPROG 0
# define BUILTIN 1

# define EXIT_STATUS 0
# define SUCCESS_STATUS 1
# define FAILURE_STATUS 2

# define OUT_RIGHT (S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH)
# define OUT_MOD (O_CREAT | O_RDWR)
# define APPEND_OUT_MOD (O_CREAT | O_WRONLY | O_APPEND)

/*
** -------------------------------------------------------------------------- **
** STRUCTURES
** -------------------------------------------------------------------------- **
*/

typedef struct	s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}				t_env;

/*
** -------------------------------------------------------------------------- **
** GLOBAL VARIABLES
** -------------------------------------------------------------------------- **
*/

t_env			*g_env;
int				g_status;

/*
** -------------------------------------------------------------------------- **
** MINISHELL PROTOTYPES
** -------------------------------------------------------------------------- **
*/

void			shell_loop();

/*
** -------------------------------------------------------------------------- **
** EXECUTION PROTOTYPES
** -------------------------------------------------------------------------- **
*/

int				execute_commands(char *commands);
int				process_commands(char **commands);
int				execute_piped_commands(char **piped_commands);
int				run_builtin(char **command);
int				run_system_program(char **command);
int				is_executable(char *bin);
void			get_absolute_path(char **command);
char			*join_path(char *path, char *command);
void			reset_redirection(void);

/*
** -------------------------------------------------------------------------- **
** INITIALISATION PROTOTYPES
** -------------------------------------------------------------------------- **
*/

void			show_prompt(void);
void			init_env(char **env);
char			*get_env_var(char *key);
void			append_env(char *var);

/*
** -------------------------------------------------------------------------- **
** PARSING PROTOTYPES
** -------------------------------------------------------------------------- **
*/

char			*take_input(void);
char			**split_input(char *input);
char			**split_command(char *command);
int				is_builtin(char *command);
int				redirection(char ***command);
int				redirect_output(char **command, int pos);
int				append_redirect_output(char **command, int pos);
int				redirect_input(char **command, int pos);
void			parse_env_var(char **command);
char			**parse_pipe(char *command);
void			parse_quotes(char *command);
char			*extract_var_key(char *command);
void			process_quotes_and_env(char **command);
char			*get_key(char *command, int start, int end);
void			substitute_env(char **command, int start);
int				handle_state_of_quote(char c, int state_of_quote);
void			process_env(char **command);
int				handle_state_of_quotes(char *str, int state_of_quote);
char			**join_quotes(char **split);
char			*trim_quotes(char *tmp, char q);
char			*process_quotes(char **split, int *i, char c);

/*
** -------------------------------------------------------------------------- **
** UTILS PROTOTYPES
** -------------------------------------------------------------------------- **
*/

void			ft_puterr(char *err);
void			free_env(void);
void			free_split(char **str);
int				clear_command_of_redirection(char ***command);
void			close_pipes(int *pipes, int nb_command);
void			dup_pipe(int *pipes, int len, int nb_command);
int				*init_pipes(int nb_command);

/*
** -------------------------------------------------------------------------- **
** BUILT-INS PROTOTYPES
** -------------------------------------------------------------------------- **
*/

int				builtin_pwd(void);
int				builtin_cd(char **command);
int				builtin_env(void);
int				builtin_exit(void);
int				builtin_echo(char **command);
int				builtin_export(char **command);
int				display_export();
int				valid_key();
int				add_export_builtin(char **command);
int				builtin_unset(char **command);

#endif
