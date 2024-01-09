/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo <lumontgo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:41:26 by tde-los-          #+#    #+#             */
/*   Updated: 2024/01/09 15:14:19 by lumontgo         ###   ########.fr       */
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
	player->camerax = (((double)x * 2) / (double)WIDTH) - 1;
	player->raydirx = player->dirx + (player->planex * player->camerax);
	player->raydiry = player->diry + (player->planey * player->camerax);
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
		player->sidedistx = (player->posx - player->mapx) *
			player->deltadistx;
	}
	else
	{
		player->stepx = 1;
		player->sidedistx = (player->mapx + 1.0 - player->posx) *
			player->deltadistx;
	}
	if (player->raydiry < 0)
	{
		player->stepy = -1;
		player->sidedisty = (player->posy - player->mapy) *
			player->deltadisty;
	}
	else
	{
		player->stepy = 1;
		player->sidedisty = (player->mapy + 1.0 - player->posy) *
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
	if (player->side == 0)
		player->perpwalldist = player->sidedistx - player->deltadistx;
	else
		player->perpwalldist = player->sidedisty - player->deltadisty;
	return (player->perpwalldist);
}

void	ft_texture(t_master *s_m, t_draw draw, int x)
{
	t_player	*player;
	unsigned int			color;

	s_m->so.addr = mlx_get_data_addr(s_m->so.m_img, &s_m->so.bpp, &s_m->so.l_len, &s_m->so.end);
	if (player->side == 0)
		player->wallx = player->posy + player->perpwalldist * player->raydiry;
	else
	player->wallx = player->posx + player->perpwalldist * player->raydirx;
	player->wallx -= floor(player->wallx);
	player->texx = (int)(player->wallx * (double)(s_m->so.w));
	if (player->side == 0 && player->raydirx > 0)
		player->texx = s_m->so.w - player->texx - 1;
	if (player->side == 1 && player->raydiry < 0)
		player->texx = s_m->so.w - player->texx - 1;
	player->step = 1.0 * s_m->so.h / player->lineheight;
	player->texpos = (draw.drawstart - HEIGHT / 2 + player->lineheight / 2) * player->step;
	int y = draw.drawstart;
	while (y < draw.drawend)
	{
		player->texy = (int)player->texpos & (s_m->so.h - 1);
		player->texpos += player->step;
		int color = (unsigned int)s_m->so.addr[s_m->so.h * player->texy + player->texx];
		put_pixel_img(s_m->img, x, y, color);
		y++;
	}
}

void	ft_ray(t_master *s_m, t_player *player, char **map)
{
	int	x;
	int	drawstart;
	int	drawend;

	x = -1;
	int	j = 0;
	//ft_rplace(s_m, s_m->so, s_m->img, (t_coords){200, 50, 256, 256});
	s_m->so = ft_img_resize(s_m, s_m->so, 16, 16);
	while (++x < WIDTH)
	{
		ft_init_ray(player, x);
		ft_step(player);
		ft_dda(player, map);
		ft_per_wall(player);
		player->lineheight = (int)(HEIGHT / player->perpwalldist);
		drawstart = ((-1 * player->lineheight) / 2) + (HEIGHT / 2);
		if (drawstart < 0)
			drawstart = 0;
		drawend = (player->lineheight / 2) + (HEIGHT / 2);
		if (drawend >= HEIGHT)
			drawend = HEIGHT - 1;
		if (s_m->help)
			ft_verline(s_m, x, (t_draw){drawstart, drawend});
 		else
 			ft_texture(s_m, (t_draw){drawstart, drawend}, x);
	}
}


// void	ft_ray(t_master *s_m, t_player *player, char **map)
// {
// 	int	x = 0;

// 	while (x < WIDTH)
// 	{
// 		if (!player->posx && !player->posy)
// 		{
// 			player->posx = player->x;
// 			player->posy = player->y;
// 		}	
// 		player->camerax = 2 * x / (double)WIDTH  - 1;
// 		player->raydirx = player->dirx + player->planex * player->camerax;
// 		player->raydiry = player->diry + player->planey * player->camerax;

// 		player->mapx = (int)player->posx;
// 		player->mapy = (int)player->posy;

// 		player->deltadistx = (1 / player->raydirx) * \
// 			(1 - (2 * (1 / player->raydirx < 0)));
// 		player->deltadisty = (1 / player->raydiry) * \
// 			(1 - (2 * (1 / player->raydiry < 0)));
		
// 		if (player->raydirx < 0)
// 		{
// 			player->stepx = -1;
// 			player->sidedistx = (player->posx - player->mapx) * player->deltadistx;
// 		}
// 		else
// 		{
// 			player->stepx = 1;
// 			player->sidedistx = (player->mapx + 1.0 - player->posx) * player->deltadistx;
// 		}
// 		if (player->raydiry < 0)
// 		{
// 			player->stepy = -1;
// 			player->sidedisty = (player->posy - player->mapy) * player->deltadisty;
// 		}
// 		else
// 		{
// 			player->stepy = 1;
// 			player->sidedisty = (player->mapy + 1.0 - player->posy) * player->deltadisty;
// 		}

// 		while (player->hit == 0)
// 		{
// 			if (player->sidedistx < player->sidedisty)
// 			{
// 				player->sidedistx += player->deltadistx;
// 				player->mapx += player->stepx;
// 				player->side = 0;
// 			}
// 			else
// 			{
// 				player->sidedisty += player->deltadisty;
// 				player->mapy += player->stepy;
// 				player->side = 1;
// 			}
// 			if (map[player->mapy][player->mapx] == '1')
// 				player->hit = 1;
// 		}

// 		if (player->side == 0)
// 			player->perpwalldist = (player->sidedistx - player->deltadistx);
// 		else
// 			player->perpwalldist = (player->sidedisty - player->deltadisty);

// 		player->lineheight = (int)(HEIGHT / player->perpwalldist);


// 		int drawstart = -player->lineheight / 2 + HEIGHT / 2;
// 		if (drawstart < 0)
// 			drawstart = 0;
// 		int drawend = player->lineheight / 2 + HEIGHT / 2;
// 		if (drawend >= HEIGHT)
// 			drawend = HEIGHT - 1;

// 		if (player->side == 0)
// 			player->wallx = player->posy + player->perpwalldist * player->raydiry;
// 		else
// 			player->wallx = player->posx + player->perpwalldist * player->raydirx;

// 		player->wallx -= floor(player->wallx);

// 		player->texx = (int)(player->wallx * (double)(s_m->so.w));
// 		if (player->side == 0 && player->raydirx > 0)
// 			player->texx = s_m->so.w - player->texx - 1;
// 		if (player->side == 1 && player->raydiry < 0)
// 			player->texx = s_m->so.w - player->texx - 1;
		
// 		player->step = 1.0 * s_m->so.h / player->lineheight;
// 		player->texpos = (drawstart - HEIGHT / 2 + player->lineheight / 2) * player->step;

// 		int y = drawstart;
// 		while (y < drawend)
// 		{
// 			player->texy = (int)player->texpos & (s_m->so.h - 1);
// 			player->texpos += player->step;
// 			int color = (unsigned int)s_m->so.addr[s_m->so.h * player->texy + player->texx];
// 			put_pixel_img(s_m->img, x, y, color);
// 			y++;
// 		}
// 		x++;
// 	}
// }