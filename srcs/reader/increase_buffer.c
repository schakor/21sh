/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 22:13:26 by schakor           #+#    #+#             */
/*   Updated: 2018/10/26 15:48:38 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void		increase_buffer(t_shell *sh)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(*ret) * (sh->in->buf_tmp + BUF_TMP))))
		exit(EXIT_FAILURE);
	ft_memset(ret, '\0', sh->in->buf_tmp + BUF_TMP);
	ft_memcpy(ret, sh->in->buffer, sh->in->buf_tmp);
	sh->in->buf_tmp += BUF_TMP;
	ft_strdel(&(sh->in->buffer));
	sh->in->buffer = ret;
}
