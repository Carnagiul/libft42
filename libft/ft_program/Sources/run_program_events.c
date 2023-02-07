/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_program_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:24:45 by piquerue          #+#    #+#             */
/*   Updated: 2022/02/11 15:00:25 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				run_program_events(t_program *program)
{
	t_list				*cpy;
	t_program_callback	*callback;
	pthread_t			thread[ft_list_size(*(&(program->events))) + 1];
	int					i = 0;
	int					j = 0;

	cpy = *(&(program->events));
	while (cpy != NULL)
	{
		if (program->need_stop == 1)
			return ;
		if (cpy->content != NULL)
		{
			callback = (t_program_callback	*)cpy->content;
			
			if (callback->callback != NULL)
			{
				pthread_create(&thread[i++], NULL, (void*)callback->callback, &callback);
			}
		}
		cpy = cpy->next;
	}
	for (j = 0; j < i; j++)
		pthread_join(thread[j], NULL);
	return ;
}