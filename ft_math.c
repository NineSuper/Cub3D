/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo <lumontgo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:41:26 by tde-los-          #+#    #+#             */
/*   Updated: 2024/01/08 19:02:41 by lumontgo         ###   ########.fr       */
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
? Systeme de porte (ouverture)
! width / X = largeur
! height / Y = Hauteur
*/

void	ft_init_ray(t_player *player, int x)
{
	if (!player->posx && !player->posy)
	{
		player->posx = player->x;
		player->posy = player->y;
	}
	player->camerax = 2 * (double)x / (double)WIDTH - 1;
	player->raydirx = player->dirx + player->planex * player->camerax;
	player->raydiry = player->diry + player->planey * player->camerax;
	player->mapx = (int)player->posx;
	player->mapy = (int)player->posy;
	player->deltadistx = (1 / player->raydirx) * \
		(1 - (2 * (1 / player->raydirx < 0)));
	player->deltadisty = (1 / player->raydiry) * \
		(1 - (2 * (1 / player->raydiry < 0)));
}

void	ft_step(t_player *player)
{
	if (player->raydirx < 0)
	{
		player->stepx = -1;
		player->sidedistx = (player->posx - player->mapx) * \
			player->deltadistx;
	}
	else
	{
		player->stepx = 1;
		player->sidedistx = (player->mapx + 1.0 - player->posx) * \
			player->deltadistx;
	}
	if (player->raydiry < 0)
	{
		player->stepy = -1;
		player->sidedisty = (player->posy - player->mapy) * \
			player->deltadisty;
	}
	else
	{
		player->stepy = 1;
		player->sidedisty = (player->mapy + 1.0 - player->posy) * \
			player->deltadisty;
	}
}

/*
* Player->hit == 1 : Mur
* Player->hit == 2 : Portes
* Player->hit == 3 : Sortie
*/

void	ft_dda(t_player *player, char **map)
{
	player->hit = 0;
	while (player->hit == 0)
	{
		if (player->sidedistx < player->sidedisty)
		{	
			player->sidedistx += player->deltadistx;
			player->mapx += player->stepx;
			player->side = 0;
		}
		else
		{
			player->sidedisty += player->deltadisty;
			player->mapy += player->stepy;
			player->side = 1;
		}
		if (map[player->mapy][player->mapx] == '1')
			player->hit = 1;
		// if (map[player->mapy][player->mapx] == 'D')
		// 	player->hit = 2;
	}
}

double	ft_per_wall(t_player *player)
{
	double	perp_wall_dist;

	if (player->side == 0)
		perp_wall_dist = fabs((player->mapx - player->posx \
			+ (1 - player->stepx) / 2) / player->raydirx);
	else
		perp_wall_dist = fabs((player->mapy - player->posy \
			+ (1 - player->stepy) / 2) / player->raydiry);
	return (perp_wall_dist);
}

void	ft_texture(t_master *s_m, t_draw draw, int lineheight, int x)
{
	t_player	*player;
	double		wallX;
	int			textWidth = 1024;

	player = &s_m->player;
	if (player->side == 0)
		wallX = player->posy + player->perpwalldist * player->raydiry;
	else
		wallX = player->posx + player->perpwalldist * player->raydirx;
	wallX -= floor((wallX));
	int	texX = (int)(wallX * (double)textWidth);
	if (player->side == 0 && player->raydirx > 0)
		texX = textWidth - texX - 1;
	if (player->side == 1 && player->raydiry < 0)
		texX = textWidth - texX - 1;
	//printf("%d\n", texX);
	double step = 1.0 * textWidth / lineheight;
	double texPos = (draw.drawstart - textWidth / 2 + lineheight / 2) * step;
	while (draw.drawstart <= draw.drawend)
	{
		int texY = (int)(texPos) & (textWidth - 1);
		unsigned int color = get_pixel_img(s_m->no, 500, 620);
		//int color = s_m->so.addr[(textWidth * texY + texX)];
		// printf("%d %d\n", texX, texY);
		put_pixel_img(s_m->img, x, draw.drawstart++, color);
	}
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
		ft_texture(s_m, (t_draw){drawstart, drawend}, lineheight, x);
		//ft_verline(s_m, x, (t_draw){drawstart, drawend});
	}
}
