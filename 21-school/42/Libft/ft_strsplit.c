/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 12:24:31 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/10/03 18:23:24 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		**ft_astrfree(char **astr)
{
	size_t		s_i;

	if (astr)
	{
		s_i = 0;
		while (astr + s_i)
			ft_strdel(astr + s_i++);
		free(astr);
	}
	return (NULL);
}

static char		**ft_astrpull(char const **awords, size_t s_words)
{
	size_t		s_i;
	char		**astr;

	if ((astr = (char **)malloc(sizeof(char **) * s_words + 1)))
	{
		s_i = 0;
		while (s_i < s_words)
		{
			if (!(astr[s_i] = ft_strnew(ft_strlen(awords[s_i]))))
				return (ft_astrfree(astr));
			ft_strcpy(astr[s_i], awords[s_i]);
			s_i++;
		}
		astr[s_i] = NULL;
		return (astr);
	}
	else
		return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		s_i;
	size_t		s_words;
	char		*str;
	char		*awords[FT_STR_WORDS_MAX];

	if (!(s_words = 0) && s && ft_strlen(s) != 0)
	{
		if (!ft_strdup(str = (char *)s))
			return (NULL);
		if (!ft_strcmp(ft_strstrim(str, c), ""))
			return (ft_astrpull((const char **)"", 0));
		while (str && ft_strchr(str, c) &&
				(awords[s_words] = ft_strstrim(str, c)))
			str = ft_strchr(awords[s_words++], c);
		s_i = 0;
		while (s_words > 0 && s_i < s_words - 1 &&
			(awords[s_i] = ft_strstrim(ft_strsub(awords[s_i], 0,
					ft_strstr(awords[s_i], awords[s_i + 1]) - awords[s_i]), c)))
			s_i++;
		if (s_words > 0)
			awords[s_i] = ft_strstrim(awords[s_i], c);
		else
			awords[s_words++] = str;
	}
	return (ft_astrpull((const char **)awords, s_words));
}
