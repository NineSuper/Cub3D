/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:45:53 by tde-los-          #+#    #+#             */
/*   Updated: 2023/08/23 16:40:29 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
? Faire le ray-casting : ft_raycast.c
? Minimap
*/

void	ft_play(t_master *s_m)
{
	ft_loader_b(s_m, s_m->mlx, s_m->win);
	s_m->screen = 5;
}
