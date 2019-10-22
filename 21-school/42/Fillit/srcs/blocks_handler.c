/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:29:09 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/22 20:46:24 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <tetriminos.h>

void		get_offset(char **lines, int *x_offset, int *y_offset)
{
	int		i;
	int		j;

	i = 0;
	*x_offset = TETR_SIZE;
	*y_offset = TETR_SIZE;
	while (i < TETR_SIZE)
	{
		j = 0;
		while (j < TETR_SIZE)
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
	while (i < TETR_SIZE)
	{
		j = 0;
		while (j < TETR_SIZE)
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
	char	tmp[TETR_SIZE][TETR_SIZE];
	int		i;
	int		j;

	i = 0;
	while (i < TETR_SIZE)
	{
		j = 0;
		while (j++ < TETR_SIZE)
			tmp[i][j - 1] = block[TETR_SIZE - (j - 1) - 1][i];
		i++;
	}
	i = 0;
	while (i < TETR_SIZE)
	{
		j = 0;
		while (j++ < TETR_SIZE)
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

	if (!(tetr = (char ***)malloc(sizeof(char **) * ((len / TETR_AREA) + 1))))
		clear_ts(INVALID);
	i = 0;
	k = 0;
	while (i <= len / TETR_AREA)
	{
		j = 0;
		if (!(tetr[i] = (char **)malloc(sizeof(char *) * TETR_SIZE)))
			clear_ts(INVALID);
		while (j < TETR_SIZE)
			tetr[i][j++] = ft_strdup(lines[k++]);
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
	if (side < TETR_SIZE)
		while (i < TETR_SIZE && (o = ft_strequ(a[i], b[i])))
			i++;
	else
		return (INVALID);
	return (o ? side + 1 : arraycmp(rotate(a), b, side + 1));
}
