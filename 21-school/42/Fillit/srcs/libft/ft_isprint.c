/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 11:57:56 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/20 15:24:29 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprint(int c)
{
	if (ft_isalnum(c) || (c >= ' ' && c <= '/') ||
			(c >= ':' && c <= '@') || (c >= '[' && c <= '`') ||
			(c >= '{' && c <= '~'))
		return (1);
	else
		return (0);
}