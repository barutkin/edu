/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:59:09 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/20 19:17:31 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetraminos.h"

char		*chrjoin(char name, char symbol, char side)
{
	char	*a;

	if (!(a = (char *)malloc(4)))
		clear_ts();
	a[0] = name;
	a[1] = symbol;
	a[2] = side;
	a[3] = '\0';
	return (a);
}

void		create_ts(void)
{
	if (!(g_cur_tetr = (char **)malloc(sizeof(char *) * TETR_MAX)))
		clear_ts();
	g_cur_tetr_len = 0;
	if (!(g_tetr = (t_tetramino *)malloc(sizeof(t_tetramino) * TETR_COUNT)))
		clear_ts();
	g_s.symbol = 'S';
	g_s.array = NULL;
	g_z.symbol = 'Z';
	g_z.array = NULL;
	g_t.symbol = 'T';
	g_t.array = NULL;
	g_i.symbol = 'I';
	g_i.array = NULL;
	g_o.symbol = 'O';
	g_o.array = NULL;
	g_l.symbol = 'L';
	g_l.array = NULL;
	g_j.symbol = 'J';
	g_j.array = NULL;
	create_tsarray();
}

void		create_tsarray(void)
{
	g_s.array = fill_ts(".##.##..........");
	g_tetr[0] = g_s;
	g_z.array = fill_ts("##...##.........");
	g_tetr[1] = g_z;
	g_t.array = fill_ts(".#..###.........");
	g_tetr[2] = g_t;
	g_i.array = fill_ts("#...#...#...#...");
	g_tetr[3] = g_i;
	g_o.array = fill_ts("##..##..........");
	g_tetr[4] = g_o;
	g_l.array = fill_ts("#...#...##......");
	g_tetr[5] = g_l;
	g_j.array = fill_ts(".#...#..##......");
	g_tetr[6] = g_j;
}

char		**fill_ts(char *str)
{
	int		i;
	char	**tetr;

	if (!(tetr = tsmalloc()))
		clear_ts();
	i = 0;
	while (i < 4)
	{
		tetr[i] = ft_strsub(str, i * 4, 4);
		i++;
	}
	return (tetr);
}

void		set_board(int k)
{
	char	*line;
	int		i;
	int		n;

	i = 0;
	if (g_cur_tetr_len > 0)
	{
		if (!(line = ft_strnew(TETR_MAX)))
			clear_ts();
		n = get_board_size(g_cur_tetr_len) + k;
		while (i++ < n)
			ft_strcat(line, ".");
		if (!(g_b = malloc(sizeof(char *) * n)))
			clear_ts();
		if (!g_b || !line)
		{
			ft_strdel(&line);
			clear_ts();
		}
		g_bs = n;
		i = 0;
		while (i < n)
			g_b[i++] = ft_strdup(line);
		ft_strdel(&line);
	}
}
