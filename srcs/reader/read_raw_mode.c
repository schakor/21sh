/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_raw_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:22:18 by schakor           #+#    #+#             */
/*   Updated: 2018/10/16 14:46:03 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void			read_raw_mode(t_shell *sh)
{
	int		tmp;

	(void)sh;
	ft_memset(&tmp, '\0', 4);
	while (42)
	{
		if (read(STDIN_FILENO, &tmp, 4) < 0)
			break ;
		if (ft_isprint(tmp))
			insert_buffer(sh, (char)tmp);
		else if (tmp == LEFT_KEY)
			move_left_cursor(sh);
		else if (tmp == RIGHT_KEY)
			move_right_cursor(sh);
		else if (tmp == DELETE_KEY)
			del_one_char(sh);
		else if (tmp == ENTER_KEY)
			break ;
		if (sh->in->bufsize >= sh->in->buf_tmp)
			increase_buffer(sh);
		ft_memset(&tmp, '\0', 4);
	}
}
