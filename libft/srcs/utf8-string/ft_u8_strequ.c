/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u8_strequ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <schakor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 10:42:06 by schakor           #+#    #+#             */
/*   Updated: 2019/02/16 10:43:41 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_u8_strequ(uint8_t const *s1, uint8_t const *s2)
{
	return (ft_strequ((char const *)s1, (char const *)s2));
}
