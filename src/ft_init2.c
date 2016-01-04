/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 13:00:30 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/05 13:29:11 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_loop_hit(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->sidedistx < e->sidedisty)
		{
			e->sidedistx += e->deltadistx;
			e->mapx += e->stepx;
			if (e->stepx < 0)
				e->side = 0;
			else
				e->side = 1;
		}
		else
		{
			e->sidedisty += e->deltadisty;
			e->mapy += e->stepy;
			if (e->stepy < 0)
				e->side = 2;
			else
				e->side = 3;
		}
		if (e->map[e->mapx][e->mapy] > 0 && e->map[e->mapx][e->mapy] != 6)
			e->hit = 1;
	}
}

void			hit_side_2(t_env *e)
{
	if (e->side == 0)
	{
		if (e->map[e->mapx][e->mapy] == 5)
			e->c = get_color(0, 0, 129);
		else if (e->map[e->mapx][e->mapy] == 2 || e->map[e->mapx][e->mapy] == 3)
			e->c = get_color(129, 255, 129);
		else if (e->map[e->mapx][e->mapy] == 1)
			e->c = get_color(0, 129, 0);
		else if (e->map[e->mapx][e->mapy] == 4)
			e->c = get_color(129, 0, 0);
	}
	else if (e->side == 2)
	{
		if (e->map[e->mapx][e->mapy] == 5)
			e->c = get_color(0, 0, 255);
		else if (e->map[e->mapx][e->mapy] == 4)
			e->c = get_color(255, 0, 0);
		else if (e->map[e->mapx][e->mapy] == 2 || e->map[e->mapx][e->mapy] == 3)
			e->c = get_color(255, 255, 255);
		else if (e->map[e->mapx][e->mapy] == 1)
			e->c = get_color(0, 255, 0);
	}
}

void			hit_side(t_env *e)
{
	if (e->side == 1)
	{
		if (e->map[e->mapx][e->mapy] == 5)
			e->c = get_color(129, 0, 129);
		else if (e->map[e->mapx][e->mapy] == 4)
			e->c = get_color(129, 129, 0);
		else if (e->map[e->mapx][e->mapy] == 2 || e->map[e->mapx][e->mapy] == 3)
			e->c = get_color(129, 129, 129);
		else if (e->map[e->mapx][e->mapy] == 1)
			e->c = get_color(0, 129, 129);
	}
	else if (e->side == 3)
	{
		if (e->map[e->mapx][e->mapy] == 5)
			e->c = get_color(255, 0, 255);
		else if (e->map[e->mapx][e->mapy] == 4)
			e->c = get_color(255, 255, 0);
		else if (e->map[e->mapx][e->mapy] == 2 || e->map[e->mapx][e->mapy] == 3)
			e->c = get_color(255, 129, 255);
		else if (e->map[e->mapx][e->mapy] == 1)
			e->c = get_color(0, 255, 255);
	}
	else
		hit_side_2(e);
}

void			draw_lite2(t_env *e)
{
	e->camerax = (2 * e->x / ((double)e->width) - 1);
	e->rayposx = e->posx;
	e->rayposy = e->posy;
	if (e->planex != 0)
		e->raydirx = e->dirx + e->planex * e->camerax;
	else
		e->raydirx = e->dirx;
	e->raydiry = e->diry + e->planey * e->camerax;
	e->mapx = (int)e->rayposx;
	e->mapy = (int)e->rayposy;
	e->tmp = e->raydiry * e->raydiry;
	e->tmp2 = e->raydirx * e->raydirx;
	e->deltadistx = sqrt(1 + e->tmp / e->tmp2);
	e->deltadisty = sqrt(1 + e->tmp2 / e->tmp);
	e->hit = 0;
}

void			ft_clearimg(char *data, size_t xmax, size_t ymax)
{
	char		*pos;
	size_t		x;
	size_t		y;

	y = 0;
	pos = data;
	while (y < ymax)
	{
		x = 0;
		while (x < xmax)
		{
			*pos++ = 0;
			*pos++ = 0;
			*pos++ = 0;
			*pos++ = 0;
			x++;
		}
		y++;
	}
}
