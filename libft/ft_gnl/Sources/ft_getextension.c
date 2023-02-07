/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getextension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 20:05:08 by piquerue          #+#    #+#             */
/*   Updated: 2018/08/07 05:07:26 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_extension(char *str)
{
	char	**tab;
	int		i;
	char	*ret;

	i = 0;
	if (ft_strlen(str) <= 2)
		return (NULL);
	tab = ft_strsplit(str, '.');
	while (tab[i])
		i++;
	ret = ft_strdup(tab[i - 1]);
	while (i > 0)
		free(tab[--i]);
	free(tab);
	return (ret);
}
