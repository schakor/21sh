/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 21:54:11 by schakor           #+#    #+#             */
/*   Updated: 2018/10/16 11:55:51 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void			insert_buffer(t_shell *sh, char c)
{
	size_t		i;

	i = sh->in->bufsize;
	while (i > sh->in->buf_i)
	{
		sh->in->buffer[i + 1] = sh->in->buffer[i];
		i--;
	}
	sh->in->buffer[sh->in->buf_i++] = c;
	sh->in->bufsize += 1;
	move_start(sh);
	write(1, sh->in->buffer, sh->in->bufsize);
}
