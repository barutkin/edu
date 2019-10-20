/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:47:57 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/20 20:47:58 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int	handle_1(char *block)
{
	int		x;
	int		y;

	y = -1;
	while (++y <= g_bs - 2)
	{
		x = -1;
		while (++x <= g_bs - 3)
			if (g_b[y][x] == '.' && g_b[y][x + 1] == '.' &&
				g_b[y + 1][x + 1] == '.' && g_b[y + 1][x + 2] == '.')
			{
				g_b[y][x] = block[0];
				g_b[y][x + 1] = block[0];
				g_b[y + 1][x + 1] = block[0];
				g_b[y + 1][x + 2] = block[0];
				if (solve())
					return (1);
				g_b[y][x] = '.';
				g_b[y][x + 1] = '.';
				g_b[y + 1][x + 1] = '.';
				g_b[y + 1][x + 2] = '.';
			}
	}
	return (0);
}

static int	handle_2(char *block)
{
	int		x;
	int		y;

	y = -1;
	while (++y <= g_bs - 3)
	{
		x = -1;
		while (++x <= g_bs - 2)
			if (g_b[y][x + 1] == '.' && g_b[y + 1][x] == '.' &&
				g_b[y + 1][x + 1] == '.' && g_b[y + 2][x] == '.')
			{
				g_b[y][x + 1] = block[0];
				g_b[y + 1][x] = block[0];
				g_b[y + 1][x + 1] = block[0];
				g_b[y + 2][x] = block[0];
				if (solve())
					return (1);
				g_b[y][x + 1] = '.';
				g_b[y + 1][x] = '.';
				g_b[y + 1][x + 1] = '.';
				g_b[y + 2][x] = '.';
			}
	}
	return (0);
}

int			handle_z(char *block)
{
	if (block[2] == '1')
		return (handle_1(block));
	if (block[2] == '2')
		return (handle_2(block));
	return (0);
}
