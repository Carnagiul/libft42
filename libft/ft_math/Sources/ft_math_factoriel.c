/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_factoriel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:17:34 by piquerue          #+#    #+#             */
/*   Updated: 2019/01/10 12:17:43 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_math_factoriel(int i)
{
	int	start;
	int	ret;

	ret = 1;
	start = 1;
	while (start < i)
		ret = ret * start++;
	ret = ret * start;
	return (ret);
}
