/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:59:47 by tde-los-          #+#    #+#             */
/*   Updated: 2023/07/06 13:26:38 by tde-los-         ###   ########.fr       */
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

// * Struct M

typedef struct s_key
{
	int	f; //* front
	int b; //* back
	int l; //* gauche 
	int r; //* droite
}	t_key;

typedef struct s_map
{
	char	**map;
	int		h;
	int		w;
}	t_map;

typedef struct s_menu
{

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
}	t_master;

char    *ft_menu(t_master *s_m);

#endif