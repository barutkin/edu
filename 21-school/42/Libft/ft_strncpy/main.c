/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:54:00 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/14 16:39:39 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int			main(void)
{
	char	*src = "A";
	/* char	*src = "AbcdefG"; */
	/* char	*src = "--> nyancat <--\n\r"; */
	char	*dst;
	/* char	dst[30]; */

	dst = ft_strnew(1);
	printf("src=\"%s\"\n", src);
	printf("dst=\"%s\"\n", dst);
	/* printf("ft_strncpy=\"%s\"\n", ft_strncpy(dst, src, ft_strlen(src))); */
	printf("ft_strncpy=\"%s\"\n", ft_strncpy(dst, src, 1));
	/* printf("ft_strcmp=%d", ft_strcmp()) */

	return (0);
}
