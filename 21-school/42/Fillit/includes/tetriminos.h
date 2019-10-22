/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:09:57 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/22 18:00:53 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

# include "fillit.h"

# define TETR_COUNT		7
# define TETR_MAXIN		26
# define TETR_SIZE		4
# define EMPTY_LINES	1
# define TETR_AREA		(TETR_SIZE + EMPTY_LINES)
# define BOARD_MAXSIZE	((TETR_MAXIN * TETR_AREA) + 1)
# define TETR_MASK_S	".##.##.........."
# define TETR_MASK_Z	"##...##........."
# define TETR_MASK_T	".#..###........."
# define TETR_MASK_I	"#...#...#...#..."
# define TETR_MASK_O	"##..##.........."
# define TETR_MASK_L	"#...#...##......"
# define TETR_MASK_J	".#...#..##......"

t_tetrimino			*g_tetr;
char				**g_cur_tetr;
int					g_cur_tetr_len;
t_tetrimino			g_s;
t_tetrimino			g_z;
t_tetrimino			g_t;
t_tetrimino			g_i;
t_tetrimino			g_o;
t_tetrimino			g_l;
t_tetrimino			g_j;

void				set_board(int k);
void				create_ts();
void				create_tsarray(void);
void				clear_ts();
int					clear_tetr(char ***tetr, int len, int cur_size);
char				***split_tetr(char **lines, int len);
void				print();
void				print_tetr(char **block, int len);
char				*chrjoin(char name, char symbol, char side);
void				ft_arraydel(char **lines, int len);
char				**tsmalloc(void);
char				**fill_ts(char *str);

#endif
