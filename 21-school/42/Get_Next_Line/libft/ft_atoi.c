/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:48:31 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/09/29 15:22:57 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	res;
	long	sign;
	long	border;

	border = FT_LONG_MAX / 10;
	res = 0;
	while (ft_isspace(*str))
		++str;
	sign = ((*str == '-') ? -1 : 1);
	if (*str == '+' || *str == '-')
		++str;
	while (ft_isdigit(*str))
	{
		if (sign == 1 && (res > border ||
					(res == border && *str > FT_INT_MAX_LASTCHAR)))
			return ((int)FT_LONG_MAX);
		if (sign == -1 && (res > border ||
					(res == border && *str > FT_INT_MIN_LASTCHAR)))
			return ((int)FT_LONG_MIN);
		res = res * 10 + (*str - '0');
		++str;
	}
	return ((int)(sign * res));
}
