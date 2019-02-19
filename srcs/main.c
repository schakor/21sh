/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:37:05 by khsadira          #+#    #+#             */
/*   Updated: 2019/02/08 16:54:29 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

t_shell				g_shell;

int					main(int ac, char **av, char **env)
{
	init_shell(ac, av, env);
	run_shell();
	clean_shell();
	exit(EXIT_SUCCESS);
}