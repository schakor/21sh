/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u8_arrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <schakor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:25:27 by schakor           #+#    #+#             */
/*   Updated: 2019/02/16 13:55:35 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_u8_arrlen(uint8_t **arr)
{
	size_t	ret;

	ret = 0;
	if (!arr)
		return (ret);
	while (arr[ret] != NULL)
		ret++;
	return (ret);
}
