/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:22:45 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:39:33 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_pow(int nb)
{
	int p;

	p = 0;
	if (nb == 0)
		p++;
	if (nb < 0)
		p++;
	while (nb != 0)
	{
		nb = nb / 10;
		p++;
	}
	return (p);
}
