/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_histori.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:28:39 by khsadira          #+#    #+#             */
/*   Updated: 2018/11/12 16:48:19 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

t_history	*new_hist(char *buffer, int bufsize)
{
	t_history	*list;

	list = NULL;
	if (!(list = (t_history *)malloc(sizeof(*list))))
		return (NULL);
	list->buffer = buffer;
	list->bufsize = bufsize;
	list->next = NULL;
	list->bfr = NULL;
	return (list);
}

t_history	*add_hist(t_history *list, t_history *new_hist)
{
	if (new_hist == NULL)
	{
		while (list && list->next)
			list = list->next;
		return (list);
	}
	if (list == NULL)
		return (new_hist);
	while (list->next)
		list = list->next;
	list->next = new_hist;
	new_hist->bfr = list;
	return (new_hist);
}
