/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 19:30:17 by schakor           #+#    #+#             */
/*   Updated: 2019/03/02 13:46:48 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void			push_env(t_envl **head, char *name, char *value)
{
	t_envl		*tmp;

	tmp = NULL;
	if (!head || !name || !value)
		return ;
	tmp = *head;
	if (tmp)
	{
		while (tmp->next != NULL)
		{
			if (ft_strequ(tmp->name, name))
			{
				ft_strdel(&tmp->value);
				tmp->value = ft_strdup(value);
				return ;
			}
			tmp = tmp->next;
		}
	}
	if (!(tmp = (t_envl *)malloc(sizeof(*tmp))))
		return ;
	tmp->name = ft_strdup(name);
	tmp->value = ft_strdup(value);
	tmp->next = NULL;
	*head = addlast_envl(*head, tmp);
}
