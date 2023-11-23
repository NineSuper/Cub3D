/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:05:02 by tde-los-          #+#    #+#             */
/*   Updated: 2023/11/23 10:26:05 by tde-los-         ###   ########.fr       */
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
	put_img_to_img(s_m->img, s_m->player.cross, (WIDTH / 2) - 32, \
		(HEIGHT / 2) - 32);
}

void	ft_verline(t_master *s_m, int x, int drawstart, int drawend, int color)
{
	while (drawstart <= drawend)
	{
		put_pixel_img(s_m->img, x, drawstart, color);
		drawstart++;
	}
}

void	ft_ray(t_master *s_m, t_player *player, char **map)
{
	int	x;

	x = -1;
	if (!player->posX && !player->posY)
	{
		player->posX = player->x;
		player->posY = player->y;
	}
	while (++x < WIDTH)
	{
		player->cameraX = 2 * (double)x / (double)WIDTH - 1;
		player->rayDirX = player->dirX + player->planeX * player->cameraX;
		player->rayDirY = player->dirY + player->planeY * player->cameraX;

		int	mapX = (int)player->posX;
		int mapY = (int)player->posY;

		double sideDistX;
		double sideDistY;

		double deltaDistX = (1 / player->rayDirX) * (1 - (2 * (1 / player->rayDirX < 0)));
		double deltaDistY = (1 / player->rayDirY) * (1 - (2 * (1 / player->rayDirY < 0)));

		double	perpWallDist;

		int	stepX;
		int	stepY;

		int	hit = 0;
		int	side;

		if (player->rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (player->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - player->posX) * deltaDistX;
		}
		if (player->rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (player->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - player->posY) * deltaDistY;
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
			if (s_m->map.map[mapY][mapX] == '1')
				hit = 1;
		};
		if (side == 0)
			perpWallDist = fabs((mapX - player->posX + (1 - stepX) / 2) / player->rayDirX);
		else
			perpWallDist = fabs((mapY - player->posY + (1 - stepY) / 2) / player->rayDirY);

		int	lineHeight = (int)(HEIGHT / perpWallDist);

		int drawStart = -lineHeight / 2 + HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if (drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;

		int	color = create_trgb(0, 255, 153, 51);

		if (side == 1)
			color = color / 2;
		ft_verline(s_m, x, drawStart, drawEnd, color);
	}
}


void	ft_raycast(t_master *s_m, char **map)
{
	if (s_m->img.m_img)
		mlx_destroy_image(s_m->mlx, s_m->img.m_img);
	s_m->img = new_img(WIDTH, HEIGHT, s_m);
	put_img_to_img(s_m->img, s_m->skyfloor, 0, 0);

	ft_ray(s_m, &s_m->player, s_m->map.map + s_m->map.len);
	//ft_rplace(s_m, s_m->no, s_m->img, (t_coords){30, 80, 800, 800});
	
	//ft_minimap(s_m, s_m->map.map + s_m->map.len);
	ft_hud(s_m);
	mlx_put_image_to_window(s_m->mlx, s_m->win, s_m->img.m_img, 0, 0);
	if (!s_m->help)
		ft_text(s_m);
}
