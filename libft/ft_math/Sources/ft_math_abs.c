/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_abs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:11:51 by piquerue          #+#    #+#             */
/*   Updated: 2019/01/10 12:19:37 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_math_abs(int nb)
{
	return ((nb < 0) ? -nb : nb);
}

long int		ft_math_li_abs(long int nb)
{
	return ((nb < 0) ? -nb : nb);
}

long long int		ft_math_lli_abs(long long int nb)
{
	return ((nb < 0) ? -nb : nb);
}
