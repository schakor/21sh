/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:13:02 by khsadira          #+#    #+#             */
/*   Updated: 2018/11/15 14:27:26 by schakor          ###   ########.fr       */
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
		signal(SIGINT, ft_signal);
	}
	else if (signo == SIGSEGV)
	{
		ft_putendl_fd("Big segfault in the shell because of Khan", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
