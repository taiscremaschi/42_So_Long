/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:26:38 by ricardo           #+#    #+#             */
/*   Updated: 2023/09/26 16:12:25 by ricardo          ###   ########.fr       */
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
    printf("chegou bebe\n");
}
