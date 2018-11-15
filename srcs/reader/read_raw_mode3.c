/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_raw_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:22:18 by schakor           #+#    #+#             */
/*   Updated: 2018/11/15 14:03:14 by schakor          ###   ########.fr       */
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
	sh->in->buftmp = BUF_TMP;
}

void					read_raw_mode(t_shell *sh)
{
	init_reader(sh);
	while (!(sh->key = 0))
	{
		if (read(STDIN_FILENO, &sh->key, 8) < 0)
			break ;
		printf("[%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]\n", ((unsigned char *)(&(sh->key)))[0], ((unsigned char *)(&(sh->key)))[1], ((unsigned char *)(&(sh->key)))[2], ((unsigned char *)(&(sh->key)))[3], ((unsigned char *)(&(sh->key)))[4], ((unsigned char *)(&(sh->key)))[5], ((unsigned char *)(&(sh->key)))[6], ((unsigned char *)(&(sh->key)))[7]);
		ft_putstr(tgetstr("cr", NULL));
		/*
		if (ft_isprint(sh->key))
			insert_buffer(sh, (char)sh->key);
		else if (sh->key == LEFT_KEY)
			move_left_cursor(sh, &(sh->in->buf_i));
		else if (sh->key == RIGHT_KEY)
			move_right_cursor(sh, &(sh->in->buf_i));
		else if (sh->key == DELETE_KEY)
			delete_buffer(sh);
		else if (sh->key == UP_KEY)
			up_history(sh);
		else if (sh->key == DOWN_KEY)
			down_history(sh);
		else if (sh->key == ENTER_KEY)
		{
			sh->history_save = -2;
			break ;
		}
		if (sh->in->bufsize >= sh->in->buftmp)
			increase_buffer(sh);
		*/
	}
}
