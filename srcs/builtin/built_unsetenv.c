/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_unsetenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:30:33 by khsadira          #+#    #+#             */
/*   Updated: 2019/02/27 16:31:12 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"
/*
static t_env	*ft_unset(char *str, t_env *l_env)
{
	t_env	*h_env;
	t_env	*tmp;

	if (ft_strequ(l_env->name, str))
	{
		tmp = l_env->next;
		l_env->next = NULL;
		ft_freeenv(l_env);
		return (tmp);
	}
	h_env = l_env;
	while (l_env)
	{
		if (ft_strequ(l_env->name, str))
		{
			tmp->next = l_env->next;
			l_env->next = NULL;
			ft_freeenv(l_env);
			return (h_env);
		}
		tmp = l_env;
		l_env = l_env->next;
	}
	return (h_env);
}

t_env			*ft_unsetenv(t_lst *list, t_env *l_env)
{
	int	i;
	int	len;

	if (!l_env)
		return (NULL);
	len = ft_dstrlen(list->arg);
	i = 1;
	if (len < 2)
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
	else
		while (list->arg[i])
			l_env = ft_unset(list->arg[i++], l_env);
	return (l_env);
}*/

void	built_unsetenv()
{
}
