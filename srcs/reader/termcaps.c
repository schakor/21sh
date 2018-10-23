/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 22:37:56 by schakor           #+#    #+#             */
/*   Updated: 2018/10/23 16:44:40 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void			move_start(t_shell *sh)
{
	int				index;
	struct winsize	w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	index = sh->in->buf_i;
	while (index > 1)
	{
		if (index % w.ws_col == 0)
		{
			while (w.ws_col > 0)
			{
				ft_putstr(tgetstr("nd", NULL));
				w.ws_col--;
			}
			ft_putstr(tgetstr("up", NULL));
			ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
		}
		else
			ft_putstr(tgetstr("le", NULL));
		index--;
	}
}

void			move_left_cursor(t_shell *sh)
{
	struct winsize	w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	if (sh->in->buf_i > 0)
	{
		if (sh->in->buf_i % w.ws_col == 0)
		{
			while (w.ws_col > 0)
			{
				ft_putstr(tgetstr("nd", NULL));
				w.ws_col--;
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
	struct winsize w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	if (sh->in->buf_i < sh->in->bufsize)
	{
		if (sh->in->buf_i != 0 && sh->in->buf_i % w.ws_col == 0)
		{
			ft_putstr(tgetstr("cr", NULL));
			ft_putstr(tgetstr("do", NULL));
		}
		else
			ft_putstr(tgetstr("nd", NULL));
		sh->in->buf_i++;
	}
}

void			move_end(t_shell *sh)
{
	size_t			i;

	i = sh->in->buf_i;
	while (i < sh->in->bufsize)
	{
		move_right_cursor(sh);
		i++;
	}
}

void			delete_until_cursor(t_shell *sh)
{
	size_t			i;

	i = sh->in->bufsize;
	while (i > sh->in->buf_i)
	{
		move_left_cursor(sh);
		ft_putstr(tgetstr("dc", NULL));
		i--;
	}
}
