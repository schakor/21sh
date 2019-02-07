/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:37:05 by khsadira          #+#    #+#             */
/*   Updated: 2019/02/06 16:26:48 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

int					main(int ac, char **av, char **env)
{
	t_shell			*sh;

	sh = init_shell(ac, av, env);
	run_shell(sh);
	clean_shell(sh);
	exit(EXIT_SUCCESS);
}
