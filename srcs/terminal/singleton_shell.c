/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton_shell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:16:41 by schakor           #+#    #+#             */
/*   Updated: 2018/12/17 12:19:11 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

t_shell					*singleton_shell(void)
{
	static t_shell		*ret = NULL;

	if (!ret)
		if (!(ret = (t_shell *)malloc(sizeof(*ret))))
			fatal_exit(ret, SH_ENOMEM);
	return (ret);
}
