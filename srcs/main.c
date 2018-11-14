/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:11:22 by schakor           #+#    #+#             */
/*   Updated: 2018/11/14 17:43:10 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

int			main(int ac, char **av, char **env)
{
	t_shell		*sh;

	sh = init_shell(ac, av, env);
	while (42)
	{
		signal(SIGINT, ft_signal);
		display_prompt(sh);
		read_raw_mode(sh);
		//lexer(sh);
		//parser(sh);
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
		free_input(sh->in);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &(sh->cooked_tio));
	return (0);
}
