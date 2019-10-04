/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:25:12 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/09/29 15:17:40 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa(int n)
{
	int		sign;
	char	isintmin;
	char	*res;
	int		i;

	if ((res = ft_strnew(FT_INT_MAXCHARS)))
	{
		if (!(isintmin = 0) && (n == FT_INT_MIN) &&
				(isintmin = 1) &&
				(sign = -1))
			n = (FT_INT_MAX / 10) * (-1);
		else
			sign = n >= 0 ? 1 : -1;
		n *= sign;
		if (!(i = 0) && n == 0)
			*res = '0';
		while (n > 0 && (*(res + i++) = n % 10 + '0'))
			n /= 10;
		if (sign == -1)
			*(res + i++) = '-';
		if ((res = ft_strrev(res)) && isintmin)
			*(res + i) = FT_INT_MIN_LASTCHAR;
	}
	return (res);
}
