/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:04:47 by schakor           #+#    #+#             */
/*   Updated: 2019/02/01 19:03:41 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

static t_keymap				g_keymap[MODES][KEYMAP_SIZE] = {
	{
		{KEYSTR_CTRL_B, rl_backward_char},
		{KEYSTR_CTRL_F, rl_forward_char},
		{KEYSTR_ESC_B, rl_backward_word},
		{KEYSTR_ESC_F, rl_forward_word},
		{KEYSTR_CTRL_A, rl_beg_of_line},
		{KEYSTR_CTRL_E, rl_end_of_line},
		{KEYSTR_CTRL_X_X, rl_ctrl_x_x},
		{KEYSTR_BACKSPACE, rl_delete_buffer},
		{KEYSTR_DEL, rl_delete_underneath},
		{KEYSTR_CTRL_D, rl_ctrl_d},
		{KEYSTR_CTRL_U, rl_delete_backline},
		{KEYSTR_CTRL_K, rl_delete_endline},
		{KEYSTR_ESC_D, rl_delete_esc_d},
		{KEYSTR_CTRL_W, rl_delete_ctrl_w},
		{KEYSTR_LEFT_ARROW, rl_backward_char},
		{KEYSTR_RIGHT_ARROW, rl_forward_char}
	},
	{
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL}
	},
	{
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL},
		{NULL, NULL}
	}
};

static int					find_key_in_keymap(t_rl *rl)
{
	int						i;
	int						ret_cmp;

	i = 0;
	while (i < KEYMAP_SIZE)
	{
		ret_cmp = ft_memcmp(g_keymap[0][i].key, rl->bufkey, rl->bufkey_index);
		if (ret_cmp == 0 && rl->bufkey_index == ft_strlen(g_keymap[0][i].key))
		{
			rl->keymap_index = i;
			return (PERFECT_KEY_MATCH);
		}
		else if (ret_cmp == 0)
			return (PARTIAL_KEY_MATCH);
		i++;
	}
	return (NO_KEY_MATCH);
}

static void					read_stdin(t_rl *rl)
{
	t_bool					stop;
	int						find_key;

	stop = FALSE;
	rl->keymap_index = -1;
	rl->bufkey_index = 0;
	ft_memset(rl->bufkey, 0, 8);
	while (stop == FALSE)
	{
		if (read(STDIN_FILENO, &rl->bufkey[rl->bufkey_index++], 1) < 0)
			fatal_exit(singleton_shell(), SH_ENOMEM);
		find_key = find_key_in_keymap(rl);
		if (find_key == PERFECT_KEY_MATCH)
			stop = TRUE;
		else if (find_key == NO_KEY_MATCH)
			stop = TRUE;
	}
}

static void					rl_main_work(t_rl *rl)
{
	t_bool					reading;

	reading = TRUE;
	while (reading == TRUE)
	{
		read_stdin(rl);
		if (rl->keymap_index >= 0)
			g_keymap[0][rl->keymap_index].rl_command_func(rl);
		else if (rl->bufkey[0] == ENTER_KEY)
			reading = FALSE;
		else if (rl->keymap_index == -1)
			rl_insert_buffer(rl, rl->bufkey[0]);
		if (rl->len_buf >= rl->rl_tot)
			rl_increase_buffer(rl);
	}
}

static void					rl_init(t_rl *rl)
{
	if (!(rl->buf = (char *)ft_memalloc(BUF_TMP + 1)))
		fatal_exit(singleton_shell(), SH_ENOMEM);
	rl->nb_char = 0;
	rl->i_char = 0;
	rl->i_buf = 0;
	rl->len_buf = 0;
	rl->rl_tot = BUF_TMP;
	ft_memset(rl->bufkey, 0, 8);
	rl->bufkey_index = 0;
}

void						readline(t_shell *sh)
{
	t_rl					rl;

	rl_init(&rl);
	rl_get_prompt(&rl);
	rl_display_prompt(rl.prompt);
	rl_main_work(&rl);
	sh->line = rl.buf;
}
