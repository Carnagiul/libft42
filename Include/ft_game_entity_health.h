/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_entity_health.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:14:32 by piquerue          #+#    #+#             */
/*   Updated: 2022/02/06 23:24:46 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_ENTITY_HEALTH_H
# define FT_GAME_ENTITY_HEALTH_H

typedef struct s_entity_health {
	int			actual;
	int			max;
	void		(*setHealth)(struct s_entity_health *entity, int health);
	void		(*setMaxHealth)(struct s_entity_health *entity, int maxHealth);
	int			(*getHealth)(struct s_entity_health *entity);
	int			(*getMaxHealth)(struct s_entity_health *entity);
}				t_entity_health;

t_entity_health			*ft_create_entity_health(void);
void					ft_update_entity_health(t_entity *entity, int health);
void					ft_update_entity_max_health(t_entity *entity, int health);
void					ft_get_entity_max_health(t_entity *entity);
void					ft_get_entity_health(t_entity *entity);

#endif