/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_static.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:34:56 by piquerue          #+#    #+#             */
/*   Updated: 2019/02/27 14:55:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_static_print(int fd, t_ft_printf_static *ptf)
{
	int	old;

	old = ptf->position;
	ptf->printed += write(fd, ptf->str, 2048);
	ptf->position = 0;
	while (ptf->position < old)
		ptf->str[ptf->position++] = 0;
	ptf->position = 0;
	printf("\nJe suis passer par ici\n");
}

int		ft_printf_static_percent(t_ft_printf_static *ptf)
{
	ptf->str[ptf->position++] = '%';
	ptf->position_str++;
	return (0);
}

int		ft_printf_static_char(t_ft_printf_static *ptf)
{
	int c;

	c = va_arg(ptf->actual, int);
	c %= 255;
	ptf->str[ptf->position++] = c;
	ptf->position_str++;
	return (0);
}

int		ft_printf_static_long_string(t_ft_printf_static *ptf)
{
	int		*str;
	size_t	ret;
	size_t	str_len;
	int		*ext_str;
	int		i;

	i = 0;
	ret = 0;
	str = va_arg(ptf->actual, int *);
	str_len = ft_strlen((char *)str);
	ext_str = (int *)ft_malloc(sizeof(int) * (str_len * 4));
	while (i < str_len)
	{
		i++;
	}
	ret = (int)str_len;
	return ((int)ret);
}

int		ft_printf_static_string(t_ft_printf_static *ptf)
{
	char	*str;
	size_t	ret;
	size_t	str_len;

	str = va_arg(ptf->actual, char *);
	str_len = ft_strlen((char *)str);
	if (ptf->position + str_len >= 2048)
	{
		ft_printf_static_print(ptf->fd, ptf);
		ret = write(ptf->fd, str, str_len);
	}
	else
	{
		ret = 0;
		while (ret < str_len)
			ptf->str[ptf->position++] = str[ret++];
	}
	ptf->position_str++;
	ret = 0;
	return ((int)ret);
}

int		ft_printf_static_delimitor(char *fmt, t_ft_printf_static *ptf)
{
	if (fmt[ptf->position_str] == '%')
		return (ft_printf_static_percent(ptf));
	if (fmt[ptf->position_str] == 'c')
		return (ft_printf_static_char(ptf));
	if (fmt[ptf->position_str] == 's')
		return (ft_printf_static_string(ptf));
	return (1);
}

int		ft_printf_static_research(char *fmt, t_ft_printf_static *ptf)
{
	if (fmt[ptf->position_str] == '%')
	{
		ptf->position_str++;
		while (fmt[ptf->position_str])
		{
			if (ft_printf_static_delimitor(fmt, ptf) == 0)
				return (0);
			ptf->position_str++;
		}
	}
	else
	{
		ptf->str[ptf->position++] = fmt[ptf->position_str++];
	}
	return (0);
}

int		ft_printf_static_fd(int fd, char *fmt, va_list lst)
{
	static t_ft_printf_static	ptf;

	ptf.position_str = 0;
	ptf.total_printed += ptf.printed;
	ptf.printed = 0;
	ptf.fd = fd;
	va_copy(ptf.actual, lst);
	va_copy(ptf.mem, lst);
	va_copy(ptf.cpy, lst);
	while (fmt[ptf.position_str])
	{
		ft_printf_static_research(fmt, &ptf);
		if (ptf.position == 2048)
			ft_printf_static_print(fd, &ptf);
	}
	if (ptf.position > 0)
		ft_printf_static_print(fd, &ptf);
	(void)lst;
	va_end(ptf.actual);
	va_end(ptf.cpy);
	va_end(ptf.mem);
	va_end(lst);
	return (ptf.printed);
}

int		ft_printf_static(char *fmt, ...)
{
	va_list		lst;

	va_start(lst, fmt);
	return (ft_printf_static_fd(1, fmt, lst));
}
