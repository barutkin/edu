/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:55:35 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/17 15:59:31 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

# define FD_MAX			1000000
# define BUFF_SIZE		1
# define BUFFTMP_SIZE	10

typedef struct			s_buff
{
	int					fd;
	char				*buff;
	ssize_t				bufflen;
	char				*bufftmp[BUFFTMP_SIZE];
	ssize_t				bufftmplen;
	int					i;
	struct s_buff		*next;
}						t_buff;

int						get_next_line(const int fd, char **line);

#endif
