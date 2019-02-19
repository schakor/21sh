/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_termcaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 22:37:56 by schakor           #+#    #+#             */
/*   Updated: 2019/02/19 13:28:05 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void			rl_move_start(t_rl *rl)
{
	size_t		index;

	index = rl->bufvar.len_char + rl->len_prompt;
	while (index > 0)
	{
		ft_putstr(tgetstr("le", NULL));
		index--;
	}
}

void			rl_ctrl_c(t_rl *rl)
{
	cooked_terminal();
	write(1, "\n", 1);
	rl_display_prompt(rl->prompt);
	raw_terminal();
}
