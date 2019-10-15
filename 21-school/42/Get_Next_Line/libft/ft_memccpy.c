/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:55:40 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/09/29 14:19:09 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*u_chr;

	u_chr = (unsigned char *)ft_memchr(src, c, n);
	if (u_chr)
	{
		ft_memcpy(dst, src, (size_t)(u_chr - (unsigned char *)src + 1));
		return ((void *)((unsigned char *)dst +
					(u_chr - (unsigned char *)src) + 1));
	}
	else
	{
		ft_memcpy(dst, src, n);
		return (NULL);
	}
}
