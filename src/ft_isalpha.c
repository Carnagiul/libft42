/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 18:13:14 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:24:47 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_isalpha(int c)
{
	if (!ft_isascii(c))
		return (0);
	if (ft_toupper(c) == ft_tolower(c))
		return (0);
	return (1);
}
