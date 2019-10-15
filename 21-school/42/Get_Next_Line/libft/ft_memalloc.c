/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:31:42 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/09/24 22:45:59 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	unsigned char	*u_mem;

	if ((u_mem = (unsigned char *)malloc(size)))
		ft_bzero((void *)u_mem, size);
	else
		return (NULL);
	return ((void *)u_mem);
}
