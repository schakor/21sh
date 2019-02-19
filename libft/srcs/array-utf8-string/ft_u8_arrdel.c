/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u8_arrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <schakor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:47:58 by schakor           #+#    #+#             */
/*   Updated: 2019/02/16 13:55:35 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_u8_arrdel(uint8_t **arr)
{
	size_t	i;

	i = 0;
	if (arr)
	{
		while (arr[i] != NULL)
		{
			ft_u8_strdel(&(arr[i]));
			i++;
		}
		free(arr);
		arr = NULL;
	}
}
