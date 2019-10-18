/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:41:47 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/17 16:11:36 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int					buffparse(char **buff, char **line)
{
	char			*eol;
	char			*strtmp;
	size_t			len;

	if (!(eol = NULL) && (!(*buff) || **buff == '\0'))
		return (-1);
	if ((eol = ft_strchr(*buff, '\n')))
	{
		if (!(*line = ft_strsub(*buff, 0, eol - *buff)))
			return (-1);
		len = ft_strlen(*line);
		if (ft_strlen(*buff) > len)
		{
			strtmp = *buff;
			if (!(*buff = ft_strsub(strtmp, len + 1,
							ft_strlen(strtmp) - len - 1)))
				return (-1);
			ft_strdel(&strtmp);
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
	int				i;

	if (l_buff->buff == NULL)
	{
		if (!(l_buff->buff = ft_strnew(0)))
			return (-1);
		l_buff->bufflen = 0;
	}
	else
		l_buff->bufflen = ft_strlen(l_buff->buff);
	/* printf("bufftotmp: l_buff->buff=\"%s\"\n", l_buff->buff); */
	if (!(*strtmp = ft_strnew(l_buff->bufflen + l_buff->bufftmplen)))
		return (-1);
	/* printf("bufftotmp: l_buff->bufflen + l_buff->bufftmplen=%zu\n", l_buff->bufflen + l_buff->bufftmplen); */
	ft_strlcat(*strtmp, l_buff->buff, l_buff->bufflen + 1);
	/* printf("bufftotmp: *strtmp=\"%s\"\n", *strtmp); */
	i = 0;
	while (i < l_buff->i)
	{
		ft_strlcat(*strtmp, l_buff->bufftmp[i], ft_strlen(*strtmp) +
				ft_strlen(l_buff->bufftmp[i]) + 1);
		ft_strdel(&(l_buff->bufftmp[i]));
		i++;
	}
	/* printf("bufftotmp: *strtmp=\"%s\"\n", *strtmp); */
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

int					getread(t_buff **lst, ssize_t *ssread)
{
	while ((*lst)->i < BUFFTMP_SIZE)
	{
		if (!((*lst)->bufftmp[(*lst)->i] = ft_strnew(BUFF_SIZE)))
			return (-1);
		*ssread = read((*lst)->fd, (*lst)->bufftmp[(*lst)->i], BUFF_SIZE);
		/* printf("getread: (*lst)->bufftmp[(*lst)->i]=\"%s\"\n", (*lst)->bufftmp[(*lst)->i]); */
		if (*ssread >= 0)
		{
			(*lst)->bufftmplen += *ssread;
			if (ft_strchr((*lst)->bufftmp[(*lst)->i++], '\n'))
				break ;
		}
		else if (*ssread == -1)
			return (-1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	int				out;
	ssize_t			ssread;
	char			*strtmp;
	static t_buff	*l_buff;
	t_buff			*lst;

	/* printf("get_next_line: fd=%d\n", fd); */
	if (fd < 0 || fd > FD_MAX - 1 || line == NULL)
		return (-1);
	if (!(lst = NULL) && getlst(fd, &l_buff, &lst) == -1)
		return (-1);
	/* printf("get_next_line: lst->fd=%d\n", lst->fd); */
	/* printf("get_next_line: lst->buff=\"%s\"\n", lst->buff); */
	/* printf("get_next_line: lst->next=\"%p\"\n", lst->next); */
	/* printf("get_next_line: lst=%p\n", lst); */
	/* printf("get_next_line: l_buff=%p\n", l_buff); */
	while (((out = buffparse(&(lst->buff), line)) == -1))
	{
		lst->i = 0;
		if ((!(ssread = 0) && getread(&lst, &ssread) == -1) ||
				bufftotmp(lst, &strtmp) == -1)
			return (-1);
		/* bufftotmp(lst, &strtmp); */
		/* printf("get_next_line: strtmp=\"%s\"\n", strtmp); */
		lst->buff = strtmp;
		/* printf("get_next_line: lst->buff=\"%s\"\n", lst->buff); */
		if (ssread == 0 && (*line = lst->buff))
		{
			lst->buff = NULL;
			out = (ft_strlen(*line) > 0) ? 1 : 0;
			break ;
		}
	}
	return (out);
}
