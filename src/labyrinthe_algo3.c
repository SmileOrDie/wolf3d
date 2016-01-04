/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labyrinthe_algo3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 13:07:25 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/05 21:28:18 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				creer_un_pont2(int i, int j,
							t_terrain tab[2 * N + 1][2 * M + 1], int t)
{
	if (tab[i][j - 1].val != tab[i][j + 1].val && t == 1)
	{
		tab[i][j].val = inf(tab[i][j - 1].val, tab[i][j + 1].val);
		propager (i, j, tab[i][j].val, tab);
		return (1);
	}
	if (tab[i - 1][j].val != tab[i + 1][j].val && t == 2)
	{
		tab[i][j].val = inf(tab[i - 1][j].val, tab[i + 1][j].val);
		propager (i, j, tab[i][j].val, tab);
		return (1);
	}
	return (0);
}

void			creer_un_pont(t_terrain tab[2 * N + 1][2 * M + 1])
{
	int			i;
	int			j;

	while (42)
	{
		i = (int)((2 * N - 1) * (rand() / (RAND_MAX + 1.0))) + 1;
		j = (int)((2 * M - 1) * (rand() / (RAND_MAX + 1.0))) + 1;
		if (tab[i][j].val == -1)
		{
			if (((i % 2) == 1 && (j % 2) == 0) ||
				((i % 2) == 0 && (j % 2) == 1))
			{
				if (tab[i - 1][j].val == -1 && tab[i + 1][j].val == -1)
				{
					if (creer_un_pont2(i, j, tab, 1) == 1)
						break ;
				}
				else if (tab[i][j - 1].val == -1 && tab[i][j + 1].val == -1)
					if (creer_un_pont2(i, j, tab, 2) == 1)
						break ;
			}
		}
	}
}

void			map_key(int key, t_env *e)
{
	if (e->map[(int)e->posx][(int)e->posy] == 2 && key == 113)
	{
		init_terrain(e);
		check_where(e);
		if (!e->map)
			exit(0);
	}
	if (e->map[(int)e->posx][(int)e->posy] == 2 && key == 114)
	{
		convert("./.img_wolf/terrain", e, 0, 0);
		check_where(e);
		if (!e->map)
			exit(0);
	}
	if (e->map[(int)e->posx][(int)e->posy] == 2 && key == 116)
	{
		convert("./.img_wolf/map1", e, 0, 0);
		check_where(e);
		if (!e->map)
			exit(0);
	}
}

void			ft_free_tab_int(int **tab, int col)
{
	int			i;

	i = 0;
	while (i < col)
	{
		free(tab[i]);
		++i;
	}
	free(tab);
	tab = NULL;
}
