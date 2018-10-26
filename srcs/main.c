/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:11:22 by schakor           #+#    #+#             */
/*   Updated: 2018/10/26 17:48:30 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

int			main(int ac, char **av, char **env)
{
	t_shell		*sh;

	sh = init_shell(ac, av, env);
	while (42)
	{
		display_prompt(sh);
		read_raw_mode(sh);
		write(1, "\n", 1);
		ft_putstr(tgetstr("cr", NULL));
		ft_putstr(sh->in->buffer);
		add_history(sh);
		if (ft_strequ(sh->in->buffer, "exit"))
		{
			tcsetattr(STDIN_FILENO, TCSANOW, &(sh->cooked_tio));
			exit(1);
		}
		write(1, "\n", 1);
		ft_putstr(tgetstr("cr", NULL));
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &(sh->cooked_tio));
	return (0);
}
