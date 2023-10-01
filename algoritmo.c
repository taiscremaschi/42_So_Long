/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:35:22 by ricardo           #+#    #+#             */
/*   Updated: 2023/10/01 01:19:02 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **copy_map(t_main *main)
{
    char **c_map;
    int x;
    int y;

    c_map = malloc(sizeof(char *) * (main->altura + 1));
    x = 0;
    while(main->map[x] != NULL)
    {
        y = 0;
        c_map[x] = malloc(sizeof(char) * (main->large + 1));
        while(main->map[x][y] != '\0')
        {
            c_map[x][y] = main->map[x][y];
            y++;
        }
        c_map[x][y] = '\0';
        x++;
    }
    c_map[x] = NULL;
    return c_map;
}

int algoritmo(int x, int y, char **map_copy, int col)
{ 
    static int exit;
        
    if(map_copy[y][x] == 'E')
       exit = 1;
    if(map_copy[y - 1][x] != '1' && map_copy[y - 1][x] != 'z')
    {
        if(map_copy[y - 1][x] == 'C')
            col--;
        map_copy[y][x] = 'z';
        algoritmo(x, y - 1, map_copy, col);   
    }
    if(map_copy[y + 1][x] != '1' && map_copy[y + 1][x] != 'z')
    {
        if(map_copy[y + 1][x] == 'C')
            col--;
        map_copy[y][x] = 'z';
        algoritmo(x, y + 1, map_copy, col);   
    }
    if(map_copy[y][x + 1] != '1' && map_copy[y][x + 1] != 'z')
    {
        if(map_copy[y][x + 1] == 'C')
            col--;
        map_copy[y][x] = 'z';
        algoritmo(x + 1, y, map_copy, col);   
    }
    if(map_copy[y][x - 1] != '1' && map_copy[y][x - 1] != 'z')
    {
        if(map_copy[y][x  - 1] == 'C')
            col--;
        map_copy[y][x] = 'z';
        algoritmo(x - 1, y, map_copy, col);   
    }
    if(col == 0 && exit == 1)
        return (0);
    return (1);
    
}
