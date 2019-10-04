/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:38:37 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/09/25 12:37:28 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*u_src;
	unsigned char	*u_dst;
	unsigned char	*u_tmp;

	u_src = (unsigned char *)src;
	u_dst = (unsigned char *)dst;
	if (u_dst == u_src || !len)
		return (dst);
	if (u_src + len < u_dst || u_src > u_dst + len)
		ft_memcpy(dst, src, len);
	else
	{
		if ((u_tmp = (unsigned char*)malloc(len)))
		{
			ft_memcpy(u_tmp, src, len);
			ft_memcpy(dst, u_tmp, len);
			free(u_tmp);
		}
	}
	return (dst);
}
