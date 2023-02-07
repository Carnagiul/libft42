/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:27:32 by piquerue          #+#    #+#             */
/*   Updated: 2022/02/04 17:04:53 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_read(int fd)
{
	int		ret;
	char	buf;
	int		i;
	int		count;
	char	*input;

	input = ft_strnew(1);
	count = 1;
	i = 0;
	while ((ret = read(fd, &buf, 1)) && buf != '\n')
	{
		*(input + i++) = buf;
		input = ft_mem_realloc(input, count, count + 1);
		count++;
	}
	*(input + i) = '\0';
	if (!ret)
		free(input);
	return input;
}