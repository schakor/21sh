/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u8_strcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <schakor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 09:28:13 by schakor           #+#    #+#             */
/*   Updated: 2019/02/16 10:29:29 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_u8_strcmp(const uint8_t *s1, const uint8_t *s2)
{
	return (ft_strcmp((const char *)s1, (const char *)s2));
}
