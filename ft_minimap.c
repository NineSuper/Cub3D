/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:59:35 by tde-los-          #+#    #+#             */
/*   Updated: 2023/08/20 16:40:46 by tde-los-         ###   ########.fr       */
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

	i = -1;
	while (++i <= 8)
	{
		j = -1;
		h = i + y * 8;
		while (++j <= 8)
		{
			w = j + x * 8;
			if (c == 1)
				mlx_pixel_put(s_m->mlx, s_m->win, w, h, create_trgb(0, 255, 0, 0));
            else if (c == 2)
                mlx_pixel_put(s_m->mlx, s_m->win, w, h, create_trgb(0, 0, 199, 13));
            else
                mlx_pixel_put(s_m->mlx, s_m->win, w, h, create_trgb(0, 0, 0, 0));
		}
	}
}

void	ft_minimap(t_master *s_m, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				ft_draw_square(s_m, j, i, 1);
			else if (map[i][j] == 'N') // ! A modifer par 'P' pour player a l'avenir
				ft_draw_square(s_m, j, i, 2);
            else
                ft_draw_square(s_m, j, i, 0);
		}
	}
}