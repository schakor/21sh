/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twenty_one_sh.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 13:06:41 by schakor           #+#    #+#             */
/*   Updated: 2018/10/24 13:46:34 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWENTY_ONE_SH_H
# define TWENTY_ONE_SH_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include "../libft/includes/libft.h"
# include <signal.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>

# define BUF_TMP		32
# define ENTER_KEY		10
# define DELETE_KEY		127
# define HOME_KEY		4741915
# define END_KEY		4610843
# define LEFT_KEY		4479771
# define RIGHT_KEY		4414235
# define UP_KEY			4283163
# define DOWN_KEY		4283163

typedef struct termios	t_termios;

typedef struct			s_env_lst
{
	char				*name;
	char				*value;
	struct s_env_lst	*next;
}						t_env_lst;

typedef struct			s_cmd_lst
{
	char				**cmds;
	int					cmds_count;
	struct s_cmd		*next;
}						t_cmd_lst;

typedef struct			s_input
{
	char				*buffer;
	size_t				buf_i;
	size_t				bufsize;
	size_t				buf_tmp;
}						t_input;

typedef struct			s_shell
{
	char				**env;
	t_env_lst			*env_lst;
	t_input				*in;
	char				**paths;
	t_cmd_lst			*cmd;
	t_cmd_lst			*head;
	t_termios			cooked_tio;
	t_termios			raw_tio;
}						t_shell;

/*
**	ENVIRONNEMENT FUNCTIONS
*/

t_env_lst				*addlast_env_lst(t_env_lst *head, t_env_lst *new);
t_env_lst				*envarr_2_envlst(char **env);
char					*get_env_val(t_env_lst *env_lst, char *name);
void					push_env(t_env_lst **env_lst, char *name, char *value);

/*
**	TERMINAL / SHELL FUNCTIONS
*/

t_shell					*init_shell(int ac, char **av, char **env);
void					init_terminal(t_shell *sh);

/*
**	READING FUNCTIONS
*/

void					read_raw_mode(t_shell *sh);
void					insert_buffer(t_shell *sh, char c);
void					increase_buffer(t_shell *sh);
void					delete_buffer(t_shell *sh);
void					display_prompt(void);

/*
**	TERMCAPS FUNCTIONS
*/

void					move_start(t_shell *sh);
void					move_left_cursor(t_shell *sh, size_t *index);
void					move_right_cursor(t_shell *sh, size_t *index);
void					delete_until_cursor(t_shell *sh, size_t index);
void					move_end(t_shell *sh);

/*
**	HISTORY FUNCTIONS
*/

void					up_history(t_shell sh);
void					down_history(t_shell sh);
void					add_history(t_shell sh);
t_history				*new_hist(char *buffer, int bufsize);
t_history				*add_hist(t_history *list, t_history *new_hist);

#endif
