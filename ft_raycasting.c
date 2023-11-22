/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:05:02 by tde-los-          #+#    #+#             */
/*   Updated: 2023/11/22 10:25:17 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <math.h>

/*
Si 'N' : angle 0°
Si 'S' : angle 180°
Si 'E' : angle 90°
Si 'O' : angle 270°
? Savoir l'orientation du joueur
? Projeter un mur
* Mettre la couleur sur le ciel/sol
? Mettre des textures sur les murs
? Faire Bouger la camera
? Faire Bouger le Joueur
? Collision avec les murs
* Minimap
? Systeme de porte (ouverture/fermeture)
! width / X = largeur
! height / Y = Hauteur
*/

/*
	? put_img_to_img(s_m->img, s_m->cursor, s_m->m_x, s_m->m_y);
*/

void	ft_hud(t_master *s_m)
{
	if (WIDTH != 1920)
		return (ft_mac_hud(s_m));
	put_img_to_img(s_m->img, s_m->player.cross, (WIDTH / 2) - 64, \
		(HEIGHT / 2) - 64);
}

char	**ft_backmap(t_master *s_m, char **map)
{
	char	**temp_map;
	int		i;
	int		j;
	int		x;

	temp_map = ft_calloc(27, sizeof(char *) + 1);
	map += s_m->map.len;
	map[s_m->player.y][s_m->player.x] = 'P';
	i = s_m->player.y - 3;
	if (i < 0)
		i = 0;
	j = 0;
	x = s_m->player.x - 6;
	if (x < 0)
		x = 0;
	while (map[i] && i < s_m->player.y + 5)
		temp_map[j++] = ft_substr(map[i++], x, x + 8);
	return (temp_map);
}

void	ft_verline(t_master *s_m, int x, int drawstart, int drawend, int color)
{
	while (drawstart++ <= drawend)
		put_pixel_img(s_m->img, x, drawstart, color);
}

void	ft_ray(t_master *s_m)
{
	double	posX = s_m->player.x;
	double	posY = s_m->player.y;
	double	dirX = -1;
	double	dirY = 0;
	double	planeX = 0;
	double	planeY = 0.66;

	int x = -1;
	while (++x < WIDTH)
	{
		double	cameraX = 2 * x / (double)WIDTH - 1;
		double	rayDirX = dirX + planeX * cameraX;
		double	rayDirY = dirY + planeY * cameraX;

		int	mapX = (int)posX;
		int mapY = (int)posY;

		double sideDistX;
		double sideDistY;

		double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));

		double	perpWallDist;

		int	stepX;
		int	stepY;

		int	hit = 0;
		int	side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			// printf("%c\n", s_m->map.map[mapY][mapX]);
			if (s_m->map.map[mapY][mapX] == '1')
			{
				hit = 1;
			}
		}
		if (side == 0)
			perpWallDist = (sideDistX + deltaDistX);
		else
			perpWallDist = (sideDistY + deltaDistY);

		int lineHeight = (perpWallDist != 0) ? (int)(HEIGHT / perpWallDist) : HEIGHT;

		int drawStart;
		drawStart = -lineHeight / 2 + HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		
		int drawEnd;
		drawEnd = lineHeight / 2 + HEIGHT / 2;
		if (drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;

		int	color = create_trgb(0, 255, 0, 0);

		if (side == 1)
			{color = color / 2;}
		ft_verline(s_m, x, drawStart, drawEnd, color);
	}
}

void	ft_raycast(t_master *s_m, char **map)
{
	if (s_m->img.m_img)
		mlx_destroy_image(s_m->mlx, s_m->img.m_img);
	s_m->img = new_img(WIDTH, HEIGHT, s_m);
	put_img_to_img(s_m->img, s_m->skyfloor, 0, 0);

	ft_ray(s_m);
	//ft_rplace(s_m, s_m->no, s_m->img, (t_coords){30, 80, 800, 800});
	
	ft_minimap(s_m, ft_backmap(s_m, s_m->map.map));
	ft_hud(s_m);
	mlx_put_image_to_window(s_m->mlx, s_m->win, s_m->img.m_img, 0, 0);
	if (!s_m->help)
		ft_text(s_m);
}
