/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:33:46 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/20 15:26:32 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*u_b;

	u_b = (unsigned char *)b;
	while (len-- > 0)
		*u_b++ = (unsigned char)c;
	return (b);
}
