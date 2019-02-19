/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u8_strdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <schakor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 09:41:04 by schakor           #+#    #+#             */
/*   Updated: 2019/02/16 09:42:10 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t		*ft_u8_strdup(const uint8_t *s)
{
	return ((uint8_t *)ft_strdup((const char *)s));
}
