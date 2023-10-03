/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:15:22 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/10/03 19:11:59 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/get_next_line_bonus.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//////////// STRUCTS  //////////////
typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

}				t_image;

typedef struct s_player
{
	int			x;
	int			y;
	int			col;
}				t_player;

typedef struct s_picture
{
	void		*collectable;
	void		*wall;
	void		*player;
	void		*floor;
	void		*exit;
}				t_picture;

typedef struct s_main
{
	void		*win;
	char		**map;
	int			large;
	int			altura;
	void		*mlx;
	int			moves_counter;
	t_image		image;
	t_player	player;
	t_picture	picture;
}				t_main;

///////////// VALIDATION //////////

void			map_paredes(t_main *main);
void			map_rectangle(t_main *main);
void	map_caracteres(t_main *main, int true_e, int true_p);
void			map_validate(t_main *main);
void			check_map(char **av, t_main *main);
////////// MAPS ////////////

int				map_caracteres_valids(char *s);
char			**save_map(char **map, int fd);
void			print_map(char **map);

///////////// CONTROLS ////////////
int				key_hook(int keycode, t_main *main);
int				read_esc(int keycode, t_main *main);
void			verification_moves(t_main *m, int x, int y);
void			string_to_moves(t_main *m);

////////////// IMAGENS //////////////
void			image_inicialize(t_main *main);
int				function_image(t_main *main);

///////////  MAIN //////////
int				end(t_main *main);
void	        free_map(char **m);


////////// ALGORITMO  /////////////
int				algoritmo(int x, int y, char **map_copy, int col);
char			**copy_map(t_main *main);

#endif
