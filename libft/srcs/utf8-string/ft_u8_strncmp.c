/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u8_strncmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <schakor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 09:34:35 by schakor           #+#    #+#             */
/*   Updated: 2019/02/16 10:30:46 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_u8_strncmp(const uint8_t *s1, const uint8_t *s2, size_t n)
{
	return (ft_strncmp((const char *)s1, (const char *)s2, n));
}
