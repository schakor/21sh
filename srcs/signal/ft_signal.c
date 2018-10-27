/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:13:02 by khsadira          #+#    #+#             */
/*   Updated: 2018/10/01 15:38:25 by khsadira         ###   ########.fr       */
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
	//	display_prompt(sh);
		signal(SIGINT, ft_signal);
	}
}
