/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:35:14 by piquerue          #+#    #+#             */
/*   Updated: 2022/02/04 16:53:40 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROGRAM_H
# define FT_PROGRAM_H

typedef struct s_program {
	void			(*callback)(void);
	int				need_stop;
	int				exit_code;	
}					t_program;

t_program			*ft_create_program(void);

#endif