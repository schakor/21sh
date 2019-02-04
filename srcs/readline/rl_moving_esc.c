/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_moving_esc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:25:08 by schakor           #+#    #+#             */
/*   Updated: 2019/02/01 18:45:53 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void		rl_backward_word(t_rl *rl)
{
	if (rl->i_char == 0)
		return ;
	if (!rl->buf[rl->i_buf] || (rl->i_buf - 1 > 0 &&
	(rl->buf[rl->i_buf - 1] == ' ' || rl->buf[rl->i_buf - 1] == '\n')))
	{
		rl_backward_char(rl);
		while (rl->i_buf > 0)
		{
			if (rl->buf[rl->i_buf] != ' ' && rl->buf[rl->i_buf] != '\n')
				break ;
			rl_backward_char(rl);
		}
	}
	while (rl->i_buf)
	{
		if (rl->buf[rl->i_buf - 1] == ' ' || rl->buf[rl->i_buf - 1] == '\n')
			break ;
		else
			rl_backward_char(rl);
	}
}

void		rl_forward_word(t_rl *rl)
{
	if (!rl->buf[rl->i_buf])
		return ;
	if (rl->buf[rl->i_buf] && (rl->buf[rl->i_buf + 1] == '\n' ||
	rl->buf[rl->i_buf] == ' '))
	{
		rl_forward_char(rl);
		while (rl->buf[rl->i_buf])
		{
			if (rl->buf[rl->i_buf] != ' ' && rl->buf[rl->i_buf] != '\n')
				break ;
			rl_forward_char(rl);
		}
	}
	while (rl->buf[rl->i_buf])
	{
		if (rl->buf[rl->i_buf] == ' ' || rl->buf[rl->i_buf] == '\n')
			break ;
		else
			rl_forward_char(rl);
	}
}
