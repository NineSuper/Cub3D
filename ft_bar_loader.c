/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bar_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:10:48 by tde-los-          #+#    #+#             */
/*   Updated: 2023/07/06 22:43:04 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_bar_loader(t_master *s_m, int width, int height)
{
	int x;
	int y;
	int i;
	int j;

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
    //mlx_clear_window(s_m->mlx, s_m->win);
}

void	ft_loader_b(t_master *s_m, void *mlx, void *win)
{
    int x;  
    int y;
    int i;
    int j;
    int width;
    int height;
    int borderSize;

	s_m->screen = 4;
    x = (s_m->width / 2) - 200;
    y = (s_m->height / 2) - 15;
    width = 400;
    height = 30;
    borderSize = 4;
    i = x - borderSize - 1;
    mlx_string_put(mlx, win, x + 120, y - 15, 0xFFFFFF, text_load);
    while (++i < x + width + borderSize)
    {
        j = y - borderSize - 1;
        while (++j < y + height + borderSize)
            mlx_pixel_put(mlx, win, i, j, 0x3e4648);
    }
    ft_bar_loader(s_m, width, height);
}
