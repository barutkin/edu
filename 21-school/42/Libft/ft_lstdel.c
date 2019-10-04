/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:29:28 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/01 11:32:17 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst_next;

	if (*alst && alst && del)
	{
		while (*alst)
		{
			lst_next = (*alst)->next;
			ft_lstdelone(&(*alst), del);
			*alst = lst_next;
		}
	}
}
