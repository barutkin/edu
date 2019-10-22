/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:47:44 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/22 15:01:31 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tetraminos.h>

int			check_tetraminos(char **lines, int len)
{
	char	***tetr;
	char	name;
	int		side;
	int		i;
	int		j;

	i = -1;
	name = 'A';
	tetr = split_tetr(lines, len);
	while (++i < (len / TETR_AREA) + 1)
	{
		j = -1;
		while (++j < TETR_COUNT)
		{
			if ((side = arraycmp(tetr[i], g_tetr[j].array, 0)))
			{
				g_cur_tetr[i] = chrjoin(name++, g_tetr[j].symbol, side + '0');
				break ;
			}
		}
		if (!side)
			return (clear_tetr(tetr, len, i));
	}
	clear_tetr(tetr, len, i);
	return (VALID);
}

int			check_lines(char **lines, int len)
{
	if ((len + EMPTY_LINES) % TETR_AREA != 0 || !(*lines) ||
			(len / TETR_AREA) + 1 > TETR_MAXIN)
		return (INVALID);
	len /= TETR_AREA;
	while (len)
	{
		if (*lines[(len * TETR_AREA) - 1])
			return (INVALID);
		len--;
	}
	return (VALID);
}

int			check_line(const char *str)
{
	int		i;

	if (*str && ft_strlen(str) != TETR_SIZE)
		return (INVALID);
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) != '.' && *(str + i) != '#')
			return (INVALID);
		i++;
	}
	return (VALID);
}

int			validate(const int fd)
{
	char	*line;
	char	**lines;
	int		len;
	int		err[2];

	if (!(lines = (char **)malloc(sizeof(char *) * BOARD_MAXSIZE)))
		clear_ts();
	err[1] = 0;
	len = 0;
	while ((err[0] = get_next_line(fd, &line)) > 0 &&
			(err[1] = check_line(line)))
		lines[len++] = line;
	if (err[0] == -1)
		clear_ts();
	ft_strdel(&line);
	lines[len] = 0;
	if (err[1] && check_lines(lines, len) && check_tetraminos(lines, len))
	{
		ft_arraydel(lines, len);
		return (VALID);
	}
	ft_arraydel(lines, len);
	if (!len && fd > 0)
		ft_strdel(&line);
	return (INVALID);
}
