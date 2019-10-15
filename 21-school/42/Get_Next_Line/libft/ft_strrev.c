/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:04:19 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/09/29 14:14:50 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(const char *str)
{
	size_t	s_i;
	size_t	strlen;
	char	*res;

	if (!str)
		return (NULL);
	strlen = ft_strlen(str);
	if ((res = ft_strnew(strlen)))
	{
		s_i = strlen - 1;
		while (s_i < strlen)
			*(res++) = *(str + s_i--);
	}
	else
		return (NULL);
	return (res - strlen);
}
