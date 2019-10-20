/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:56:44 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/20 21:29:49 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/tetraminos.h"

char		**tsmalloc(void)
{
	char	**p;

	if (!(p = (char **)malloc(sizeof(char *) * 4)))
	{
		ft_putendl("tsmalloc error");
		clear_ts();
	}
	return (p);
}

void		ft_arraydel(char **lines, int len)
{
	int		i;

	i = 0;
	if (!lines || !*lines)
		return ;
	while (i < len)
	{
		if (lines[i])
			ft_strdel(&lines[i]);
		i++;
	}
	//free(lines);
	lines = NULL;
}

void		clear_ts(void)
{
	if (g_s.array)
		ft_arraydel(g_s.array, 4);
	if (g_z.array)
		ft_arraydel(g_z.array, 4);
	if (g_t.array)
		ft_arraydel(g_t.array, 4);
	if (g_i.array)
		ft_arraydel(g_i.array, 4);
	if (g_o.array)
		ft_arraydel(g_o.array, 4);
	if (g_l.array)
		ft_arraydel(g_l.array, 4);
	if (g_j.array)
		ft_arraydel(g_j.array, 4);
	ft_arraydel(g_cur_tetr, g_cur_tetr_len);
	ft_arraydel(g_b, g_bs);
	if (g_tetr)
		free(g_tetr);
	exit(1);
}

int			clear_tetr(char ***tetr, int len, int cur_size)
{
	int		i;

	i = 0;
	while (i <= len / 5)
		free(tetr[i++]);
	free(tetr);
	g_cur_tetr_len = cur_size;
	return (INVALID);
}
