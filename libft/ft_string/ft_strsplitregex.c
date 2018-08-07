/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitregex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 07:04:55 by piquerue          #+#    #+#             */
/*   Updated: 2018/08/07 07:08:04 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsplit_regex(char *str, char split)
{
	int		i;
	int		start;
	int		stop;

	start = -1;
	stop = -1;
	i = -1;
	while (str[++i] && stop >= 0)
	{
		if (str[i] == split && start >= 0)
			stop = i;
		if (str[i] == split)
			start = i;
	}
	return (ft_strdup_from_to(str, start, stop));
}
