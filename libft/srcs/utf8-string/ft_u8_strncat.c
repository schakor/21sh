/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u8_strncat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <schakor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:47:59 by schakor           #+#    #+#             */
/*   Updated: 2019/02/16 10:41:41 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t			*ft_u8_strncat(uint8_t *dst, const uint8_t *src, size_t n)
{
	return ((uint8_t *)ft_strncat((char *)dst, (const char *)src, n));
}
