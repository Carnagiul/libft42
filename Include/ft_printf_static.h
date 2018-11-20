/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_static.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:27:16 by piquerue          #+#    #+#             */
/*   Updated: 2018/11/20 15:15:44 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STATIC_H
# define FT_PRINTF_STATIC_H

typedef struct		s_ft_printf_static
{
	char			str[2048];
	int				position_str;
	int				position;
	int				printed;
	int				total_printed;
	int				fd;
	va_list			actual;
	va_list			cpy;
	va_list			mem;
}					t_ft_printf_static;

int		ft_printf_static(char *fmt, ...);
int		ft_printf_static_fd(int fd, char *fmt, va_list lst);

#endif
