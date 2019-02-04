/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_delete_ctrl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <schakor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:29:12 by schakor           #+#    #+#             */
/*   Updated: 2019/02/01 18:49:29 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

static int			get_cur_bytes(t_rl *rl, int index)
{
	int				ret;

	ret = 1;
	if (!(rl->buf[index] & (1 << 7)))
		return (ret);
	index++;
	while ((rl->buf[index] & (1 << 7)) && !(rl->buf[index] & (1 << 6)))
	{
		ret++;
		index++;
	}
	return (ret);
}

void				rl_delete_underneath(t_rl *rl)
{
	size_t			i;
	int				nb_bytes;

	if (rl->buf[rl->i_buf] == '\0')
		return ;
	nb_bytes = get_cur_bytes(rl, rl->i_buf);
	ft_memcpy(rl->buf + rl->i_buf, rl->buf +\
			rl->i_buf + nb_bytes, rl->len_buf - rl->i_buf);
	rl_move_start(rl);
	ft_putstr(tgetstr("cd", NULL));
	rl_display_prompt(rl->prompt);
	rl->len_buf -= nb_bytes;
	write(1, rl->buf, rl->len_buf);
	rl->nb_char--;
	i = rl->nb_char;
	while (i > rl->i_char)
	{
		ft_putstr(tgetstr("le", NULL));
		i--;
	}
}

void				rl_delete_esc_d(t_rl *rl)
{
	(void)rl;
}

void				rl_delete_ctrl_w(t_rl *rl)
{
	(void)rl;
}

void				rl_ctrl_d(t_rl *rl)
{
	if (rl->i_char == 0 && rl->i_buf == 0 && rl->buf[rl->i_buf] == '\0')
		fatal_exit(singleton_shell(), 6);
	else
		rl_delete_underneath(rl);
}
