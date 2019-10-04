/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 23:42:37 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/09/24 18:31:39 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) && *(s2 + i) && i < n)
	{
		if ((unsigned char)*(s1 + i) > (unsigned char)*(s2 + i))
			return ((unsigned char)(*(s1 + i) - *(s2 + i)));
		else if ((unsigned char)*(s1 + i) < (unsigned char)*(s2 + i))
			return (-(unsigned char)(*(s2 + i) - *(s1 + i)));
		i++;
	}
	if (i != n)
	{
		if (*(s1 + i))
			return ((unsigned char)*(s1 + i));
		else if (*(s2 + i))
			return (-(unsigned char)*(s2 + i));
		return (0);
	}
	return (0);
}
