/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_div.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:11:57 by piquerue          #+#    #+#             */
/*   Updated: 2019/01/10 12:23:03 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_math_div(int a, int div)
{
	if (ft_math_mod(a, div) != 0)
		return ((a / div) - 1);
	return (a / div);
}

long int		ft_math_li_div(long int a, long int div)
{
	if (ft_math_mod(a, div) != 0)
		return ((a / div) - 1);
	return (a / div);
}

long long int	ft_math_lli_div(long long int a, long long int div)
{
	if (ft_math_mod(a, div) != 0)
		return ((a / div) - 1);
	return (a / div);
}
