/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetraminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:09:57 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/22 01:06:58 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRAMINOS_H
# define TETRAMINOS_H

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

t_tetramino			*g_tetr;
char				**g_cur_tetr;
int					g_cur_tetr_len;
t_tetramino			g_s;
t_tetramino			g_z;
t_tetramino			g_t;
t_tetramino			g_i;
t_tetramino			g_o;
t_tetramino			g_l;
t_tetramino			g_j;

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
