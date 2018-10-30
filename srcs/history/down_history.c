/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:37:42 by schakor           #+#    #+#             */
/*   Updated: 2018/10/30 13:29:42 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void	down_history_here(t_shell *sh)
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

void	down_history(t_shell *sh)
{
	if (!sh->history)
		return ;
	if (sh->history_save == 0)
		sh->history_save++;
	if (sh->history_save == -1 || sh->history_save == -2)
		return ;
	else
	{
		sh->history_save--;
		down_history_here(sh);
	}
}
