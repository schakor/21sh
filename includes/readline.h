/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:28:17 by schakor           #+#    #+#             */
/*   Updated: 2019/01/30 14:36:32 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef READLINE_H
# define READLINE_H

# include "rl_defines.h"
# include "rl_typedefs.h"

/*
**		readline utility that allows the user to edit the command line
*/

struct					s_keymap
{
	char				*key;
	t_rl_command_func	rl_command_func;
};

struct					s_rl
{
	char				*buf;
	char				*prompt;
	size_t				nb_char;
	size_t				i_char;
	size_t				len_prompt;
	size_t				i_buf;
	size_t				len_buf;
	size_t				rl_tot;
	t_uint8				bufkey[8];
	size_t				bufkey_index;
	int					keymap_index;
};

void					readline(t_shell *sh);
void					rl_get_prompt(t_rl *rl);
void					rl_display_prompt(const char *prompt);
void					rl_insert_buffer(t_rl *rl, unsigned char c);
void					rl_increase_buffer(t_rl *rl);
void					rl_move_start(t_rl *rl);
void					rl_backward_char(t_rl *rl);
void					rl_forward_char(t_rl *rl);
void					rl_delete_buffer(t_rl *rl);
int						get_nb_bytes(t_rl *rl, int index);
void					rl_backward_word(t_rl *rl);
void					rl_forward_word(t_rl *rl);
void					rl_beg_of_line(t_rl *rl);
void					rl_end_of_line(t_rl *rl);
void					rl_ctrl_x_x(t_rl *rl);
void					rl_delete_underneath(t_rl *rl);
void					rl_delete_backline(t_rl *rl);
void					rl_delete_endline(t_rl *rl);
void					rl_delete_esc_d(t_rl *rl);
void					rl_delete_ctrl_w(t_rl *rl);
void					rl_ctrl_d(t_rl *rl);

#endif
