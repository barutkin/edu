/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:32:49 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/09/29 18:49:33 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	int		sign;
	char	isintmin;

	if (fd < 0)
		return ;
	if (!(isintmin = 0) && n == FT_INT_MIN)
	{
		isintmin = 1;
		n = FT_INT_MIN / 10;
		sign = -1;
	}
	else
		sign = n >= 0 ? 1 : -1;
	if ((n *= sign) && sign == -1)
		ft_putchar_fd('-', fd);
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
		n /= 10;
	}
	else
		ft_putchar_fd(n + '0', fd);
	if (isintmin)
		ft_putchar_fd(FT_INT_MIN_LASTCHAR, fd);
}
