/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:24:42 by schakor           #+#    #+#             */
/*   Updated: 2019/01/26 16:00:34 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

static void			sig_handler(int signo)
{
	if (signo == SIGTSTP)
	{
		singleton_shell()->sigtstp_sig = 1;
	}
}

void				run_shell(t_shell *sh)
{
	t_bool			run;

	run = TRUE;
	while (run == TRUE)
	{
		if (signal(SIGTSTP, sig_handler) == SIG_ERR)
			ft_putendl_fd("Couldn't catch fucking signal", STDERR_FILENO);
		readline(sh);
		write(1, "\n", 1);
		ft_putstr(tgetstr("cr", NULL));
		ft_putstr(sh->line);
		if (ft_strequ(sh->line, "exit"))
		{
			reset_terminal(sh);
			exit(EXIT_FAILURE);
		}
		write(1, "\n", 1);
		ft_putstr(tgetstr("cr", NULL));
	}
}
