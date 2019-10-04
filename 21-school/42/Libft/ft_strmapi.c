/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:32:26 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/03 18:18:01 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	slen;
	char			*sout;

	if (s != NULL && f != NULL)
	{
		slen = (unsigned int)ft_strlen(s);
		if ((sout = (char *)malloc(sizeof(char) * (slen + 1))))
		{
			i = 0 - 1;
			while (++i < slen)
				*(sout + i) = f(i, *(s + i));
			*(sout + i) = '\0';
		}
	}
	else
		sout = NULL;
	return (sout);
}
