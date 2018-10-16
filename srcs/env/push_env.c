/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 19:30:17 by schakor           #+#    #+#             */
/*   Updated: 2018/10/15 19:44:58 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void		push_env(t_env_lst **env_lst_ptr, char *name, char *value)
{
	t_env_lst	*tmp;
	t_env_lst	*new;

	new = NULL;
	tmp = NULL;
	if (!env_lst_ptr || !name || !value)
		return ;
	tmp = *env_lst_ptr;
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
	if (!(new = (t_env_lst *)malloc(sizeof(*new))))
		return ;
	new->name = ft_strdup(name);
	new->value = ft_strdup(value);
	new->next = NULL;
	*env_lst_ptr = addlast_env_lst(*env_lst_ptr, new);
}
