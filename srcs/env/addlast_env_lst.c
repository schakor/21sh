/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addlast_env_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:11:26 by schakor           #+#    #+#             */
/*   Updated: 2018/10/15 19:43:30 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

t_env_lst		*addlast_env_lst(t_env_lst *head, t_env_lst *new)
{
	t_env_lst	*tmp;

	tmp = NULL;
	if (head == NULL)
		return (new);
	else if (new == NULL)
		return (head);
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (head);
}
