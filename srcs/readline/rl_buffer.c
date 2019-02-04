/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 22:13:26 by schakor           #+#    #+#             */
/*   Updated: 2019/02/04 14:20:52 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void				rl_increase_buffer(t_rl *rl)
{
	char			*ret;

	if (!(ret = (char *)ft_memalloc(rl->rl_tot + BUF_TMP + 1)))
		fatal_exit(singleton_shell(), SH_ENOMEM);
	ft_memcpy(ret, rl->buf, rl->len_buf);
	rl->rl_tot += BUF_TMP;
	ft_strdel(&(rl->buf));
	rl->buf = ret;
}

void				rl_insert_buffer(t_rl *rl, unsigned char c)
{
	size_t			i;

	if (ft_isnotprint(c))
		return ;
	if (ft_first_char_unicode(c))
	{
		rl->nb_char++;
		rl->i_char++;
	}
	i = rl->len_buf;
	ft_memmove(rl->buf + rl->i_buf + 1, rl->buf\
			+ rl->i_buf, i - rl->i_buf);
	rl->buf[rl->i_buf] = c;
	rl_move_start(rl);
	ft_putstr(tgetstr("cd", NULL));
	rl_display_prompt(rl->prompt);
	rl->len_buf++;
	write(STDOUT_FILENO, rl->buf, rl->len_buf);
	i = rl->nb_char;
	rl->i_buf++;
	while (i > rl->i_char)
	{
		ft_putstr(tgetstr("le", NULL));
		i--;
	}
}

static void			rl_delete_buffer_multi_bytes(t_rl *rl, int nb_bytes)
{
	size_t			i;

	ft_memcpy(rl->buf + rl->i_buf - nb_bytes, rl->buf +\
			rl->i_buf, rl->len_buf - rl->i_buf + nb_bytes);
	rl_move_start(rl);
	ft_putstr(tgetstr("cd", NULL));
	rl_display_prompt(rl->prompt);
	rl->len_buf -= nb_bytes;
	write(1, rl->buf, rl->len_buf);
	i = rl->nb_char;
	rl->i_buf -= nb_bytes;
	while (i > rl->i_char)
	{
		ft_putstr(tgetstr("le", NULL));
		i--;
	}
}

int					get_nb_bytes(t_rl *rl, int index)
{
	int				ret;

	ret = 1;
	if (!(rl->buf[index] & (1 << 7)))
		return (ret);
	while ((rl->buf[index] & (1 << 7)) && !(rl->buf[index] & (1 << 6)))
	{
		ret += 1;
		index--;
	}
	return (ret);
}

void				rl_delete_buffer(t_rl *rl)
{
	int				nb_bytes;

	if (rl->i_char > 0)
	{
		nb_bytes = get_nb_bytes(rl, rl->i_buf - 1);
		rl_delete_buffer_multi_bytes(rl, nb_bytes);
		rl->i_char--;
		rl->nb_char--;
	}
}
