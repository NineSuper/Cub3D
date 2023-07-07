/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bar_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:10:48 by tde-los-          #+#    #+#             */
/*   Updated: 2023/07/07 10:47:25 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_bar_loader(t_master *s_m, int width, int height)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = (s_m->width / 2) - 200;
	y = (s_m->height / 2) - 15;
	i = x - 1;
	while (++i < x + width)
	{
		usleep(400 * 10);
		j = y - 1;
		while (++j < y + height)
			mlx_pixel_put(s_m->mlx, s_m->win, i, j, 0xFFFFFF);
	}
	usleep(400 * 1000);
	mlx_clear_window(s_m->mlx, s_m->win);
}

void	ft_loader_b(t_master *s_m, void *mlx, void *win)
{
	int	x;
	int	y;
	int	i;
	int	j;

	s_m->screen = 4;
	x = (s_m->width / 2) - 200;
	y = (s_m->height / 2) - 15;
	s_m->menu.width = 400;
	s_m->menu.height = 30;
	s_m->menu.borderSize = 6;
	i = x - s_m->menu.borderSize - 1;
	mlx_set_font(mlx, win, "-*-fixed-bold-*-*-*-18-*-*-*-*-*-*-*");
	mlx_string_put(mlx, win, x + 80, y - 15, 0xFFFFFF, text_load);
	while (++i < x + s_m->menu.width + s_m->menu.borderSize)
	{
		j = y - s_m->menu.borderSize - 1;
		while (++j < y + s_m->menu.height + s_m->menu.borderSize)
			mlx_pixel_put(mlx, win, i, j, 0x3e4648);
	}
	ft_bar_loader(s_m, s_m->menu.width, s_m->menu.height);
}
