/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:59:35 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/04 14:13:22 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
* Minimap : Afficher les murs/portes
* ft_map : aggrandir la map
? Afficher le joueur en temps direct 
*/

void	ft_map(t_master *s_m, int x, int y, int c)
{
	int	i;
	int	j;
	int w;
	int h;

	i = 15;
	while (++i <= 32)
	{
		j = 15;
		h = i + y * 16;
		while (++j <= 32)
		{
			w = j + x * 16;
			if (c == 1)
				img_pix_put(&s_m->img, w, h, create_trgb(0, 107, 107, 107));
            else if (c == 2)
				img_pix_put(&s_m->img, w, h, create_trgb(0, 0, 255, 0));
			else if (c == 3)
				img_pix_put(&s_m->img, w, h, create_trgb(0, 0, 255, 0));
		}
	}
}

void	ft_color_door(t_master *s_m, int x, int y, int c)
{
	int	x;
	int	y;

	if (s_m->minimap)
	{
		y * 16;
		x * 16;
	}
	else
	{
		y * 8;
		x * 8;
	}
	if (c == 3)
		img_pix_put(&s_m->img, w, h, create_trgb(0, 255, 255, 255));
}

void	ft_draw_square(t_master *s_m, int x, int y, int c)
{
	int	i;
	int	j;
	int w;
	int h;

	i = 7;
	if (s_m->minimap)
		ft_map(s_m, x, y, c);
	else
	{
		while (++i <= 16)
		{
			j = 7;
			h = i + y * 8;
			while (++j <= 16)
			{
				w = j + x * 8;
				if (c == 1)
					img_pix_put(&s_m->img, w, h, create_trgb(0, 107, 107, 107));
            	else if (c == 2)
					img_pix_put(&s_m->img, w, h, create_trgb(0, 0, 255, 0));
			}
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
			else if (map[y][x] == 'P')
				ft_draw_square(s_m, x, y, 2);
			else if (map[y][x] == 'D')
				ft_color_door(s_m, x, y);
		}
	}
}
