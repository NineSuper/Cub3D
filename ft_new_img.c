/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:34:58 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/19 12:01:54 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	put_pixel_img(t_imgs img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.l_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

unsigned int	get_pixel_img(t_imgs img, int x, int y)
{
	return (*(unsigned int *)((img.addr
			+ (y * img.l_len) + (x * img.bpp / 8))));
}

t_imgs	new_file_img(char *path, t_master *s_m)
{
	t_imgs	image;

	image.win = s_m->win;
	image.mlx = s_m->mlx;
	image.m_img = mlx_xpm_file_to_image(s_m->mlx, path, &image.w, &image.h);
	if (!image.m_img)
	{
		printf("\033[1;41mERROR: %s n'existe pas\033[00m\n", path);
		ft_exit_menu(s_m);
	}
	image.addr = mlx_get_data_addr(image.m_img, &(image.bpp),
			&(image.l_len), &(image.end));
	return (image);
}

void	img_pix_put(t_imgs *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->l_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->end != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	ft_new_img(t_imgs *img, t_master *s_m)
{
	if (img->m_img)
		mlx_destroy_image(s_m->mlx, img->m_img);
	img->m_img = mlx_new_image(s_m->mlx, s_m->width, s_m->height);
	img->addr = mlx_get_data_addr(img->m_img, &img->bpp, \
		&img->l_len, &img->end);
}
