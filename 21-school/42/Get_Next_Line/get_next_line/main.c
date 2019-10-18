/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:30:41 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/15 18:56:51 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.c"
#include <stdio.h>

int			main(int argc, char **argv)
{
	char	*line;
	int		fd[FD_MAX + 1][2];
	int		i;
	int		j;
	int		gnlreturn;

	i = 0;
	if (argc == 1)
		fd[i++][0] = 0;
	j = 1;
	while (j < argc)
	{
		fd[i][0] = open(argv[j], O_RDONLY);
		if (fd[i][0] < 0)
		{
			printf("i=%d, fd[i][0]=%d, argv[%d]=%s\n", i, fd[i][0], j, argv[j]);
			printf("Error: open %s\n", argv[j]);
			return (-1);
		}
		fd[i][1] = 0;
		i++;
		j++;
	}
	fd[FD_MAX][1] = 0;
	while (1)
	{
		j = 0;
		while (j < i && !fd[j][1])
		{
			gnlreturn = get_next_line(fd[j][0], &line);
			/* printf("main: gnlreturn=%d\n", gnlreturn); */
			if (gnlreturn == 0 || gnlreturn == -1)
			{
				fd[j][1] = 1;
				fd[FD_MAX][1]++;
			}
			if ((gnlreturn == 1 || gnlreturn == 0) && *line != '\0')
			{
				printf("%s\n", line);
			}
			else if (gnlreturn == -1)
			{
				printf("Error: get_next_line(%d, ...\n", fd[j][0]);
			}
			free(line);
			j++;
		}
		if (fd[FD_MAX][1] == i)
			break;
	}
	return (0);
}
