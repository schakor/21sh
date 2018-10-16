/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 22:37:56 by schakor           #+#    #+#             */
/*   Updated: 2018/10/16 14:47:15 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void			move_start(t_shell *sh)
{
	int		index;
	int		co;

	co = tgetnum("co");
	index = sh->in->buf_i;
	while (index > 1)
	{
		if (index % co == 0)
		{
			while (co > 0)
			{
				ft_putstr(tgetstr("nd", NULL));
				co--;
			}
			ft_putstr(tgetstr("up", NULL));
			co = tgetnum("co");
		}
		else
			ft_putstr(tgetstr("le", NULL));
		index--;
	}
}

void			move_left_cursor(t_shell *sh)
{
	int			co;

	co = tgetnum("co");
	if (sh->in->buf_i > 0)
	{
		if (sh->in->buf_i % co == 0)
		{
			while (co > 0)
			{
				ft_putstr(tgetstr("nd", NULL));
				co--;
			}
			ft_putstr(tgetstr("up", NULL));
		}
		else
			ft_putstr(tgetstr("le", NULL));
		sh->in->buf_i--;
	}
}

void			move_right_cursor(t_shell *sh)
{
	int			co;

	co = tgetnum("co");
	if (sh->in->buf_i < sh->in->bufsize)
	{
		if (sh->in->buf_i % co == 0)
		{
			ft_putstr(tgetstr("cr", NULL));
			ft_putstr(tgetstr("do", NULL));
		}
		else
			ft_putstr(tgetstr("nd", NULL));
	}
}

void			del_one_char(t_shell *sh)
{
	int			co;

	co = tgetnum("co");
	if (sh->in->buf_i > 0)
	{
		ft_putstr(tgetstr("dc", NULL));
		if (sh->in->buf_i % co == 0)
			move_left_cursor(sh);
	}
}
