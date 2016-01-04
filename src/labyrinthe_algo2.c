/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labyrinthe_algo2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 12:57:39 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/05 12:57:08 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			inf(int i, int j)
{
	if (i < j)
		return (i);
	return (j);
}

void		propager(int ligne, int colonne, int valeur,
					t_terrain tab[2 * N + 1][2 * M + 1])
{
	tab[ligne][colonne].val = valeur;
	if (tab[ligne - 1][colonne].val != -1 &&
		tab[ligne - 1][colonne].val > valeur)
		propager(ligne - 1, colonne, valeur, tab);
	if (tab[ligne][colonne + 1].val != -1 &&
		tab[ligne][colonne + 1].val > valeur)
		propager(ligne, colonne + 1, valeur, tab);
	if (tab[ligne + 1][colonne].val != -1 &&
		tab[ligne + 1][colonne].val > valeur)
		propager(ligne + 1, colonne, valeur, tab);
	if (tab[ligne][colonne - 1].val != -1 &&
		tab[ligne][colonne - 1].val > valeur)
		propager(ligne, colonne - 1, valeur, tab);
}

void		enumerer(int ligne, int colonne, int valeur,
					t_terrain tab[2 * N + 1][2 * M + 1])
{
	if (tab[ligne][colonne].val != 1)
	{
		tab[ligne][colonne].val = valeur;
		if (tab[ligne - 1][colonne].val >= valeur ||
			tab[ligne - 1][colonne].val == 0)
			enumerer (ligne - 1, colonne, valeur + 1, tab);
		if (tab[ligne][colonne + 1].val >= valeur ||
			tab[ligne][colonne + 1].val == 0)
			enumerer (ligne, colonne + 1, valeur + 1, tab);
		if (tab[ligne + 1][colonne].val >= valeur ||
			tab[ligne + 1][colonne].val == 0)
			enumerer (ligne + 1, colonne, valeur + 1, tab);
		if (tab[ligne][colonne - 1].val >= valeur ||
			tab[ligne][colonne - 1].val == 0)
			enumerer (ligne, colonne - 1, valeur + 1, tab);
	}
}

void		creer_labyrente(t_terrain tab[2 * N + 1][2 * M + 1])
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = -1;
	while (++i <= 2 * N)
	{
		j = -1;
		while (++j <= 2 * M)
		{
			if (((i % 2) == 1) && ((j % 2) == 1))
				tab[i][j].val = k++;
			else
				tab[i][j].val = -1;
		}
	}
}

void		creer_nouveau_pont(t_terrain tab[2 * N + 1][2 * M + 1])
{
	int		i;
	int		j;

	while (42)
	{
		i = (int)((2 * N - 1) *
				(rand() / (RAND_MAX + 1.0))) + 1;
		j = (int)((2 * M - 1) *
				(rand() / (RAND_MAX + 1.0))) + 1;
		if (tab[i][j].val == -1)
		{
			if (((i % 2) == 1 && (j % 2) == 0) ||
				((i % 2) == 0 && (j % 2) == 1))
			{
				tab[i][j].val = 0;
				break ;
			}
		}
	}
}
