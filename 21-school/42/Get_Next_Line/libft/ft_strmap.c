/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:06:27 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/03 18:15:47 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		slen;
	char	*sout;

	if (s != NULL && f != NULL)
	{
		slen = (int)ft_strlen(s);
		if ((sout = (char *)malloc(sizeof(char) * (slen + 1))))
		{
			i = 0 - 1;
			while (++i < slen)
				*(sout + i) = f(*(s + i));
			*(sout + i) = '\0';
		}
	}
	else
		sout = NULL;
	return (sout);
}
