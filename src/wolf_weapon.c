/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 16:52:32 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/05 18:25:41 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void						get_weapon(t_env *e, char *weapon, int n)
{
	if (e->w.text)
		mlx_destroy_image(e->mlx, e->w.text);
	e->w.text = mlx_xpm_file_to_image(e->mlx, weapon, &e->w.w, &e->w.h);
	e->w.textur =
		mlx_get_data_addr(e->w.text, &e->w.bpp, &e->w.sizeline, &e->w.endian);
	e->weapon = n;
}

void						change_weapon(t_env *e, int key)
{
	if (key == 49 && e->weapon != 1)
		get_weapon(e, ".img_wolf/cs.xpm", 1);
	else if (key == 50 && e->weapon != 2)
		get_weapon(e, ".img_wolf/justweapon.xpm", 2);
	else if (key == 51 && e->weapon != 3)
		get_weapon(e, ".img_wolf/dragonknife.xpm", 3);
}

int							weapon_is_black(char *str, int pos)
{
	if (str[pos] != 0 && str[pos + 1] != 0 && str[pos + 2] != 0)
		return (1);
	return (0);
}

void						put_weapon(t_env *e)
{
	static int				i;
	static int				j;
	static int				pos_i;
	static int				pos_w;

	i = 0;
	while (i < e->w.h)
	{
		j = 0;
		while (j < e->w.w)
		{
			pos_i = 4 * (e->width - e->w.w + j) +
				e->sizeline * (e->height - e->w.h + i);
			pos_w = 4 * j + e->w.sizeline * i;
			if (weapon_is_black(e->w.textur, pos_w) == 1)
			{
				e->data[pos_i] = e->w.textur[pos_w];
				e->data[pos_i + 1] = e->w.textur[pos_w + 1];
				e->data[pos_i + 2] = e->w.textur[pos_w + 2];
			}
			j++;
		}
		i++;
	}
}
