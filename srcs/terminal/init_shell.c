/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:29:22 by schakor           #+#    #+#             */
/*   Updated: 2018/10/15 22:37:13 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

static void				init_reader(t_shell *sh)
{
	if (!(sh->in = (t_input *)malloc(sizeof(*sh->in))))
	{
		free(sh);
		ft_putendl_fd("Cannot allocate memory.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!(sh->in->buffer = (char *)malloc(sizeof(*sh->in->buffer) * BUF_TMP)))
	{
		free(sh->in);
		free(sh);
		ft_putendl_fd("Cannot allocate memory.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_memset(sh->in->buffer, '\0', BUF_TMP);
	sh->in->buf_i = 0;
	sh->in->bufsize = 0;
	sh->in->buf_tmp = BUF_TMP;
}

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
	init_reader(sh);
	sh->env = ft_arrdup(env);
	sh->env_lst = envarr_2_envlst(env);
	sh->paths = NULL;
	sh->cmd = NULL;
	sh->head = NULL;
	init_terminal(sh);
	return (sh);
}
