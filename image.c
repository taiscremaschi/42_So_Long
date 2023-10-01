/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:26:38 by ricardo           #+#    #+#             */
/*   Updated: 2023/10/01 00:44:27 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    image_inicialize(t_main *main)
{
    int i;
    
    main->picture.collectable = mlx_xpm_file_to_image(main->mlx, "./images/coletavel.xpm", &i, &i);
    main->picture.wall = mlx_xpm_file_to_image(main->mlx, "./images/wall.xpm", &i, &i);
    main->picture.player = mlx_xpm_file_to_image(main->mlx, "./images/player.xpm", &i, &i);
    main->picture.floor = mlx_xpm_file_to_image(main->mlx, "./images/chao.xpm", &i, &i);
    main->picture.exit = mlx_xpm_file_to_image(main->mlx, "./images/exit.xpm", &i, &i);
}

int function_image(t_main *main)
{
    int x;
    int y;
    
    x = 0;
    y = 0;        
    while(main->map[y] != NULL)
    {
        x = 0;
        while(main->map[y][x] != '\0')
        {
            if(main->map[y][x] == '1')
                mlx_put_image_to_window(main->mlx, main->win, main->picture.wall, (x * 64), (y * 64));
            else if(main->map[y][x] == '0')
               mlx_put_image_to_window(main->mlx, main->win, main->picture.floor, (x * 64), (y * 64));
            else if(main->map[y][x] == 'P')
                mlx_put_image_to_window(main->mlx, main->win, main->picture.floor, (x * 64), (y * 64));
            else if(main->map[y][x] == 'E')
                mlx_put_image_to_window(main->mlx, main->win, main->picture.exit, (x * 64), (y * 64));
            else if(main->map[y][x] == 'C')
            {
                mlx_put_image_to_window(main->mlx, main->win, main->picture.collectable, (x * 64), (y * 64));
            }
            
            x++;
            
        }
        y++;
    }
    mlx_put_image_to_window(main->mlx, main->win, main->picture.player, (main->player.x * 64), (main->player.y * 64));
    return (0);
}
 