/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Labyrinthe_Algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 17:38:46 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/05 21:20:52 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_tabi			check(t_terrain tab[2 * N + 1][2 * M + 1],
					t_tabi map, int i, int j)
{
	if (tab[i][j].val == -1)
	{
		if ((i == 0 || i == 2 * N) || (j == 0 || j == 2 * M))
			map.tab[i][j] = 1;
		else
		{
			if (tab[i][j].altitude == 0 && tab[i][j + 1].altitude != 0)
				map.tab[i][j] = 6;
			else
				map.tab[i][j] = 5;
		}
	}
	else if (tab[i][j].val == 1)
		map.tab[i][j] = 2;
	else
		map.tab[i][j] = 0;
	return (map);
}

t_tabi			map_rand(t_terrain tab[2 * N + 1][2 * M + 1])
{
	int			i;
	int			j;
	t_tabi		map;

	if (!(map.tab = (int **)malloc(sizeof(int *) * (2 * N + 1))))
		return (map);
	i = -1;
	while (++i <= 2 * N)
	{
		j = -1;
		if (!(map.tab[i] = (int *)malloc(sizeof(int) * 2 * M + 1)))
			return (map);
		while (++j <= 2 * M)
			map = check(tab, map, i, j);
	}
	map.y = 2 * N + 1;
	map.x = 2 * M + 1;
	return (map);
}

void			init_terrain2(t_env *e, int i, int j,
							t_terrain tab[2 * N + 1][2 * M + 1])
{
	t_tabi		ret;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < M)
			tab[i][j].altitude = 0;
	}
	ret = map_rand(tab);
	ft_map(e, &ret);
}

void			init_terrain(t_env *e)
{
	t_terrain	tab[2 * N + 1][2 * M + 1];
	int			i;
	int			j;

	creer_labyrente (tab);
	i = -1;
	while (++i < NB - 1)
		creer_un_pont(tab);
	enumerer (1, 1, 1, tab);
	creer_nouveau_pont (tab);
	i = -1;
	while (++i < N * M / 2 + (N * M % 10) / 2)
		creer_nouveau_pont (tab);
	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < M)
			if (i == 0 || j == 0 || j == (M - 1) || i == (N - 1))
				tab[i][j].val = -1;
	}
	init_terrain2(e, i, j, tab);
}
