/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:32:41 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/09/26 21:39:32 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnchr(const char *s, int c, size_t n)
{
	char	c_c;
	size_t	i;

	c_c = (char)c;
	i = 0;
	while (*(s + i) != '\0' && i < n)
	{
		if (*(s + i) == c_c)
			return ((char *)(s + i));
		i++;
	}
	if (c_c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
