/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 00:17:04 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/05 21:41:49 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_step(t_env *e)
{
	if (e->raydirx < 0)
	{
		e->stepx = -1;
		e->sidedistx = (e->rayposx - e->mapx) * e->deltadistx;
	}
	else
	{
		e->stepx = 1;
		e->sidedistx = (e->mapx + 1.0 - e->rayposx) * e->deltadistx;
	}
	if (e->raydiry < 0)
	{
		e->stepy = -1;
		e->sidedisty = (e->rayposy - e->mapy) * e->deltadisty;
	}
	else
	{
		e->stepy = 1;
		e->sidedisty = (e->mapy + 1.0 - e->rayposy) * e->deltadisty;
	}
}

void			draw_lite(t_env *e)
{
	e->x = -1;
	while (++e->x < e->width)
	{
		draw_lite2(e);
		ft_step(e);
		ft_loop_hit(e);
		if (e->side == 0 || e->side == 1)
			e->perpwalldist =
				ABS((e->mapx - e->rayposx + (1 - e->stepx) / 2) / e->raydirx);
		else
			e->perpwalldist =
				ABS((e->mapy - e->rayposy + (1 - e->stepy) / 2) / e->raydiry);
		e->lineheight = ABS((int)(e->height / e->perpwalldist));
		e->drawstart = -e->lineheight / 2 + e->y;
		if (e->drawstart < 0)
			e->drawstart = 0;
		e->drawend = e->lineheight / 2 + e->y;
		hit_side(e);
		if (e->drawend >= e->height)
			e->drawend = e->height - 1;
		vertical_line(e, e->drawstart, e->drawend);
	}
}

void			final_hook(int key, t_env *e)
{
	if (key == 65457)
		ft_move_l(e);
	if (e->map[(int)e->posx][(int)e->posy] == 2 &&
		(key == 113 || key == 114 || key == 116))
		map_key(key, e);
	draw_lite(e);
	change_weapon(e, key);
	put_weapon(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (e->map[(int)e->posx][(int)e->posy] == 2)
		print_key(e);
	else
		print_croix(e);
	if (key == 109)
		print_map(e);
	ft_clearimg(e->data, e->width, e->height);
}

int				key_hook(int key, t_env *e)
{
	if (key == 65307)
		exit(0);
	if (key == 65364)
		ft_move_f(e);
	else if (key == 65362)
		ft_move_b(e);
	if (key == 65363)
		ft_move_lat(e, 0);
	else if (key == 65361)
		ft_move_lat(e, 1);
	if (key == 65461 && e->y < e->height - e->height / 4)
		e->y += 5;
	else if (key == 65458 && e->y > e->height / 4)
		e->y -= 5;
	if (key == 65459)
		ft_move_r(e);
	else if (key == 97)
	{
		if (e->run_m == e->move.movespeed)
			e->move.movespeed = e->run_r;
		else
			e->move.movespeed = e->run_m;
	}
	final_hook(key, e);
	return (0);
}
