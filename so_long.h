/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:15:22 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/09/26 16:12:34 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "libft/get_next_line_bonus.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_image {
	void	*img;
    char	*addr;
    int	bits_per_pixel;
    int		line_length;
	int		endian;

}				t_image;

typedef struct	s_player {
    
    int x;
    int y;
    }           t_player;

typedef struct	s_picture {
    void	*collectable;
    void	*wall;
    void    *player;
    void    *floor;
    void    *exit;
}	t_picture;

typedef struct	s_main {
	
	void	*win;
    char    **map;
    int	    large;
    int     altura;
    void	*mlx;
    t_image	 image;
    t_player	player;
    t_picture	picture;
    
}				t_main;


void check_map(char **av, t_main *main);
char **save_map(char **map, int fd);
void    image_inicialize(t_main *main);


#endif