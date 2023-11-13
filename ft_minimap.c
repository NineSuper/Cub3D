/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:59:35 by tde-los-          #+#    #+#             */
/*   Updated: 2023/11/13 08:22:41 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
* Minimap : Afficher les murs/portes
* ft_map : aggrandir la map
? Afficher le joueur en temps direct 
*/

int	color_case(int c)
{
	if (c == 1)
		return (create_trgb(0, 107, 107, 107));
	if (c == 2)
		return (create_trgb(0, 0, 255, 0));
	if (c == 3)
		return (create_trgb(0, 255, 255, 255));
	if (c == 4)
		return (create_trgb(0, 0, 162, 255));
	if (c == 5)
		return (create_trgb(0, 51, 0, 0));
}

void	ft_map(t_master *s_m, int x, int y, int c)
{
	int	i;
	int	j;
	int	w;
	int	h;

	i = 15;
	while (++i <= 32)
	{
		j = 15;
		h = i + y * 16;
		while (++j <= 32)
		{
			w = j + x * 16;
			img_pix_put(&s_m->img, w, h, color_case(c));
		}
	}
}

void	ft_draw_square(t_master *s_m, int x, int y, int c)
{
	int	i;
	int	j;
	int	w;
	int	h;

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
				img_pix_put(&s_m->img, w, h, color_case(c));
			}
		}
	}
}

void	ft_border(t_master *s_m)
{
	int	x;
	int	y;

	y = 7;
	while (y++ <= 16)
	{
		img_pix_put(&s_m->img, w, h, color_case(c));
	}
}

void	ft_minimap(t_master *s_m, char **map)
{
	int	x;
	int	y;

	y = -1;
	ft_border(s_m);
	while (map[++y])
	{
		x = -1;
		/*while (map[y][++x])
		{
			if (map[y][x] == '1')
				ft_draw_square(s_m, x, y, 1);
			if (map[y][x] == 'D')
				ft_draw_square(s_m, x, y, 3);
			else if (map[y][x] == 'B')
				ft_draw_square(s_m, x, y, 4);
			else if (map[y][x] == 'P')
				ft_draw_square(s_m, s_m->player.x, s_m->player.y, 2);
		}*/
	}
}

/*
#define MINIMAP_WIDTH 200
#define MINIMAP_HEIGHT 150

void draw_minimap_border(void *mlx, void *win)
{
    int x, y;

    // Dessiner le contour supérieur
    x = (WIDTH - MINIMAP_WIDTH) / 2;
    for (y = 0; y < MINIMAP_HEIGHT; ++y)
        mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);

    // Dessiner le contour inférieur
    x = (WIDTH - MINIMAP_WIDTH) / 2 + MINIMAP_WIDTH;
    for (y = 0; y < MINIMAP_HEIGHT; ++y)
        mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);

    // Dessiner le contour gauche
    y = 0;
    for (x = (WIDTH - MINIMAP_WIDTH) / 2; x < (WIDTH - MINIMAP_WIDTH) / 2 + MINIMAP_WIDTH; ++x)
        mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);

    // Dessiner le contour droit
    y = MINIMAP_HEIGHT;
    for (x = (WIDTH - MINIMAP_WIDTH) / 2; x < (WIDTH - MINIMAP_WIDTH) / 2 + MINIMAP_WIDTH; ++x)
        mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
}

*/