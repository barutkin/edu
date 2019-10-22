/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:21:25 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/22 17:57:44 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fillit.h>
#include <tetriminos.h>

int		main(int argc, char **argv)
{
	int	i;
	int	fd;

	if (!(i = 0) && (argc > 2 || argc < 2))
		return (0);
	create_ts();
	if (((fd = open(argv[1], O_RDONLY)) > 0 && validate(fd)))
	{
		set_board(0);
		while (!solve())
		{
			ft_arraydel(g_b, g_bs);
			set_board(++i);
		}
		print();
	}
	else
		ft_putendl("error");
	if (fd > 0)
		close(fd);
	clear_ts();
	return (0);
}
