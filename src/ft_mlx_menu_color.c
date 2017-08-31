/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_menu_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 05:12:28 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/07 02:56:11 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		calc_color(int color, int data2, int data1)
{
	int x;
	int	ratio;

	ratio = (data2 - data1) / 255;
	x = (color * ratio) + data1;
	return (x);
}