/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:27:12 by khsadira          #+#    #+#             */
/*   Updated: 2019/02/27 16:12:59 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"
/*
t_env			*ft_dupenv(t_env *env)
{
	t_env	*new;
	t_env	*head;
	t_env	*tmp;

	tmp = NULL;
	head = NULL;
	tmp = env;
	new = NULL;
	while (tmp)
	{
		if (!(new = (t_env *)malloc(sizeof(*new))))
			return (NULL);
		new->name = ft_strdup(tmp->name);
		new->arg = ft_strdup(tmp->arg);
		new->next = NULL;
		head = ft_addenv(head, new);
		tmp = tmp->next;
	}
	return (head);
}

static char		**ft_tab_to_tabi(char **tab, int i)
{
	char	*ret;
	char	**ret_t;

	if (!(ret_t = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	ret = ft_strdup(tab[i]);
	i++;
	while (tab[i])
	{
		ret = ft_strfjoin(&ret, " ");
		ret = ft_strfjoin(&ret, tab[i]);
		i++;
	}
	ret_t[0] = ret;
	ret_t[1] = 0;
	return (ret_t);
}

static void		ft_b_exec(char **cmd, int i, t_env *l_env)
{
	char	**tab;

	if (!cmd[i])
	{
		ft_printenv(l_env);
		ft_freeenv(l_env);
		return ;
	}
	tab = ft_tab_to_tabi(cmd, i);
	ft_start_prog(tab, NULL, l_env, 0);
	ft_freedstr(tab);
	ft_freeenv(l_env);
}

void			ft_built_env(t_lst *list, t_env *l_env, int i, int a)
{
	int	c;
	char	*tmp;

	while (list->arg[i] && i != a)
	{
		if (ft_strequ(list->arg[i], "env"))
			return (ft_built_env(list, l_env, i + 1, a));
		else if (ft_strequ(list->arg[i], "-i"))
		{
			ft_freeenv(l_env);
			return (ft_built_env(list, NULL, i + 1, a));
		}
		else if ((c = ft_strichr(list->arg[i], '=')) != -1)
		{
			tmp = ft_strsub(list->arg[i], 0, c);
			l_env = ft_setenv_c(tmp,
				ft_strsub(list->arg[i], c + 1, ft_strlen(list->arg[i]) - c),
				l_env);
			ft_strdel(&tmp);
			return (ft_built_env(list, l_env, i + 1, a));
		}
		i++;
	}
	ft_b_exec(list->arg, i, l_env);
}

//t_envl		*built_env(t_envl *header, t_rl readline)
{

}*/

void	built_env()
{
}
