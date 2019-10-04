/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:13:16 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/09/29 14:18:22 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*u_src;
	unsigned char	*u_dst;

	u_src = (unsigned char *)src;
	u_dst = (unsigned char *)dst;
	if (u_src == u_dst)
		return (dst);
	while (n-- > 0)
		*(u_dst++) = *(u_src++);
	return (dst);
}
