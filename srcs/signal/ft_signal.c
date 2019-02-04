/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:13:02 by khsadira          #+#    #+#             */
/*   Updated: 2018/12/17 14:16:21 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void	ft_sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		signal(SIGINT, ft_sig_handler);
	}
}

void	ft_signal(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		reset_terminal(singleton_shell());
		exit(EXIT_FAILURE);
	}
	else if (signo == SIGSEGV)
	{
		reset_terminal(singleton_shell());
		ft_putstr("\n");
		ft_putendl_fd("Khan please fix the segfault, thanks.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (signo == SIGABRT)
	{
		reset_terminal(singleton_shell());
		ft_putstr("\n");
		ft_putendl_fd("Khan please tell me, why does the program abort ?", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
