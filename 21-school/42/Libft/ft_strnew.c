/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:06:44 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/02 09:59:52 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	if (size + 1 == 0)
		return (0);
	if ((str = (char *)malloc(size + 1)))
	{
		ft_bzero(str, size + 1);
		return (str);
	}
	else
		return (NULL);
}
