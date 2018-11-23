/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:54:40 by schakor           #+#    #+#             */
/*   Updated: 2018/11/22 17:42:30 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_arrdel(char **arr)
{
	size_t	i;

	if (arr)
	{
		i = 0;
		while (arr[i] != NULL)
		{
			ft_strdel(&(arr[i]));
			i++;
		}
		free(arr);
		arr = NULL;
	}
}
