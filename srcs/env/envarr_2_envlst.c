/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envarr_2_envlst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:12:19 by schakor           #+#    #+#             */
/*   Updated: 2018/10/29 21:25:55 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

t_env_lst		*envarr_2_envlst(char **env)
{
	t_env_lst	*ret;
	t_env_lst	*new;
	char		*ptr;

	ret = NULL;
	if (!env)
		return (ret);
	while (*env != NULL)
	{
		if (!(new = (t_env_lst *)malloc(sizeof(*new))))
			return (NULL);
		ptr = ft_strchr(*env, '=');
		new->name = ft_strsub(*env, 0, ptr - *env);
		new->value = ft_strsub(*env, ptr - *env + 1, ft_strlen(ptr));
		new->next = NULL;
		if (ft_strequ(new->name, "SHLVL"))
		{
			ptr = ft_itoa(ft_atoi(new->value) + 1);
			ft_strdel(&new->value);
			new->value = ptr;
		}
		ret = addlast_env_lst(ret, new);
		env++;
	}
	return (ret);
}
