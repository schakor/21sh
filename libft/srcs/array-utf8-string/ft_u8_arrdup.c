/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u8_arrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <schakor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:44:04 by schakor           #+#    #+#             */
/*   Updated: 2019/02/16 13:55:35 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t			**ft_u8_arrdup(uint8_t **arr)
{
	uint8_t		**ret;
	size_t		i;

	i = 0;
	ret = NULL;
	if (!arr || !(ret = (uint8_t **)malloc(sizeof(*ret) * (ft_u8_arrlen(arr) +
			1))))
		return (ret);
	while (arr[i] != NULL)
	{
		ret[i] = ft_u8_strdup(arr[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
