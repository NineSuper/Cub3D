/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:59:47 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/06 07:03:31 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
/*		Screen Size	 */
# ifndef WIDTH
#  define WIDTH 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 1080
# endif
/*      Libft       */
# include "libft/libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/gnl/get_next_line.h"
# include "libft/mlx/mlx.h"
# include "libft/mlx/mlx_int.h"
/*		String		*/
# define text_load "Chargement des textures.."
# define map_load "Chargement de la map"
# define READ_ERR "n'existe pas"
# define MSG_SIZE "Séléctionnez une résolution :\n1: 1920x1080\n2: 960x540\n"
# define ERROR_T "textures/couleurs pas a la norme"
# define ARGC "./Cub3D maps/(.cub)"
# define ERROR_C "une couleur n'est pas bonne"
# define MAP_NO "merci de mettre une map a la norme"
/*		Help string		*/
# define H_MAP "M: MAP"
# define H_HELP "H: on/off help"
# define H_ESC "ESC: Exit"
/*		Texture		*/
# define MENU_1 "texture/menu/menu_1.xpm"
# define MENU_2 "texture/menu/menu_2.xpm"
# define MENU_3 "texture/menu/menu_3.xpm"
# define MENU_4 "texture/menu/menu_4.xpm"
# define MENU_5 "texture/menu/menu_5.xpm"
# define MENU_6 "texture/menu/menu_6.xpm"
# define MENU_7 "texture/menu/menu_7.xpm"
# define MENU_8 "texture/menu/menu_8.xpm"
/*		Color		*/
# define C_GREEN "\033[1;32m"
# define C_RED "\033[1;41m"

typedef struct s_key
{
	int	w;
	int q;
	int s;
	int d;
}	t_key;

typedef struct s_map
{
	char	**map;
	char	*level;
	char	*EA;
	char	*NO;
	char	*SO;
	char	*WE;
	int		c_f;
	int		c_c;
	int		fd;
	int		len;
	int		player;
}	t_map;

typedef struct s_menu
{
	char	*menu_d;
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
	double	posX;
	double	posY;
	double	dirx;
	double	diry;
	double	planeX;
	double	planeY;
}	t_player;

typedef	struct s_imgs
{
    void	*m_img;
    char	*addr;
    int		bpp;
    int		l_len;
    int		end;
}	t_imgs;

typedef struct s_master
{
    t_player	player;
	t_menu	menu;
	t_key	key;
	t_map	map;
	t_imgs	img;
	char	*mlx;
	char	*win;
	char	*EA;
	char	*NO;
	char	*SO;
	char	*WE;
	int		m_x;
	int		m_y;
	int		minimap;
	int		screen;
	int		width;
	int 	height;
	int		help;
}	t_master;


char	*ft_split_text(char *str, t_master *s_m);
void	ft_set_dir(t_master *s_m, char c, char *str);
void	ft_print_tab(char **tab);
void	ft_get_menu(int i, t_master *s_m);
void    ft_menu(t_master *s_m);
void	ft_loader_b(t_master *s_m, void *mlx, void *win);
void	imgs_load_menu(t_master *s_m);
void	ft_check_map(t_master *s_m, char *map);
void	ft_error_map(char *error, t_master *s_m);
void	free_tab(char **tab);
void	ft_check_tab(t_master *s_m, t_map *s_map, char **map);
void	ft_play(t_master *s_m);
void	ft_raycast(t_master *s_m, char **map);
void	ft_minimap(t_master *s_m, char **map);
void	ft_mac_mouse_menu(int x, int y, t_master *s_m);
void	img_pix_put(t_imgs *imgs, int x, int y, int color);
void	ft_new_img(t_imgs *img, t_master *s_m);
void    ft_key_player(int key, t_master *s_m);
void    ft_mouse_play(int button, int x, int y, t_master *s_m);
void	ft_text(t_master *s_m);
int		ft_exit_menu(t_master *s_m);
int		ft_mouse(int button, int x, int y, void *s_m);
int		deal_key(int key, t_master *s_m);
int		ft_check_color(t_master *s_m, char **tab, int i);
int		create_trgb(int t, int r, int g, int b);
int		ft_msg(char *str, t_master *s_m);
int		check_texture(char *NO, char *EA, char *SO, char *WE);

#endif