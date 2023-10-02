/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:58:57 by ricardo           #+#    #+#             */
/*   Updated: 2023/10/02 23:31:49 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **m)
{
	int	i;

	i = 0;
	while (m[i])
	{
		free(m[i]);
		i++;
	}
	free(m);
}

int	end(t_main *main)
{
	free_map(main->map);
	mlx_destroy_image(main->mlx, main->picture.collectable);
	mlx_destroy_image(main->mlx, main->picture.wall);
	mlx_destroy_image(main->mlx, main->picture.floor);
	mlx_destroy_image(main->mlx, main->picture.exit);
	mlx_destroy_image(main->mlx, main->picture.player);
	mlx_destroy_window(main->mlx, main->win);
	mlx_destroy_display(main->mlx);
	mlx_loop_end(main->mlx);
	free(main->mlx);
	exit(0);
}

int	main(int ac, char **av)
{
	t_main	main;

	main.player.x = 0;
	main.player.y = 0;
	main.moves_counter = 0;
	if (ac != 2)
	{
		exit(write(1, "Error\n", 6));
	}
	check_map(av, &main);
	main.mlx = mlx_init();
	main.win = mlx_new_window(main.mlx, ((main.large - 1) * 64), main.altura
			* 64, "so long");
	image_inicialize(&main);
	mlx_loop_hook(main.mlx, function_image, &main);
	mlx_key_hook(main.win, key_hook, &main);
	mlx_hook(main.win, 2, 1L << 0, read_esc, &main);
	mlx_hook(main.win, 33, 1L << 2, end, &main);
	mlx_loop(main.mlx);
	return (0);
}
