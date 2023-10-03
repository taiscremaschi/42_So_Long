/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:35:22 by ricardo           #+#    #+#             */
/*   Updated: 2023/10/03 20:04:32 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_main *main)
{
	char	**c_map;
	int		x;
	int		y;

	c_map = malloc(sizeof(char *) * (main->altura + 1));
	if (!c_map)
		return (NULL);
	x = 0;
	while (x < main->altura)
	{
		y = 0;
		c_map[x] = malloc(sizeof(char) * (main->large + 1));
		if (!c_map)
			return (NULL);
		while (main->map[x][y] != '\0')
		{
			c_map[x][y] = main->map[x][y];
			y++;
		}
		c_map[x][y] = '\0';
		x++;
	}
	c_map[x] = NULL;
	return (c_map);
}

int	util_alg(int x, int y, char **map_copy, int col)
{
	if (map_copy[y][x] != '1' && map_copy[y][x] != 'z')
	{
		if (map_copy[y][x] == 'C')
			col--;
		return (algoritmo(x, y, map_copy, col));
	}
	return (1);
}

int	algoritmo(int x, int y, char **map_copy, int col)
{
	static int	exit;
	static int	c;

	if (col == 0)
		c = 1;
	if (map_copy[y][x] == 'E')
		exit = 1;
	if (c == 1 && exit == 1)
		return (0);
	map_copy[y][x] = 'z';
	if (util_alg(x, y - 1, map_copy, col) == 0)
		return (0);
	if (util_alg(x, y + 1, map_copy, col) == 0)
		return (0);
	if (util_alg(x + 1, y, map_copy, col) == 0)
		return (0);
	if (util_alg(x - 1, y, map_copy, col) == 0)
		return (0);
	return (1);
}
