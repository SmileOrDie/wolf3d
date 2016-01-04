/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 00:15:25 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/05 17:44:33 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_color			get_color(int r, int g, int b)
{
	t_color		get;

	get.r = r;
	get.g = g;
	get.b = b;
	return (get);
}

void			put_pixel_to_img(t_env *e, int pos, t_color c, char *data)
{
	if (e->endian)
	{
		data[pos] =
			mlx_get_color_value(e->mlx, c.r);
		data[pos + 1] =
			mlx_get_color_value(e->mlx, c.g);
		data[pos + 2] =
			mlx_get_color_value(e->mlx, c.b);
	}
	else
	{
		e->data[pos] =
			mlx_get_color_value(e->mlx, c.b);
		e->data[pos + 1] =
			mlx_get_color_value(e->mlx, c.g);
		e->data[pos + 2] =
			mlx_get_color_value(e->mlx, c.r);
	}
}

void			put_ciel_to_img(t_env *e, int pos, char *data)
{
	data[pos] = e->tex.textur[pos + e->mc];
	data[pos + 1] = e->tex.textur[pos + 1 + e->mc];
	data[pos + 2] = e->tex.textur[pos + 2 + e->mc];
}

void			vertical_line(t_env *e, int start, int end)
{
	int			x;
	int			y;

	x = e->x * (e->bpp / 8);
	end *= e->sizeline;
	start *= e->sizeline;
	y = 0;
	while (y < end)
	{
		if (y < start)
			put_ciel_to_img(e, x + y, e->data);
		else if (start < end)
		{
			put_pixel_to_img(e, x + start, e->c, e->data);
			start += e->sizeline;
		}
		y += e->sizeline;
	}
}

int				expose_hook(t_env *e)
{
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
