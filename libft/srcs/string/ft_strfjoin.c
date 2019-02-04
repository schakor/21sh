/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:18:00 by schakor           #+#    #+#             */
/*   Updated: 2018/12/05 20:22:04 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strfjoin(char *s1, char *s2, int opt)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	if (opt == 0)
		ft_strdel(&s1);
	else if (opt == 1)
		ft_strdel(&s2);
	else if (opt == 2)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (ret);
}
