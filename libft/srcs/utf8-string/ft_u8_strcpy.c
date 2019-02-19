/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u8_strcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <schakor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:29:48 by schakor           #+#    #+#             */
/*   Updated: 2019/02/15 19:30:45 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t				*ft_u8_strcpy(uint8_t *dst, const uint8_t *src)
{
	return ((uint8_t *)ft_strcpy((char *)dst, (const char *)src));
}
