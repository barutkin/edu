/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:45:03 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/22 17:58:48 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tetriminos.h>

int		get_board_size(int n)
{
	int i;

	i = 0;
	if (n <= 0)
		return (0);
	n *= TETR_SIZE;
	while (i * i < n)
		i++;
	return (i);
}