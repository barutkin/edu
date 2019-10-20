/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:10:09 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/20 20:20:37 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/tetraminos.h"

static int	g_tetrs_len = 0;

void		print(void)
{
	int		i;

	i = 0;
	while (i < g_bs)
		ft_putendl(g_b[i++]);
}

int			solve(void)
{
	char	*b;

	if (g_tetrs_len >= g_cur_tetr_len)
		return (1);
	b = g_cur_tetr[g_tetrs_len++];
	if ((b[1] == 'I' && handle_i(b)) || (b[1] == 'O' && handle_o(b)))
		return (1);
	if ((b[1] == 'T' && handle_t(b)) || (b[1] == 'L' && handle_l(b)))
		return (1);
	if ((b[1] == 'J' && handle_j(b)) || (b[1] == 'S' && handle_s(b)))
		return (1);
	if (b[1] == 'Z' && handle_z(b))
		return (1);
	g_tetrs_len--;
	return (0);
}
