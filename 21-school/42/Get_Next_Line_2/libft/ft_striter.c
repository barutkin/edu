/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:17:29 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/09/23 15:30:34 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int	i;
	int	slen;

	if (s != NULL && f != NULL)
	{
		slen = (int)ft_strlen(s);
		i = 0;
		while (i < slen)
			f(s + i++);
	}
}
