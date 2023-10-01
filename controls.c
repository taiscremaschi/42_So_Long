/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:11:11 by ricardo           #+#    #+#             */
/*   Updated: 2023/09/30 19:55:43 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define UP 119
#define DOWN 115
#define RIGHT 100
#define LEFT 97

void verification_moves(t_main *m, int x, int y)
{
    if(m->map[y][x] == 'C')
    {
        m->player.col--;
        m->map[y][x] = '0';
    }
    else if (m->map[y][x] == 'E' && m->player.col == 0)
        exit(ft_putstr_fd("YOU ARE A WINNER!", 1));
    m->player.y = y;
    m->player.x = x;
    m->moves_counter++;
    printf("count moves is %d\n", m->moves_counter);
}

int key_hook(int keycode, t_main *m)
{
    int x;
    int y;

    x = m->player.x;
    y = m->player.y;
        
     if(keycode == UP && m->map[y - 1][x] != '1')
        verification_moves(m, x, (y - 1));
    else if(keycode == DOWN && m->map[y + 1][x] != '1')
        verification_moves(m, x, (y + 1));        
    else if(keycode == RIGHT && m->map[y][x + 1] != '1')
        verification_moves(m, (x + 1), y);        
    else if(keycode == LEFT && m->map[y][x - 1] != '1')
        verification_moves(m, (x - 1), y);        

    printf("%d\n", keycode);
    return (0);
}
int read_esc(int keycode, t_main *main)
{
	if(keycode == 65307)
		close_(main);
	return(0);	
}

