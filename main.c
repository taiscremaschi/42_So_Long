/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:58:57 by ricardo           #+#    #+#             */
/*   Updated: 2023/09/30 19:26:59 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

 void create_square(t_main *main, int x, int y, int size, int color)
{
	int i;
	int j;

	i = y;
	j = x;
	while (i <= y + size)
	{
		j = x;
		while (j <= x + size)
		{
			my_mlx_pixel_put(&(main->image), j, i, color);
			j++;
		}
		i++;
	}
}

int	close_(t_main *main)
{
	mlx_destroy_window(main->mlx, main->win);
    exit(0);
	return (0);
}

int	main(int ac, char **av)
{
    t_main    main;
  
    main.player.x = 0;
    main.player.y = 0;
	main.moves_counter = 0;
    if(ac != 2)
    {
        exit (write(2, "Error\n", 6));
    }
    check_map(av, &main);       
    main.mlx = mlx_init();
	main.win = mlx_new_window(main.mlx, ((main.large - 1) * 64), main.altura * 64, "so long");
    image_inicialize(&main);
	mlx_loop_hook(main.mlx, function_image, &main);
	mlx_key_hook(main.win,key_hook, &main);
    mlx_hook(main.win, 2, 1L<<0, read_esc, &main);
    mlx_hook(main.win, 33, 1L<<2, close_, &main);
	mlx_loop(main.mlx);
     return (0);
}
