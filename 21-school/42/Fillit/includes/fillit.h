/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:53:47 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/22 17:55:56 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libft.h>

# define VALID			1
# define INVALID		0

typedef struct		s_tetrimino
{
	char			**array;
	char			symbol;
}					t_tetrimino;

char				**g_b;
int					g_bs;

int					handle_i(char *block);
int					handle_o(char *block);
int					handle_t(char *block);
int					handle_l(char *block);
int					handle_j(char *block);
int					handle_z(char *block);
int					handle_s(char *block);
int					solve(void);
int					validate(const int fd);
int					get_next_line(const int fd, char **line);
void				ft_arraydel(char **lines, int len);
void				clear_ts(void);
char				**move_to_topleft(char **lines);
char				***split_blocks(char **lines, int len);
int					clear_blocks(char ***blocks, int len, int cur_size);
int					arraycmp(char **a, char **b, int side);
void				ft_arraydel(char **lines, int len);
int					free_to_busy(char *block);
int					get_board_size(int n);
void				print(void);

#endif
