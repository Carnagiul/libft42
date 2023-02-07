/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:57:29 by piquerue          #+#    #+#             */
/*   Updated: 2022/02/10 14:41:53 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_free_return(char *str)
{
	ft_strdel(&str);
	return (ft_strdup("0"));
}

static char	*ft_itoa_free_return_min(char *str)
{
	ft_strdel(&str);
	return (ft_strdup("-2147483648"));
}

char		*ft_itoa(int nb)
{
	char	*str;
	int		n;
	int		i;

	n = nb;
	str = (char *)malloc(sizeof(char) * (ft_pow(nb) + 1));
	if (!str)
		return (ft_strdup("0"));
	if (nb == 0)
		return (ft_itoa_free_return(str));
	i = ft_pow(nb);
	str[i--] = '\0';
	if (-2147483648 == nb)
		return (ft_itoa_free_return_min(str));
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		str[i--] = '0' + (n % 10);
		n = n / 10;
	}
	if (nb < 0)
		str[i--] = '-';
	return (str);
}
