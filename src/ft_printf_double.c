/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 04:05:48 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/30 04:28:11 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_printf_double(t_print *print, va_list *vl, char c)
{
	c = 0;
	print->writed += 0;
	va_arg(*vl, void *);
	(void)c;
}
