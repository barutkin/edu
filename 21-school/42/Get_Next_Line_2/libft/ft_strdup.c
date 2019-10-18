/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:50:02 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/14 17:04:39 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*str;
	size_t	s1len;

	s1len = s1 ? ft_strlen(s1) : 0;
	if ((str = ft_strnew(s1len)))
		return (ft_strncpy(str, s1, s1len));
	else
		return (NULL);
}
