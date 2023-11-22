/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:05:02 by tde-los-          #+#    #+#             */
/*   Updated: 2023/11/22 11:32:11 by tde-los-         ###   ########.fr       */
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

void	ft_ray(t_master *s_m, t_player *player)
{
	if (!player->posX && !player->posY)
	{
		player->posX = player->x;
		player->posY = player->y;
	}
	else
	{
		player->posX = player->posX;
		player->posY = player->posY;
	}
	player->dirX = 0;
	player->dirY = 1;
	player->planeX = 0;
	player->planeY = 0.66;

	int x = -1;
	while (++x < WIDTH)
	{
		double	cameraX = 2 * x / (double)WIDTH - 1;
		double	rayDirX = player->dirX + player->planeX * cameraX;
		double	rayDirY = player->dirY + player->planeY * cameraX;

		int	mapX = (int)player->posX;
		int mapY = (int)player->posY;

		double sideDistX;
		double sideDistY;

		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		double	perpWallDist;

		int	stepX;
		int	stepY;

		int	hit = 0;
		int	side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (player->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - player->posX) * deltaDistX;
		}
		if (rayDirY < 0)
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
			{
				hit = 1;
			}
		}
		if (side == 0)
			perpWallDist = (sideDistX + deltaDistX);
		else
			perpWallDist = (sideDistY + deltaDistY);

		int lineHeight = (perpWallDist != 0) ? (int)(HEIGHT / perpWallDist) : HEIGHT;

		int drawStart = -lineHeight / 2 + HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if (drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;

		int	color = create_trgb(0, 0, 0, 255);

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

	ft_ray(s_m, &s_m->player);
	//ft_rplace(s_m, s_m->no, s_m->img, (t_coords){30, 80, 800, 800});
	
	ft_minimap(s_m, ft_backmap(s_m, s_m->map.map));
	ft_hud(s_m);
	mlx_put_image_to_window(s_m->mlx, s_m->win, s_m->img.m_img, 0, 0);
	if (!s_m->help)
		ft_text(s_m);
}
