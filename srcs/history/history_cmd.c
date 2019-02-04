/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:17:34 by khsadira          #+#    #+#             */
/*   Updated: 2019/02/04 12:09:43 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

static int	ft_nblen(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	history_cmd(t_shell *sh)
{
	t_history	*tmp;
	int			i;
	int			len;

	i = 1;
	tmp = sh->history;
	while (tmp->bfr)
		tmp = tmp->bfr;
	while (tmp)
	{
		move_start(sh);
		len = 5 - ft_nblen(i);
		while (len--)
			ft_putchar(' ');
		ft_putnbr(i);
		ft_putstr("  ");
		ft_putstr(tmp->buffer);
		if (tmp->next)
			ft_putchar(10);
		i++;
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
