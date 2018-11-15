/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:01:24 by schakor           #+#    #+#             */
/*   Updated: 2018/11/15 13:39:12 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void			init_terminal(t_shell *sh)
{
	char	*term;

	if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO) ||\
			!isatty(STDERR_FILENO))
		fatal_exit(sh, SH_ENOTTY);
	if (!(term = get_env_val(sh->envl, "TERM")))
		term = ft_strdup("xterm-256color");
	if (!tgetent(NULL, term))
		fatal_exit(sh, SH_ENOTTY);
	ft_strdel(&term);
	if (tcgetattr(STDIN_FILENO, &(sh->cooked_tio)) ||\
			tcgetattr(STDIN_FILENO, &(sh->raw_tio)))
		fatal_exit(sh, SH_EINVAL);
	sh->raw_tio.c_lflag &= ~(ECHO | ICANON);
	sh->raw_tio.c_oflag &= ~(OPOST);
	sh->raw_tio.c_cc[VMIN] = 1;
	sh->raw_tio.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &(sh->raw_tio)))
		fatal_exit(sh, SH_EINVAL);
}

void			reset_terminal(t_shell *sh)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, &sh->cooked_tio))
		fatal_exit(sh, SH_EINVAL);
}
