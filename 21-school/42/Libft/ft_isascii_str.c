/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 11:57:56 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/09/29 18:12:12 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isascii_str(char const *s)
{
	int	i;
	int	slen;

	slen = (int)ft_strlen(s);
	i = 0;
	while (i < slen)
	{
		if (!ft_isascii((int)(*(s + i))))
			return (0);
		i++;
	}
	return (1);
}
