/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 12:54:05 by shamdani          #+#    #+#             */
/*   Updated: 2015/01/26 11:26:50 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_move_f(t_env *e)
{
	e->tmp = (e->posx - e->dirx * e->move.movespeed);
	if ((int)e->tmp > 0 && (int)e->tmp < e->y_max &&
		(!e->map[(int)e->tmp][(int)e->posy] ||
		e->map[(int)e->tmp][(int)e->posy] == 2 ||
		e->map[(int)e->tmp][(int)e->posy] == 4 ||
		e->map[(int)e->tmp][(int)e->posy] == 6))
		e->posx = e->tmp;
	e->tmp = e->posy - e->diry * e->move.movespeed;
	if ((int)e->tmp > 0 && (int)(e->tmp) < e->x_max &&
		(!e->map[(int)e->posx][(int)e->tmp] ||
		e->map[(int)e->posx][(int)e->tmp] == 2 ||
		e->map[(int)e->posx][(int)e->tmp] == 4 ||
		e->map[(int)e->posx][(int)e->tmp] == 6))
		e->posy = e->tmp;
}

void		ft_move_b(t_env *e)
{
	e->tmp = e->posx + e->dirx * e->move.movespeed;
	if ((int)e->tmp > 0 && (int)e->tmp < e->y_max &&
		(!e->map[(int)e->tmp][(int)e->posy] ||
		e->map[(int)e->tmp][(int)e->posy] == 2 ||
		e->map[(int)e->tmp][(int)e->posy] == 4 ||
		e->map[(int)e->tmp][(int)e->posy] == 6))
		e->posx = e->tmp;
	e->tmp = e->posy + e->diry * e->move.movespeed;
	if ((int)e->tmp > 0 && (int)e->tmp < e->x_max &&
		(!e->map[(int)e->posx][(int)e->tmp] ||
		e->map[(int)e->posx][(int)e->tmp] == 2 ||
		e->map[(int)e->posx][(int)e->tmp] == 4 ||
		e->map[(int)e->posx][(int)e->tmp] == 6))
		e->posy = e->tmp;
}

void		ft_move_r(t_env *e)
{
	double	olddirx;
	double	oldplanex;

	olddirx = e->dirx;
	e->tmp = cos(-e->move.rotspeed);
	e->tmp2 = sin(-e->move.rotspeed);
	e->dirx = e->dirx * e->tmp - e->diry * e->tmp2;
	e->diry = olddirx * e->tmp2 + e->diry * e->tmp;
	oldplanex = e->planex;
	e->planex = e->planex * e->tmp - e->planey * e->tmp2;
	e->planey = oldplanex * e->tmp2 + e->planey * e->tmp;
	e->mc += 16;
}

void		ft_move_l(t_env *e)
{
	double	olddirx;
	double	oldplanex;

	olddirx = e->dirx;
	e->tmp = cos(e->move.rotspeed);
	e->tmp2 = sin(e->move.rotspeed);
	e->dirx = e->dirx * e->tmp - e->diry * e->tmp2;
	e->diry = olddirx * e->tmp2 + e->diry * e->tmp;
	oldplanex = e->planex;
	e->planex = e->planex * e->tmp - e->planey * e->tmp2;
	e->planey = oldplanex * e->tmp2 + e->planey * e->tmp;
	e->mc -= 16;
}

void		ft_move_lat(t_env *e, int i)
{
	double	tmp;

	tmp = e->move.rotspeed;
	e->move.rotspeed = 1.570796;
	if (i == 1)
	{
		ft_move_r(e);
		ft_move_f(e);
		ft_move_l(e);
	}
	else
	{
		ft_move_l(e);
		ft_move_f(e);
		ft_move_r(e);
	}
	e->move.rotspeed = tmp;
}
