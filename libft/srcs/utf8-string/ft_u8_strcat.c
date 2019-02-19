/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u8_strcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <schakor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:38:51 by schakor           #+#    #+#             */
/*   Updated: 2019/02/16 10:41:41 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t			*ft_u8_strcat(uint8_t *dst, const uint8_t *src)
{
	return ((uint8_t *)ft_strcat((char *)dst, (const char *)src));
}
