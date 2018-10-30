/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:38:20 by schakor           #+#    #+#             */
/*   Updated: 2018/10/30 13:26:17 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void	up_history_here(t_shell *sh)
{
	int			i;
	t_history	*head;

	head = sh->history;
	i = 0;
	while (i < sh->history_save && sh->history->bfr)
	{
		sh->history = sh->history->bfr;
		i++;
	}
	print_history(sh);
	sh->history = head;
}

void	up_history(t_shell *sh)
{
	if (!(sh->in->buf_i == 0) && (sh->history_save == -2))
		return ;
	if (!sh->history)
		return ;
	if (sh->history_save == -2 || sh->history_save == -1)
	{
		print_history(sh);
		sh->history_save = 0;
	}
	else
	{
		if (listlen(sh->history) != sh->history_save + 1)
			sh->history_save++;
		up_history_here(sh);
	}
}
