/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_program_callback.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:35:47 by piquerue          #+#    #+#             */
/*   Updated: 2022/02/10 19:50:32 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_program_callback			*ft_create_program_callback(void)
{
	t_program_callback		*callback;

	callback = (t_program_callback *)ft_malloc(sizeof(t_program_callback));	
	callback->data_event = NULL;
	callback->callback = NULL;
	return callback;
}