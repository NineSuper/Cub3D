/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumontgo <lumontgo@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:59:47 by tde-los-          #+#    #+#             */
/*   Updated: 2024/01/10 16:33:35 by lumontgo         ###   ########.fr       */
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
# include "../libft/libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/gnl/get_next_line.h"
# include "../libft/mlx/mlx.h"
# include "../libft/mlx/mlx_int.h"
# include <math.h>
/*		String		*/
# define TEXT_LOAD "Chargement des textures.."
# define MAP_LOAD "Chargement de la map"
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
# define CROSS	"texture/crosshair/green.xpm"
# define CURSOR "texture/cursor.xpm"
# define DOOR "texture/wall/door.xpm"
# define EXIT "texture/wall/exit.xpm"
/*		Color		*/
# define C_GREEN "\033[1;32m"
# define C_RED "\033[1;41m"

typedef struct s_key
{
	char	key_table[255];
	int		w;
	int		q;
	int		s;
	int		d;
	int		e;
}	t_key;

typedef struct s_dir
{
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}	t_dir;

typedef struct s_draw
{
	int	drawstart;
	int	drawend;
}	t_draw;

typedef struct s_map
{
	char	**map;
	char	*level;
	char	*ea;
	char	*no;
	char	*so;
	char	*we;
	int		c_f;
	int		c_c;
	int		fd;
	int		len;
	int		player;
	int		width;
}	t_map;

typedef struct s_menu
{
	char	*menu_d;
	char	*menu_p;
	char	*menu_o;
	char	*menu_q;
	int		bordersize;
	int		width;
	int		height;
	int		choose;
	int		w;
	int		h;
}	t_menu;

typedef struct s_imgs
{
	void	*win;
	void	*mlx;
	void	*m_img;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		l_len;
	int		end;
}	t_imgs;

typedef struct s_player
{
	t_imgs	cross;
	t_imgs	target;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	perpwalldist;
	double	deltadistx;
	double	deltadisty;
	double	wallx;
	double	step;
	double	texposx;
	double	texpos;
	int		lineheight;
	int		texy;
	int		texx;
	int		hit;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		x;
	int		y;
	int		side;
}	t_player;

typedef	struct s_fill
{
	int	x;
	int	y;
}	t_fill;


typedef struct s_coods
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_coords;

typedef struct s_master
{
	t_player	player;
	t_menu		menu;
	t_key		key;
	t_map		map;
	t_imgs		img;
	t_imgs		cursor;
	t_imgs		skyfloor;
	t_imgs		door;
	t_imgs		exit;
	t_imgs		ea;
	t_imgs		no;
	t_imgs		so;
	t_imgs		we;
	char		*mlx;
	char		*win;
	int			m_x;
	int			m_y;
	int			minimap;
	int			screen;
	int			width;
	int			height;
	int			help;
	int			hud;
	int			error;
}	t_master;

unsigned int	get_pixel_img(t_imgs img, int x, int y);
double			ft_per_wall(t_player *player);
t_imgs			new_img(int w, int h, t_master *s_m);
t_imgs			new_file_img(char *path, t_master *s_m);
t_imgs			ft_img_resize(t_master *s_m, t_imgs img, int h, int w);
t_coords		ft_coords(int h, int w, int x, int y);
char			*ft_split_text(char *str);
char			*ft_space(char *str);
void			ft_rplace(t_master *s_m, t_imgs src, t_imgs dest, \
	t_coords coords);
void			ft_set_dir(t_master *s_m, char c, char *str);
void			ft_init_resize(t_master *s_m);
void			put_pixel_img(t_imgs img, int x, int y, int color);
void			put_img_to_img(t_imgs dst, t_imgs srcs, int x, int y);
void			ft_print_tab(char **tab);
void			ft_get_menu(int i, t_master *s_m);
void			ft_menu(t_master *s_m);
void			ft_loader_b(t_master *s_m, void *mlx, void *win);
void			imgs_load_menu(t_master *s_m);
void			ft_check_map(t_master *s_m, char *map);
void			ft_error_map(char *error, t_master *s_m);
void			free_tab(char **tab);
void			ft_check_tab(t_master *s_m, t_map *s_map, char **map);
void			ft_play(t_master *s_m);
void			ft_raycast(t_master *s_m);
void			ft_minimap(t_master *s_m, char **map);
void			ft_mac_mouse_menu(int x, int y, t_master *s_m);
void			img_pix_put(t_imgs *imgs, int x, int y, int color);
void			ft_new_img(t_imgs *img, t_master *s_m, int width, int height);
void			ft_key_player(int key, t_master *s_m);
void			ft_mouse_play(int button, int x, int y, t_master *s_m);
void			ft_text(t_master *s_m);
void			ft_mac_hud(t_master *s_m);
void			ft_destroy_img(void *mlx, char *img);
void			ft_put_destroy(t_imgs src, t_imgs dest, int x, int y);
void			ft_hud(t_master *s_m);
void			ft_ray(t_master *s_m, t_player *player, char **map);
void			ft_verline(t_master *s_m, int x, t_draw draw);
void			ft_cam(int key, t_player *player, double rotSpeed);
void			ft_wall_sheets(t_player *player, t_master *s_m);
void			ft_texture(t_master *s_m, t_draw draw, int x, t_player *player);
void			ft_open_door(t_master *s_m, char **map);
void			ft_other_key(int key, t_master *s_m, char **map);
int				ft_press(int key);
int				ft_exit_menu(t_master *s_m);
int				ft_onscreen(t_master *s_m);
int				ft_mouse(int button, int x, int y, void *s_m);
int				deal_key(int key, t_master *s_m);
int				ft_check_color(t_master *s_m, char **tab, int i);
int				create_trgb(int t, int r, int g, int b);
int				ft_msg(char *str, t_master *s_m);
int				check_texture(char *NO, char *EA, char *SO, char *WE);
int				ft_check_x_y(int x, char c);
int				ft_check_resized(int base);
int				key_up(int key, t_master *s_m);

#endif
