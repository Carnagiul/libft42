/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitwhitespace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 05:47:10 by piquerue          #+#    #+#             */
/*   Updated: 2018/08/07 05:47:11 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbword(char const *s)
{
	int			i;
	int			isword;

	i = 0;
	isword = 0;
	while (*s)
	{
		if (isword == 0 && (*s != ' ' || *s != '\t'))
		{
			isword = 1;
			i++;
		}
		else if (isword == 1 && (*s != ' ' || *s != '\t'))
			isword = 0;
		s++;
	}
	return (i);
}

static int		ft_length(char const *s)
{
	int			length;

	length = 0;
	while (*s && (*s != ' ' || *s != '\t'))
	{
		length++;
		s++;
	}
	return (length);
}

char			**ft_strsplitwhitespace(char const *s)
{
	char		**tab;
	int			i;
	int			nbword;

	i = 0;
	if (!s)
		return (0);
	nbword = ft_nbword(s);
	tab = (char **)malloc(sizeof(char *) * (nbword + 1));
	if (!tab)
		return (NULL);
	while (nbword--)
	{
		while (*s && (*s == ' ' || *s == '\t'))
			s++;
		tab[i] = ft_strsub(s, 0, ft_length(s));
		if (!tab[i])
			return (NULL);
		s = s + ft_length(s);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
