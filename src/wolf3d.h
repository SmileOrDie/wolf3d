/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:20:35 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/05 21:19:39 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WOLF3D_H
# define _WOLF3D_H

# include <mlx.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <sys/time.h>
# include <X11/xlib.h>
# include <X11/cursorfont.h>

# include <stdio.h>

# define BLACK 0x000000
# define RED 0xFF0000
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define WHITE 0xFFFFFF
# define GRIS 0xA9A9A9
# define CHOCO 0xD2691E
# define N 20
# define M 20
# define NB N*M

# define ABS(x) ((x >= 0) ? x : -(x))

typedef struct		s_terrain
{
	int				val;
	int				altitude;
}					t_terrain;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_move
{
	struct timeval	time;
	long			usec;
	long			sec;
	double			movespeed;
	double			rotspeed;
	double			old_dirx;
	double			old_planex;
}					t_move;

typedef struct		s_tex
{
	void			*text;
	int				w;
	int				h;
	int				bpp;
	int				sizeline;
	int				endian;
	char			*textur;
}					t_tex;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	t_tex			tex;
	t_tex			sol;
	t_tex			w;
	int				weapon;
	int				**map;
	int				bpp;
	int				sizeline;
	int				endian;
	int				y_max;
	int				x_max;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				x;
	int				y;
	int				tmp_x;
	int				tmp_y;
	int				width;
	int				height;
	int				poscursx;
	int				poscursy;
	int				mc;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	double			run_m;
	double			run_r;
	double			tmp;
	double			tmp2;
	double			old_time;
	double			time;
	double			frame_time;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	t_color			c;
	t_move			move;
}					t_env;

void				convert(char *str, t_env *e, int ret, int fd);
char				*ft_freejoin(char *line, char *line2);
void				ft_free_tab_char(char ***tab);
void				ft_map(t_env *e, t_tabi *map);

int					expose_hook(t_env *e);
void				vertical_line(t_env *e, int start, int end);
t_color				get_color(int r, int g, int b);

void				ft_loop_hit(t_env *e);
void				hit_side(t_env *e);
void				draw_lite2(t_env *e);
void				ft_clearimg(char *data, size_t xmax, size_t ymax);

void				draw_lite(t_env *e);
int					key_hook(int key, t_env *e);

void				check_where(t_env *e);
void				init_env(t_env *e);
void				print_map(t_env *e);

void				ft_move_b(t_env *e);
void				ft_move_f(t_env *e);
void				ft_move_l(t_env *e);
void				ft_move_r(t_env *e);
void				ft_move_lat(t_env *e, int i);

void				env_mlx(t_env e);
int					mouse_hook(int x, int y, t_env *e);
void				print_key(t_env *e);
void				print_croix(t_env *e);

void				init_terrain(t_env *e);

int					inf(int i, int j);
void				propager(int ligne, int colonne, int valeur,
							t_terrain tab[2 * N + 1][2 * M + 1]);
void				enumerer(int ligne, int colonne, int valeur,
							t_terrain tab[2 * N + 1][2 * M + 1]);
void				creer_labyrente(t_terrain tab[2 * N + 1][2 * M + 1]);
void				creer_nouveau_pont(t_terrain tab[2 * N + 1][2 * M + 1]);

void				creer_un_pont(t_terrain tab[2 * N + 1][2 * M + 1]);
void				map_key(int key, t_env *e);
void				ft_free_tab_int(int **tab, int y);

void				put_weapon(t_env *e);
void				change_weapon(t_env *e, int key);

#endif
