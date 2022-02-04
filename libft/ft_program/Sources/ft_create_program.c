/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_program.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:05:20 by piquerue          #+#    #+#             */
/*   Updated: 2022/02/04 16:44:56 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_program			*ft_create_program(void)
{
	t_program		*prog;
	
	prog = (t_program *)ft_malloc(sizeof(t_program));
	prog->exit_code = 0;
	prog->need_stop = 0;
	return prog;
}