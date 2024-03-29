/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:05:02 by tde-los-          #+#    #+#             */
/*   Updated: 2024/01/09 23:19:42 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <math.h>

void	ft_verline(t_master *s_m, int x, t_draw draw)
{
	int	color;

	color = create_trgb(0, 80, 80, 80);
	if (s_m->player.hit == 2)
		color = create_trgb(0, 0, 0, 255);
	if (s_m->player.side == 1)
		color = color / 2;
	while (draw.drawstart <= draw.drawend)
	{
		put_pixel_img(s_m->img, x, draw.drawstart++, color);
	}
}

void	ft_raycast(t_master *s_m)
{
	char	**map;

	map = s_m->map.map + s_m->map.len;
	if (s_m->img.m_img)
		mlx_destroy_image(s_m->mlx, s_m->img.m_img);
	s_m->img = new_img(WIDTH, HEIGHT, s_m);
	put_img_to_img(s_m->img, s_m->skyfloor, 0, 0);
	ft_ray(s_m, &s_m->player, s_m->map.map + s_m->map.len);
	ft_minimap(s_m, s_m->map.map + s_m->map.len);
	ft_hud(s_m);
	mlx_put_image_to_window(s_m->mlx, s_m->win, s_m->img.m_img, 0, 0);
	if (!s_m->help)
		ft_text(s_m);
	if (map[(int)s_m->player.posy][(int)s_m->player.posx] == 'B')
		ft_exit_menu(s_m);
}
