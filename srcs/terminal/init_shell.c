/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:29:22 by schakor           #+#    #+#             */
/*   Updated: 2018/10/24 14:04:39 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

t_shell					*init_shell(int ac, char **av, char **env)
{
	t_shell		*sh;

	(void)ac;
	(void)av;
	if (!(sh = (t_shell *)malloc(sizeof(*sh))))
	{
		ft_putendl_fd("Cannot allocate memory.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	sh->in = NULL;
	sh->env = ft_arrdup(env);
	sh->env_lst = envarr_2_envlst(env);
	sh->paths = NULL;
	sh->cmd = NULL;
	sh->head = NULL;
	init_terminal(sh);
	sh->history = NULL;
	return (sh);
}
