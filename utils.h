/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:59:47 by tde-los-          #+#    #+#             */
/*   Updated: 2023/07/07 16:22:35 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
/*      Libft       */
# include "libft/libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/gnl/get_next_line.h"
# include "libft/mlx/mlx.h"
# include "libft/mlx/mlx_int.h"
/*		String		*/
#define text_load "Chargement des textures.."
#define map_load "Chargement de la map"
/*		Texture		*/
#define MENU_1 "texture/menu/menu_1.xpm"
#define MENU_2 "texture/menu/menu_2.xpm"
#define MENU_3 "texture/menu/menu_3.xpm"
#define MENU_4 "texture/menu/menu_4.xpm"

typedef struct s_key
{
	int	w;
	int q;
	int s;
	int d;
}	t_key;

typedef struct s_map
{
	
}	t_map;

typedef struct s_menu
{
	char	*menu_d; // menu par defaut
	char	*menu_p;
	char	*menu_o;
	char	*menu_q;
	int		borderSize;
	int 	width;
	int 	height;
	int		choose;
	int 	w;
	int 	h;
}	t_menu;

typedef struct s_player
{

}	t_player;

typedef struct s_master
{
    t_player	player;
	t_menu	menu;
	t_key	key;
	t_map	map;
	char	*mlx;
	char	*win;
	int		*m_x;
	int		*m_y;
	int screen;
	int	width;
	int height;
}	t_master;

void    ft_menu(t_master *s_m);
void	ft_loader_b(t_master *s_m, void *mlx, void *win);
void	imgs_load_menu(t_master *s_m);
int		deal_key(int key, t_master *s_m);

#endif