/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 21:54:11 by schakor           #+#    #+#             */
/*   Updated: 2018/10/24 13:44:51 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void			insert_buffer(t_shell *sh, char c)
{
	size_t		i;

	i = sh->in->bufsize;
	ft_memmove(sh->in->buffer + sh->in->buf_i + 1, sh->in->buffer + sh->in->buf_i, i - sh->in->buf_i);
	sh->in->buffer[sh->in->buf_i] = c;
	move_end(sh);
	delete_until_cursor(sh, sh->in->buf_i);
	sh->in->bufsize++;
	write(1, &(sh->in->buffer[sh->in->buf_i]), sh->in->bufsize - sh->in->buf_i);
	i = sh->in->bufsize;
	while (i > sh->in->buf_i + 1)
		move_left_cursor(sh, &i);
	sh->in->buf_i++;
}

void			delete_buffer(t_shell *sh)
{
	size_t			i;
	struct winsize	w;

	if (sh->in->buf_i > 0)
	{
		sh->in->buffer[sh->in->bufsize - 1] = '\0';
		i = sh->in->buf_i - 1;
		while (i < sh->in->bufsize)
		{
			sh->in->buffer[i] = sh->in->buffer[i + 1];
			i++;
		}
		ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
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
		ft_putstr(tgetstr("dc", NULL));
		sh->in->buf_i--;
		sh->in->bufsize--;
	}
}
