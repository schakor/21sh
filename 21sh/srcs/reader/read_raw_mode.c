/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_raw_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:22:18 by schakor           #+#    #+#             */
/*   Updated: 2018/10/16 20:45:58 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

static void				init_reader(t_shell *sh)
{
	if (!(sh->in = (t_input *)malloc(sizeof(*sh->in))))
	{
		free(sh);
		ft_putendl_fd("Cannot allocate memory.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!(sh->in->buffer = (char *)malloc(sizeof(*sh->in->buffer) * BUF_TMP)))
	{
		free(sh->in);
		free(sh);
		ft_putendl_fd("Cannot allocate memory.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_memset(sh->in->buffer, '\0', BUF_TMP);
	sh->in->buf_i = 0;
	sh->in->bufsize = 0;
	sh->in->buf_tmp = BUF_TMP;
}

void			read_raw_mode(t_shell *sh)
{
	int		tmp;

	init_reader(sh);
	tmp = 0;
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
			delete_buffer(sh);
		else if (tmp == ENTER_KEY)
			break ;
		if (sh->in->bufsize >= sh->in->buf_tmp)
			increase_buffer(sh);
		tmp = 0;
	}
}
