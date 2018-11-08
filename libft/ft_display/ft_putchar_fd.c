/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:09:04 by piquerue          #+#    #+#             */
/*   Updated: 2018/11/08 13:49:00 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_4_fd(int wc, int fd)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int writed;

	writed = 0;
	a = (wc >> 18) + 0xF0;
	b = ((wc >> 12) & 0x3F) + 0X80;
	c = ((wc >> 6) & 0x3F) + 0X80;
	d = (wc & 0x3F) + 0X80;
	writed += write(fd, &a, 1);
	writed += write(fd, &b, 1);
	writed += write(fd, &c, 1);
	writed += write(fd, &d, 1);
}

void	ft_putchar_3_fd(int wc, int fd)
{
	int	b;
	int	c;
	int	d;
	int	writed;

	writed = 0;
	b = (wc >> 12) + 0XE0;
	c = ((wc >> 6) & 0x3F) + 0X80;
	d = (wc & 0x3F) + 0X80;
	writed += write(fd, &b, 1);
	writed += write(fd, &c, 1);
	writed += write(fd, &d, 1);
}

void	ft_putchar_2_fd(int wc, int fd)
{
	int	c;
	int	d;
	int	writed;

	writed = 0;
	c = (wc >> 6) + 0XC0;
	d = (wc & 0x3F) + 0X80;
	writed += write(fd, &c, 1);
	writed += write(fd, &d, 1);
}

void	ft_putchar_fd(int wc, int fd)
{
	int writed;

	writed = 0;
	if (wc <= 127)
		writed += write(fd, &wc, 1);
	else if (wc <= 0x7FF)
		ft_putchar_2_fd(wc, fd);
	else if (wc <= 0xFFFF)
		ft_putchar_3_fd(wc, fd);
	else
		ft_putchar_4_fd(wc, fd);
}
