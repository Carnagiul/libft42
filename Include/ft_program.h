/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:35:14 by piquerue          #+#    #+#             */
/*   Updated: 2022/02/11 14:58:52 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROGRAM_H
# define FT_PROGRAM_H

typedef struct s_program {
	void							(*callback)(struct s_program *program);
	int								need_stop;
	int								exit_code;
	char							*exit_message;
	struct s_list					*events;
	void							*project;
}									t_program;

typedef struct s_program_callback {
	void							(*callback)(struct s_program_callback *cb);
	t_program						*data_event;
	struct s_program_callback		*next;
}									t_program_callback;

t_program					*ft_create_program(void);
void						run_program_methods(t_program *program);
void						run_program_callback(t_program *program);
void						run_program_events(t_program *program);
t_program_callback			*ft_create_program_callback(void);


#endif