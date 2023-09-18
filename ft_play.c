/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:45:53 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/13 10:15:39 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_skyflor(t_master *s_m)
{
	int	x;
	int	y;

	y = -1;
	while (++y < s_m->height)
	{
		x = -1;
		while (++x < s_m->width)
		{
			if (y < s_m->height / 2)
				img_pix_put(&s_m->skyfloor, x, y, s_m->map.c_c);
			else
				img_pix_put(&s_m->skyfloor, x, y, s_m->map.c_f);
		}
	}
}

void	ft_play(t_master *s_m)
{
	ft_loader_b(s_m, s_m->mlx, s_m->win);
	ft_skyflor(s_m);
	s_m->screen = 5;
}
