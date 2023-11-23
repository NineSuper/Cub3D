/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:41:26 by tde-los-          #+#    #+#             */
/*   Updated: 2023/11/23 11:51:51 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <math.h>

/*
? Savoir l'orientation du joueur
* Projeter un mur
* Mettre la couleur sur le ciel/sol
? Mettre des textures sur les murs
* Faire Bouger la camera
* Faire Bouger le Joueur
? Collision avec les murs
* Minimap
? Systeme de porte (ouverture/fermeture)
! width / X = largeur
! height / Y = Hauteur
*/

void	ft_init_ray(t_player *player, int x)
{
	if (!player->posX && !player->posY)
	{
		player->posX = player->x;
		player->posY = player->y;
	}
	player->cameraX = 2 * (double)x / (double)WIDTH - 1;
	player->rayDirX = player->dirX + player->planeX * player->cameraX;
	player->rayDirY = player->dirY + player->planeY * player->cameraX;
	player->mapX = (int)player->posX;
	player->mapY = (int)player->posY;
	player->deltaDistX = (1 / player->rayDirX) * \
		(1 - (2 * (1 / player->rayDirX < 0)));
	player->deltaDistY = (1 / player->rayDirY) * \
		(1 - (2 * (1 / player->rayDirY < 0)));
}

void	ft_step(t_player *player)
{
	if (player->rayDirX < 0)
	{
		player->stepX = -1;
		player->sideDistX = (player->posX - player->mapX) * \
			player->deltaDistX;
	}
	else
	{
		player->stepX = 1;
		player->sideDistX = (player->mapX + 1.0 - player->posX) * \
			player->deltaDistX;
	}
	if (player->rayDirY < 0)
	{
		player->stepY = -1;
		player->sideDistY = (player->posY - player->mapY) * \
			player->deltaDistY;
	}
	else
	{
		player->stepY = 1;
		player->sideDistY = (player->mapY + 1.0 - player->posY) * \
			player->deltaDistY;
	}
}

void	ft_dda(t_player *player, char **map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (player->sideDistX < player->sideDistY)
		{	
			player->sideDistX += player->deltaDistX;
			player->mapX += player->stepX;
			player->side = 0;
		}
		else
		{
			player->sideDistY += player->deltaDistY;
			player->mapY += player->stepY;
			player->side = 1;
		}
		if (map[player->mapY][player->mapX] == '1')
			hit = 1;
	}
}

double	ft_per_wall(t_player *player)
{
	double	perp_wall_dist;

	if (player->side == 0)
		perp_wall_dist = fabs((player->mapX - player->posX \
			+ (1 - player->stepX) / 2) / player->rayDirX);
	else
		perp_wall_dist = fabs((player->mapY - player->posY \
			+ (1 - player->stepY) / 2) / player->rayDirY);
	return (perp_wall_dist);
}

void	ft_ray(t_master *s_m, t_player *player, char **map)
{
	int	x;
	int	lineheight;
	int	drawstart;
	int	drawend;

	x = -1;
	while (++x < WIDTH)
	{
		ft_init_ray(player, x);
		ft_step(player);
		ft_dda(player, map);
		lineheight = (int)(HEIGHT / ft_per_wall(player));
		drawstart = -lineheight / 2 + HEIGHT / 2;
		if (drawstart < 0)
			drawstart = 0;
		drawend = lineheight / 2 + HEIGHT / 2;
		if (drawend >= HEIGHT)
			drawend = HEIGHT - 1;
		ft_verline(s_m, x, (t_draw){drawstart, drawend});
	}
}
