/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 13:35:09 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/05 17:42:21 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			init_env(t_env *e)
{
	e->posx = 19.5;
	e->posy = 19.5;
	e->dirx = -1;
	e->diry = 0;
	e->planex = 0;
	e->poscursx = 0;
	e->poscursy = 0;
	e->planey = 0.66;
	e->y = e->height / 2;
	e->old_time = e->time;
	gettimeofday(&(e->move.time), NULL);
	e->move.usec = e->move.time.tv_usec;
	e->move.sec = e->move.time.tv_sec;
	e->time = ((e->move.sec) * 1000 + e->move.usec / 1000.0) + 0.5;
	e->frame_time = (e->time - e->old_time);
	e->move.movespeed = e->frame_time * 0.00000000000012;
	e->run_m = e->frame_time * 0.00000000000002;
	e->run_r = e->move.movespeed;
	e->move.rotspeed = e->frame_time * 0.00000000000003;
}

void			check_where(t_env *e)
{
	int			i;
	int			j;

	j = -1;
	while (++j < e->x_max)
	{
		i = -1;
		while (++i < e->y_max)
		{
			if (e->map[j][i] == 6)
			{
				e->posx = j + 0.5;
				e->posy = i + 0.5;
			}
		}
	}
}

void			print_scare(t_env *e, int x, int y, int color)
{
	int			i;
	int			j;

	j = 5;
	while (j > 0)
	{
		i = 5;
		while (i > 0)
		{
			mlx_pixel_put(e->mlx, e->win, i + (x * 5), j + (y * 5), color);
			i--;
		}
		j--;
	}
}

void			print_map(t_env *e)
{
	int			x;
	int			y;

	x = -1;
	while (++x < e->x_max)
	{
		y = -1;
		while (++y < e->y_max)
		{
			if (e->map[y][x] == 2)
				print_scare(e, x, y, CHOCO);
			else if (e->map[y][x] == 0)
				print_scare(e, x, y, BLACK);
			else
				print_scare(e, x, y, GRIS);
			if ((int)e->posx == y && (int)e->posy == x)
				print_scare(e, x, y, RED);
		}
	}
}
