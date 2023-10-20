/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:28:22 by tde-los-          #+#    #+#             */
/*   Updated: 2023/10/20 16:35:32 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
    *   ft_coords = renvoie une structure avec la hauteur/largeur puis les coordonnes x et y
    *   d'un element
*/

t_coords	ft_coords(int h, int w, int x, int y)
{
	t_coords coords;

	coords.h = h;
	coords.w = w;
	coords.x = x;
	coords.y = y;
	return (coords);
}

/*
    *   ft_rplace = redimensionne une image avec l'aide de ft_coords
    *   puis la place sur une image dest
    *   puis detruit l'image en tempon
*/

void	ft_rplace(t_master *s_m, t_imgs src, t_imgs dest, t_coords coords)
{
	t_imgs temp;

	temp = ft_img_resize(s_m, src, coords.h, coords.w);
	ft_put_destroy(temp, dest, coords.x, coords.y);
}

void	ft_put_destroy(t_imgs src, t_imgs dest, int x, int y)
{
	put_img_to_img(dest, src, x, y);
	ft_destroy_img(src.mlx, src.m_img);
}

/*
    *   ft_img_resize
    *   redimensionne une image avec une hauteur et une largeur defini
*/

t_imgs	ft_img_resize(t_master *s_m, t_imgs img, int h, int w)
{
	t_imgs	img_resized;
	int		x;
	int		y;
	int		color;

	if (h >= img.h)
		h = img.h;
	if (w >= img.w)
		w = img.w;
	if (h <= 1)
		h = 1;
	if (w <= 1)
		w = 1;
	img_resized = new_img(w, h, s_m);
	y = -1;
	while (++y < h)
	{
		x = -1;
		while (++x < w + 1)
		{
			color = get_pixel_img(img, (x * img.w) / w, (y * img.h) / h);
			put_pixel_img(img_resized, x, y, color);
		}
	}
	return (img_resized);
}