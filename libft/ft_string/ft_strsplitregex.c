/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitregex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 07:04:55 by piquerue          #+#    #+#             */
/*   Updated: 2018/08/07 07:24:54 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strsplit_regex_exist(char *str, char split)
{
	int		i;
	int		start;
	int		stop;

	start = -1;
	stop = -1;
	i = -1;
	while (str[++i] && stop < 0)
	{
		if (str[i] == split && start >= 0)
			stop = i;
		if (str[i] == split && start == -1)
			start = i;
	}
	return ((stop >= 0) ? 0 : 1);
}

char		*ft_strsplit_regex(char *str, char split)
{
	int		i;
	int		start;
	int		stop;

	start = -1;
	stop = -1;
	i = -1;
	while (str[++i] && stop <0)
	{
		if (str[i] == split && start >= 0)
			stop = i;
		if (str[i] == split && start == -1)
			start = i;
	}
	if (stop >= 0)
		return (ft_strdup_from_to(str, start + 1, stop));
	return (NULL);
}
