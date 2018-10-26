/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controler_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:33:25 by khsadira          #+#    #+#             */
/*   Updated: 2018/10/26 17:48:31 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

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
