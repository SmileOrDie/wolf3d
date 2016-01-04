/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 17:06:22 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/06 10:48:55 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				mouse_hook(int x, int y, t_env *e)
{
	if (e->tmp_x > x)
		ft_move_l(e);
	else if (e->tmp_x < x)
		ft_move_r(e);
	if (e->tmp_y > y && e->y < (e->height - e->height / 4))
		e->y += 10;
	else if (e->tmp_y < y && e->y > e->height / 4)
		e->y -= 10;
	e->tmp_y = y;
	e->tmp_x = x;
	draw_lite(e);
	put_weapon(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (e->map[(int)e->posx][(int)e->posy] == 2)
		print_key(e);
	else
		print_croix(e);
	ft_clearimg(e->data, e->width, e->height);
	return (0);
}

void			env_mlx(t_env e)
{
	if (!(e.mlx = mlx_init()))
	{
		ft_putstr_fd("error << env >> not valid!\n", 2);
		exit(0);
	}
	e.win =
		mlx_new_window(e.mlx, e.width, e.height, "< Wolf3d > Project");
	e.tex.text =
		mlx_xpm_file_to_image(e.mlx,
							".img_wolf/ciel.xpm", &e.tex.w, &e.tex.h);
	e.tex.textur =
		mlx_get_data_addr(e.tex.text, &e.tex.bpp,
						&e.tex.sizeline, &e.tex.endian);
	e.img = mlx_new_image(e.mlx, e.width, e.height);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.sizeline, &e.endian);
	init_env(&e);
	mlx_expose_hook (e.win, expose_hook, &e);
	mlx_hook(e.win, MotionNotify, PointerMotionMask, mouse_hook, &e);
	mlx_hook(e.win, 2, 3, key_hook, &e);
	mlx_loop(e.mlx);
}

void			print_key(t_env *e)
{
	mlx_string_put(e->mlx, e->win, (e->width / 2),
				(e->height / 2) - 15, CHOCO, "TELEPORTEUR");
	mlx_string_put(e->mlx, e->win, (e->width / 2) - 40,
				(e->height / 2), GRIS, "Q = MAP ALEATOIR");
	mlx_string_put(e->mlx, e->win, (e->width / 2) - 40,
				(e->height / 2) + 15, GRIS, "R = petit terrain");
	mlx_string_put(e->mlx, e->win, (e->width / 2) - 40,
				(e->height / 2) + 30, GRIS, "T = tres grand terrain");
}

void			print_croix(t_env *e)
{
	mlx_string_put(e->mlx, e->win,
				(e->width / 2) - 2, (e->height / 2) - 7, GRIS, ">+<");
}
