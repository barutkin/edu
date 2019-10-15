/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:03:20 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/14 17:08:17 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h> */

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	s_i;

	s_i = 0;
	/* printf("ft_strncpy: src=\"%s\" len=%zu\n", src, len); */
	/* printf("ft_strncpy: *(src+%zu)=%c\n", s_i, *(src + s_i)); */
	while (s_i < len && *(src + s_i))
	{
		*(dst + s_i) = *(src + s_i);
		s_i++;
	}
	while (s_i < len)
	{
		*(dst + s_i) = '\0';
		s_i++;
	}
	return (dst);
}
