/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:16:28 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/09/30 14:37:54 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lstnew;

	if (!(lstnew = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lstnew->content_size = content ? content_size : 0;
	if ((lstnew->content = (void *)malloc(content_size)))
	{
		if (content)
			ft_memcpy(lstnew->content, content, content_size);
		else
			lstnew->content = NULL;
	}
	else
	{
		free(lstnew);
		return (NULL);
	}
	lstnew->next = NULL;
	return (lstnew);
}
