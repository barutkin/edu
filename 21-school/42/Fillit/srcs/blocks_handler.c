/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:29:09 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/20 19:00:28 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		get_offset(char **lines, int *x_offset, int *y_offset)
{
	int		i;
	int		j;

	i = 0;
	*x_offset = 4;
	*y_offset = 4;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (lines[i][j] == '#' && i < *x_offset)
				*x_offset = i;
			if (lines[i][j] == '#' && j < *y_offset)
				*y_offset = j;
			j++;
		}
		i++;
	}
}

char		**move_to_topleft(char **lines)
{
	int		i;
	int		j;
	int		x_offset;
	int		y_offset;

	i = 0;
	get_offset(lines, &x_offset, &y_offset);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (lines[i][j] == '#')
			{
				lines[i][j] = '.';
				lines[i - x_offset][j - y_offset] = '#';
			}
			j++;
		}
		i++;
	}
	return (lines);
}

char		**rotate(char **block)
{
	char	tmp[4][4];
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j++ < 4)
			tmp[i][j - 1] = block[4 - (j - 1) - 1][i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j++ < 4)
			block[i][j - 1] = tmp[i][j - 1];
		i++;
	}
	move_to_topleft(block);
	return (block);
}

char		***split_tetr(char **lines, int len)
{
	char	***tetr;
	int		i;
	int		j;
	int		k;

	if (!(tetr = (char ***)malloc(sizeof(char **) * ((len / 5) + 1))))
		clear_ts();
	i = 0;
	k = 0;
	while (i <= len / 5)
	{
		j = 0;
		if (!(tetr[i] = (char **)malloc(sizeof(char *) * 4)))
			clear_ts();
		while (j < 4)
			tetr[i][j++] = lines[k++];
		k++;
		i++;
	}
	return (tetr);
}

int			arraycmp(char **a, char **b, int side)
{
	int		i;
	int		o;

	i = 0;
	if (side == 0)
		move_to_topleft(a);
	if (side < 4)
		while (i < 4 && (o = ft_strequ(a[i], b[i])))
			i++;
	else
		return (INVALID);
	return (o ? side + 1 : arraycmp(rotate(a), b, side + 1));
}
