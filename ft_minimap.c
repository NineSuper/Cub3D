/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:59:35 by tde-los-          #+#    #+#             */
/*   Updated: 2023/08/20 20:06:26 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
? Minimap : Afficher les murs/portes
? Afficher le joueur en temps direct 
*/

void	ft_draw_square(t_master *s_m, int x, int y, int c)
{
	int	i;
	int	j;
	int w;
	int h;

	i = 7;
	while (++i <= 16)
	{
		j = 7;
		h = i + y * 8;
		while (++j <= 16)
		{
			w = j + x * 8;
			if (c == 1)
				mlx_pixel_put(s_m->mlx, s_m->win, w, h, create_trgb(0, 111, 30, 255));
            else if (c == 2)
                mlx_pixel_put(s_m->mlx, s_m->win, w, h, create_trgb(0, 0, 255, 0));
		}
	}
}

void	ft_minimap(t_master *s_m, char **map)
{
    int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '1')
				ft_draw_square(s_m, x, y, 1);
			else if (map[y][x] == 'N') // ! A modifer par 'P' pour player a l'avenir
				ft_draw_square(s_m, x, y, 2);
		}
	}
}