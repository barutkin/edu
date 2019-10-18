/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:57:34 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/14 00:30:07 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_i;
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen >= size)
		return (size + srclen);
	s_i = 0;
	while (s_i < srclen && dstlen + s_i < size - 1)
	{
		*(dst + dstlen + s_i) = *(src + s_i);
		s_i++;
	}
	*(dst + dstlen + s_i) = '\0';
	return (dstlen + srclen);
}
