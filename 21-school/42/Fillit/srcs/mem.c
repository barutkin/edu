/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:56:44 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/22 22:01:04 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <tetriminos.h>

char		**tsmalloc(void)
{
	char	**p;

	if (!(p = (char **)malloc(sizeof(char *) * TETR_SIZE)))
	{
		ft_putendl("tsmalloc error");
		clear_ts(VALID);
	}
	return (p);
}

void		ft_arraydel(char **lines, int len)
{
	int		i;

	if (!lines || !*lines)
		return ;
	i = 0;
	while (i < len)
		ft_strdel(&lines[i++]);
	if (lines)
		free(lines);
	lines = NULL;
}

void		clear_ts(const int is_valid)
{
	if (g_s.array)
		ft_arraydel(g_s.array, TETR_SIZE);
	if (g_z.array)
		ft_arraydel(g_z.array, TETR_SIZE);
	if (g_t.array)
		ft_arraydel(g_t.array, TETR_SIZE);
	if (g_i.array)
		ft_arraydel(g_i.array, TETR_SIZE);
	if (g_o.array)
		ft_arraydel(g_o.array, TETR_SIZE);
	if (g_l.array)
		ft_arraydel(g_l.array, TETR_SIZE);
	if (g_j.array)
		ft_arraydel(g_j.array, TETR_SIZE);
	ft_arraydel(g_cur_tetr, g_cur_tetr_len);
	ft_arraydel(g_b, g_bs);
	if (g_tetr)
		free(g_tetr);
	if (!is_valid)
		ft_putendl("error");
	exit(1);
}

int			clear_tetr(char ***tetr, int len, int cur_size)
{
	int		i;
	int		j;

	i = 0;
	while (i <= len / TETR_AREA)
	{
		j = 0;
		while (j < TETR_SIZE)
			ft_strdel(&tetr[i][j++]);
		if (tetr[i])
			free(tetr[i++]);
	}
	if (tetr)
		free(tetr);
	g_cur_tetr_len = cur_size;
	return (INVALID);
}
