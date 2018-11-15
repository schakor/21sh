/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:29:22 by schakor           #+#    #+#             */
/*   Updated: 2018/11/14 17:25:38 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

t_shell					*init_shell(int ac, char **av, char **env)
{
	t_shell		*sh;

	(void)ac;
	(void)av;
	if (!(sh = (t_shell *)malloc(sizeof(*sh))))
		fatal_exit(sh, SH_ENOMEM);
	sh->env = ft_arrdup(env);
	sh->paths = NULL;
	sh->key = 0;
	sh->len_prompt = 0;
	sh->envl = envarr_2_envl(env);
	sh->in = NULL;
	sh->tk = NULL;
	sh->root = NULL;
	init_terminal(sh);
	sh->history = NULL;
	sh->history_save = -2;
	history_from_file(sh);
	return (sh);
}
