/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 21:54:11 by schakor           #+#    #+#             */
/*   Updated: 2018/10/23 16:56:17 by schakor          ###   ########.fr       */
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
	delete_until_cursor(sh);
	sh->in->bufsize++;
	write(1, &(sh->in->buffer[sh->in->buf_i]), sh->in->bufsize - sh->in->buf_i);
	sh->in->buf_i++;
}

void			delete_buffer(t_shell *sh)
{
	size_t		i;
	int			co;

	if (sh->in->buf_i > 0)
	{
		i = sh->in->buf_i;
		while (i < sh->in->bufsize - 1)
		{
			sh->in->buffer[i] = sh->in->buffer[i + 1];
			i++;
		}
		co = tgetnum("co");
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
		ft_putstr(tgetstr("dc", NULL));
		sh->in->buf_i--;
		sh->in->bufsize--;
	}
}
