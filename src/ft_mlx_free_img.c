/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_free_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:58:24 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/11 04:17:17 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	free_t_img(t_img *img, t_win *win)
{
	mlx_destroy_image(win->mlx, img->img_ptr);
	free(img);
}
