/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:04:30 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/02 09:48:20 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstrim(char const *s, int splitter)
{
	size_t	s_i;
	size_t	s_begin;

	if (!s)
		return (NULL);
	s_i = 0;
	while (*(s + s_i) == (char)splitter)
		s_i++;
	s_begin = s_i;
	s_i = ft_strlen(s) - 1;
	if (s_begin != s_i + 1)
	{
		while (*(s + s_i) == (char)splitter)
			s_i--;
	}
	return (ft_strsub(s, (unsigned int)s_begin, s_i - s_begin + 1));
}
