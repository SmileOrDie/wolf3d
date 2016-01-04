/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 14:15:42 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/05 21:28:17 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_free_tab_char(char ***tab)
{
	int			i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		(*tab)[i++] = NULL;
	}
	free(*tab);
	*tab = NULL;
}

char			*ft_freejoin(char *line, char *line2)
{
	char		*tmp;
	char		*tmp2;

	tmp = line;
	line = ft_strjoin(line, "\n");
	free(tmp);
	tmp2 = line2;
	line2 = ft_strjoin(line2, line);
	free(tmp2);
	free(line);
	return (line2);
}

void			ft_map(t_env *e, t_tabi *map)
{
	if (e->map)
		ft_free_tab_int(e->map, e->y_max);
	e->map = map->tab;
	e->x_max = map->x;
	e->y_max = map->y;
}

void			convert(char *str, t_env *e, int ret, int fd)
{
	char		*line;
	char		*line2;
	char		**conv;
	t_tabi		*map;

	fd = open(str, O_RDONLY);
	if (fd == (-1))
	{
		perror(str);
		exit(0);
	}
	line2 = ft_strnew(0);
	while ((ret = get_next_line(fd, &line)) || line[0] != '\0')
		line2 = ft_freejoin(line, line2);
	close(fd);
	if (line)
		free(line);
	conv = ft_strsplit(line2, '\n');
	free(line2);
	map = tabc_to_tabi(conv, ' ');
	ft_free_tab_char(&conv);
	ft_map(e, map);
	free(map);
}

int				main(void)
{
	t_env		e;

	e.width = 1024;
	e.height = 720;
	convert("./.img_wolf/terrain", &e, 0, 0);
	if (!e.map)
		return (0);
	env_mlx(e);
	return (0);
}
