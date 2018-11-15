/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:11:22 by schakor           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/11/15 14:24:32 by schakor          ###   ########.fr       */
=======
/*   Updated: 2018/11/15 14:06:59 by khsadira         ###   ########.fr       */
>>>>>>> 8fa18b769f903aec4489f3c018a0f3ba281e9291
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
<<<<<<< HEAD
			file_from_history(sh);
			reset_terminal();
=======
			file_from_history(sh, get_env_val(sh->envl, "HOME"));
			reset_terminal(sh);
>>>>>>> 8fa18b769f903aec4489f3c018a0f3ba281e9291
			exit(EXIT_FAILURE);
		}
		write(1, "\n", 1);
		ft_putstr(tgetstr("cr", NULL));
		free_input(sh->in);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &(sh->cooked_tio));
	return (0);
}
