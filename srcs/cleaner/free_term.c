/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 21:45:10 by schakor           #+#    #+#             */
/*   Updated: 2018/11/14 16:48:18 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void			free_envl(t_envl *list)
{
	t_envl		*tmp;

	while (list)
	{
		ft_strdel(&(list->name));
		ft_strdel(&(list->value));
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void			free_input(t_input *list)
{
	if (list)
	{
		ft_strdel(&(list->buffer));
		free(list);
		list = NULL;
	}
}

void			free_history(t_history *list)
{
	t_history	*tmp;

	while (list)
	{
		ft_strdel(&(list->buffer));
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void			free_term(t_shell *sh)
{
	ft_arrdel(sh->env);
	ft_arrdel(sh->paths);
	free_envl(sh->envl);
	free_input(sh->in);
	free_history(sh->history);
	free(sh);
}
