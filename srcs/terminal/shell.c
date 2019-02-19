/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:24:42 by schakor           #+#    #+#             */
/*   Updated: 2019/02/19 13:50:17 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void					init_shell(int ac, char **av, char **env)
{
	char				*term;

	(void)ac;
	(void)av;
	g_shell.el_mode = MODE_EMACS;
	g_shell.line = NULL;
	g_shell.envl = init_shell_envl(env);
	g_shell.history_save = -1;
	g_shell.history_size = 0;
	g_shell.history = init_shell_history();
	if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO) ||\
			!isatty(STDERR_FILENO))
		fatal_exit(SH_ENOTTY);
	if (!(term = get_env_val(g_shell.envl, "TERM")))
		return ;
	if (!tgetent(NULL, term))
		return ;
	if (tcgetattr(STDIN_FILENO, &(g_shell.cooked_tio)) ||\
			tcgetattr(STDIN_FILENO, &(g_shell.raw_tio)))
		fatal_exit(SH_EINVAL);
	g_shell.raw_tio.c_lflag &= ~(ECHO | ICANON | ISIG);
	g_shell.raw_tio.c_oflag &= ~(OPOST);
	g_shell.raw_tio.c_cc[VMIN] = 1;
	g_shell.raw_tio.c_cc[VTIME] = 0;
}

void					run_shell(void)
{
	t_bool run;

	run = TRUE;
	while (run == TRUE)
	{
		if (signal(SIGINT, ft_signal) < 0)
			fatal_exit(SH_EINVAL);
		if (signal(SIGABRT, ft_signal) < 0)
			fatal_exit(SH_EINVAL);
		readline();
		//lexer();
		//parser();
		write(1, "\n", 1);
		ft_putu8str(g_shell.line);
		if (ft_u8_strequ(g_shell.line, (const uint8_t *)"history"))
			;
		else if (ft_u8_strequ(g_shell.line, (const uint8_t *)"exit"))
			exit(EXIT_SUCCESS);
		write(1, "\n", 1);
	}
}
