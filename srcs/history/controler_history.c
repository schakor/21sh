/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controler_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:33:25 by khsadira          #+#    #+#             */
/*   Updated: 2018/10/24 16:34:05 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

static void	up_history_first(t_shell *sh)
{
	ft_putstr("la\n");
	delete_until_cursor(sh, 0);
	ft_strdel(&sh->in->buffer);
	sh->in->buffer = ft_strdup(sh->history->buffer);
	sh->in->bufsize = sh->history->bufsize;
	sh->in->buf_i = sh->history->bufsize;
	write(1, sh->in->buffer, sh->in->bufsize);
	if (sh->history->bfr)
		sh->history = sh->history->bfr;
}

void ft_printlist(t_history *list)
{
	ft_putendl("");
	while (list)
	{
		ft_putendl(list->buffer);
		if (list->bfr)
		list = list->bfr;
	}
}

void	up_history(t_shell *sh)
{
	ft_printlist(sh->history);
	move_end(sh);
	if (sh->in->buf_i > 0 && !sh->history)
		return ;
	if (!sh->history)
		return ;
	if (sh->history->bfr == NULL)
		return ;
	if (!sh->history->next)
		up_history_first(sh);
	else
	{
		/*delete_until_cursor(sh, 0);
		  ft_strdel(&sh->in->buffer);
		  sh->in->buffer = ft_strdup(sh->history->buffer);
		  sh->in->bufsize = sh->history->bufsize;
		  sh->in->buf_i = sh->history->bufsize;
		  write(1, sh->in->buffer, sh->in->bufsize);*/
	}
}

void	down_history(t_shell *sh)
{
	move_end(sh);
	if (!(sh->history && sh->history->next))
		return ;
	delete_until_cursor(sh, 0);
	ft_strdel(&sh->in->buffer);
	if (!(sh->history && sh->history->next))
		return ;
	sh->in->buffer = ft_strdup(sh->history->buffer);
	sh->in->buf_i = sh->history->bufsize;
	sh->in->bufsize = sh->history->bufsize;
	if (sh->history->next && sh->history->next->next)
		sh->history = sh->history->next->next;
	write(1, sh->in->buffer, sh->in->bufsize);
}

void	add_history(t_shell *sh)
{
	t_history	*new_ele;

	new_ele = new_hist(ft_strdup(sh->in->buffer), sh->in->bufsize);
	sh->history = add_hist(sh->history, new_ele);
}
