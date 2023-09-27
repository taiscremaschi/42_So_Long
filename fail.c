/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:06:28 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/09/14 11:56:17 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/*void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int read_esc(int keycode, t_vars *vars)
{
	if(keycode == 65307)
		close_(vars);
	return(0);	
}

 void create_square(t_vars *vars, int x, int y, int size, int color)
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
			my_mlx_pixel_put(vars, j, i, color);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int fd;
	char *str;
	int y;
	int x;
	t_vars	vars;
	char **map1;
	
	x = 0;
	y = 0;
	map1 = NULL;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1820, 980, "so long");
	vars.img = mlx_new_image(vars.mlx, 1820, 980);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length,
								&vars.endian);

	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 1920/2, 1080/2);
	mlx_key_hook(vars.mlx,read_esc, &vars);
	mlx_hook(vars.win, 2, 1L<<0, read_esc, &vars);
	mlx_loop(vars.mlx);
}*/