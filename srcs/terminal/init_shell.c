/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:29:22 by schakor           #+#    #+#             */
/*   Updated: 2019/01/26 16:00:31 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

static void				init_env_var(t_shell *sh, char **env)
{
	sh->env = ft_arrdup(env);
	sh->envl = envarr_2_envl(env);
	sh->sigtstp_sig = 0;
}

t_shell					*init_shell(int ac, char **av, char **env)
{
	t_shell		*sh;

	(void)ac;
	(void)av;
	sh = singleton_shell();
	init_env_var(sh, env);
	init_terminal(sh);
	return (sh);
}
