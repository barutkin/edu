/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:42:14 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/03 18:11:02 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	slen;

	if (s != NULL && f != NULL)
	{
		slen = (unsigned int)ft_strlen(s);
		i = 0 - 1;
		while (++i < slen)
			f(i, s + i);
	}
}
