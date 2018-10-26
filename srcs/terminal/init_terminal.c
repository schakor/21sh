/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:01:24 by schakor           #+#    #+#             */
/*   Updated: 2018/10/26 16:31:28 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void			init_terminal(t_shell *sh)
{
	char	*term;

	term = ft_strdup("xterm-256color");
	tgetent(NULL, term);
	ft_strdel(&term);
	tcgetattr(STDIN_FILENO, &(sh->cooked_tio));
	tcgetattr(STDIN_FILENO, &(sh->raw_tio));
	sh->raw_tio.c_lflag &= ~(ECHO | ICANON);
	sh->raw_tio.c_oflag &= ~(OPOST);
	sh->raw_tio.c_cc[VMIN] = 1;
	sh->raw_tio.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &(sh->raw_tio));
}
