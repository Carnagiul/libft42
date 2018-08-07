/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:33:19 by piquerue          #+#    #+#             */
/*   Updated: 2018/08/07 06:41:31 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup_from_to_offset(char *str, int min, int max,
		int offset)
{
	char	*ret;
	int		i;
	int		prod;

	if (offset < 0 || min < 0 || max < 0 || max - min < 0)
		return (NULL);
	prod = max - min + offset;
	ret = ft_strnew(prod);
	i = 0;
	while (min < max)
		ret[i++] = str[min++];
	return (ret);
}

char		*ft_strdup_from_to(char *str, int min, int max)
{
	char	*ret;
	int		i;

	if (max < 0 || min < 0 || max - min < 0)
		return (NULL);
	ret = ft_strnew(max - min);
	i = 0;
	while (min < max)
		ret[i++] = str[min++];
	return (ret);
}

char		*ft_strdup(char const *str)
{
	char	*s;

	s = ft_strnew(ft_strlen(str));
	return ((s == NULL) ? NULL : ft_strcpy(s, str));
}
