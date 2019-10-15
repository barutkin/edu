/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrnchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 10:47:50 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/09/27 13:03:15 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrnchr(const char *s, int c, size_t n)
{
	char	c_c;
	size_t	s_i;
	char	*res;

	c_c = (char)c;
	s_i = 0;
	res = NULL;
	while (*(s + s_i) != '\0' && s_i < n)
	{
		if (*(s + s_i) == c_c)
			res = (char *)(s + s_i);
		s_i++;
	}
	if (c_c == '\0')
		res = (char *)(s + s_i);
	return (res);
}
