/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:41:47 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/20 15:23:10 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					buffparse(char **buff, char **line)
{
	char			*eol;
	char			*tmp;
	size_t			len;

	if (!(eol = NULL) && (!(*buff) || **buff == '\0'))
		return (-1);
	if ((eol = ft_strchr(*buff, '\n')))
	{
		if (!(*line = ft_strsub(*buff, 0, eol - *buff)))
			return (-1);
		len = ft_strlen(*line);
		if (ft_strlen(*buff) > len && (tmp = *buff))
		{
			if (!(*buff = ft_strsub(tmp, len + 1, ft_strlen(tmp) - len - 1)))
				return (-1);
			ft_strdel(&tmp);
			return (1);
		}
		else
		{
			ft_strdel(buff);
			return (0);
		}
	}
	return (-1);
}

int					bufftotmp(t_buff *l_buff, char **strtmp)
{
	if (l_buff->buff == NULL)
	{
		if (!(l_buff->buff = ft_strnew(0)))
			return (-1);
		l_buff->bufflen = 0;
	}
	else
		l_buff->bufflen = ft_strlen(l_buff->buff);
	if (!(*strtmp = ft_strnew(l_buff->bufflen + BUFF_SIZE)))
		return (-1);
	ft_strlcat(*strtmp, l_buff->buff, l_buff->bufflen + 1);
	ft_strdel(&l_buff->buff);
	return (0);
}

int					getlst(const int fd, t_buff **l_buff, t_buff **lst)
{
	t_buff			*lst_next;
	t_buff			*lst_new;

	*lst = *l_buff;
	while (*lst)
	{
		if ((*lst)->fd == fd)
			return (0);
		if ((lst_next = (*lst)->next))
			*lst = lst_next;
		else
			break ;
	}
	if (!(lst_new = (t_buff *)malloc(sizeof(t_buff))))
		return (-1);
	lst_new->fd = fd;
	lst_new->buff = NULL;
	lst_new->next = NULL;
	if (*lst)
		(*lst)->next = lst_new;
	else
		*l_buff = lst_new;
	*lst = lst_new;
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	int				out;
	ssize_t			ssread;
	char			*strtmp;
	static t_buff	*l_buff;
	t_buff			*lst;

	if (fd < 0 || fd > FD_MAX - 1 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (!(lst = NULL) && getlst(fd, &l_buff, &lst) == -1)
		return (-1);
	while ((out = buffparse(&(lst->buff), line)) == -1)
	{
		bufftotmp(lst, &strtmp);
		ssread = read(lst->fd, (strtmp + lst->bufflen), BUFF_SIZE);
		lst->buff = strtmp;
		if (ssread == 0 && (*line = lst->buff))
		{
			lst->buff = NULL;
			out = (ft_strlen(*line) > 0) ? 1 : 0;
			break ;
		}
		else if (ssread == -1)
			return (-1);
	}
	return (out);
}
