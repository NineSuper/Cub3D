/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:34:01 by tde-los-          #+#    #+#             */
/*   Updated: 2023/10/20 15:20:46 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	put_img_to_img(t_imgs dst, t_imgs srcs, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < srcs.w)
	{
		j = -1;
		while (++j < srcs.h)
			put_pixel_img(dst, x + i, y + j, get_pixel_img(srcs, i, j));
	}
}

void	ft_put_destroy(t_imgs src, t_imgs dest, int x, int y)
{
	put_img_to_img(dest, src, x, y);
	ft_destroy_img(src.mlx, src.m_img);
}

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

t_imgs	new_img(int w, int h, t_master *s_m)
{
	t_imgs	image;

	image.win = s_m->win;
	image.mlx = s_m->mlx;
	image.m_img = mlx_new_image(s_m->mlx, w, h);
	image.addr = mlx_get_data_addr(image.m_img, &(image.bpp),
			&(image.l_len), &(image.end));
	image.w = w;
	image.h = h;
	return (image);
}
