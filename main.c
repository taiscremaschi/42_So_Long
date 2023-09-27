/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:58:57 by ricardo           #+#    #+#             */
/*   Updated: 2023/09/26 16:37:04 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


#define UP 119
#define DOWN 115
#define RIGHT 100
#define LEFT 97

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

int function_image(t_main *main)
{
    int i;
    int j;

    i = 0;
    j = 0;
    printf("%d, %d\n", main->player.x, main->player.y);
    while((i < (main->large - 1) * 64))
    {
        j = 0;
        while (j < main->altura * 64)
        {
            my_mlx_pixel_put()
            j++;
        }
        i++;
    }
    //create_square(main, main->player.x, main->player.y, 200, 0x40e0d0);
    //mlx_put_image_to_window(main->mlx, main->win, main->picture.exit, 200, 200);
	//mlx_put_image_to_window(main->mlx, main->win, main->image.img, 0, 0);
    while(main->map[i] != NULL)
    {
        j = 0;
        while(main->map[i][j] != '\0')
        {
            if(main->map[i][j] == '1')
                mlx_put_image_to_window(main->mlx, main->win, main->picture.wall, (j * 64), (i* 64));
            if(main->map[i][j] == '0')
               mlx_put_image_to_window(main->mlx, main->win, main->picture.floor, (j * 64), (i* 64));
            if(main->map[i][j] == 'P')
                mlx_put_image_to_window(main->mlx, main->win, main->picture.player, (j * 64), (i* 64));
            if(main->map[i][j] == 'E')
                mlx_put_image_to_window(main->mlx, main->win, main->picture.exit, (j * 64), (i* 64));
            if(main->map[i][j] == 'C')
                mlx_put_image_to_window(main->mlx, main->win, main->picture.collectable, (j * 64), (i* 64));
            
            j++;
            
        }
        i++;
    }
    return(0);
}

int	close_(t_main *main)
{
	mlx_destroy_window(main->mlx, main->win);
    exit(0);
	return (0);
}

int read_esc(int keycode, t_main *main)
{
	if(keycode == 65307)
		close_(main);
	return(0);	
}
void check_ber(char *av)
{
    if(ft_strncmp(ft_strchr(av, '.'), ".ber\0", 5) != 0)
    {
        exit(write(2, "Error, wrong extension\n", 23));
    }
}

int key_hook(int keycode, t_player *player)
{
    
     if(keycode == UP)
        player->y--;
    if(keycode == DOWN)
        player->y++;
    if(keycode == RIGHT)
        player->x++;

    if(keycode == LEFT)
        player->x--;

    printf("%d\n", keycode);
    return (0);
}

int	main(int ac, char **av)
{
    t_main    main;
  
    main.player.x = 0;
    main.player.y = 0;
    if(ac != 2)
    {
        exit (write(2, "Error\n", 6));
    }
    check_ber(av[1]);
    check_map(av, &main);       
    main.mlx = mlx_init();
	main.win = mlx_new_window(main.mlx, ((main.large - 1) * 64), main.altura * 64, "so long");
ç
    image_inicialize(&main);
    //create_square(&main, main.player.x, main.player.y, 200, 0x40e0d0);
	//mlx_put_image_to_window(main.mlx, main.win, main.image.img, 0, 0);
	mlx_key_hook(main.win,key_hook, &main.player);
	mlx_loop_hook(main.mlx, function_image, &main);
    mlx_hook(main.win, 2, 1L<<0, read_esc, &main);
	mlx_loop(main.mlx);
     return 0;
}
