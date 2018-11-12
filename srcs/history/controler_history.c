/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controler_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:33:25 by khsadira          #+#    #+#             */
/*   Updated: 2018/11/12 16:48:16 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void	switch_history(t_shell *sh)
{
	t_history	*head;
	int			i;

	i = 0;
	head = sh->history;
	while (i < sh->history_save && sh->history->bfr)
	{
		sh->history = sh->history->bfr;
		i++;
	}
	ft_strdel(&sh->history->buffer);
	sh->history->buffer = ft_strdup(sh->in->buffer);
	sh->history->bufsize = sh->in->bufsize;
	sh->history = head;
}

int		listlen(t_history *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->bfr;
	}
	return (i);
}

void	print_history(t_shell *sh)
{
	move_start(sh);
	ft_putstr(tgetstr("cd", NULL));
	display_prompt(sh);
	ft_strdel(&sh->in->buffer);
	sh->in->buffer = ft_strdup(sh->history->buffer);
	sh->in->bufsize = sh->history->bufsize;
	sh->in->buf_i = sh->history->bufsize;
	write(1, sh->in->buffer, sh->in->bufsize);
}

void	add_history(t_shell *sh)
{
	t_history	*new_ele;

	new_ele = new_hist(ft_strdup(sh->in->buffer), sh->in->bufsize);
	sh->history = add_hist(sh->history, new_ele);
}
