/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:52:56 by schakor           #+#    #+#             */
/*   Updated: 2018/10/15 19:44:33 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

char		*get_env_val(t_env_lst *env_lst, char *name)
{
	char	*ret;

	ret = NULL;
	if (env_lst == NULL || name == NULL)
		return (NULL);
	while (env_lst != NULL)
	{
		if (env_lst->name != NULL && ft_strequ(env_lst->name, name) == 1)
			return (ft_strdup(env_lst->value));
		env_lst = env_lst->next;
	}
	return (NULL);
}
