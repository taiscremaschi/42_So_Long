/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:47:01 by ricardo           #+#    #+#             */
/*   Updated: 2023/10/02 23:32:31 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_paredes(t_main *main)
{
	int	i;
	int	j;
	int	altura;
	int	largura;

	i = 0;
	j = 0;
	altura = main->altura - 1;
	largura = main->large - 2;
	while (main->map[0][j] != '\0')
	{
		if ((main->map[0][j] != '1' && main->map[0][j] != '\n')
			|| (main->map[altura][j] != '1' && main->map[altura][j] != '\n'))
			exit(ft_putstr_fd("erro na parede de cima ou baixo\n", 1));
		j++;
	}
	while (i < altura)
	{
		if (main->map[i][0] != '1' && main->map[i][largura] != '1')
			exit(ft_putstr_fd("erro na parede dos lados\n", 1));
		i++;
	}
}

void	map_retagulo(t_main *main)
{
	int	alt;
	int	i;

	alt = 1;
	i = 1;
	main->large = ft_strlen(main->map[0]);
	while (main->map[i] != NULL)
	{
		if (main->large == ft_strlen(main->map[alt]))
		{
			alt++;
			i++;
		}
		else if (main->map[i][0] == '\n')
			i++;
		else
			exit(ft_putstr_fd("O mapa não é retangulo\n", 1));
	}
	main->altura = alt;
}

void	map_caracteres(t_main *main, int true_e, int true_p)
{
	int		i;
	int		j;

	i = -1;
	main->player.col = 0;
	while (main->map[++i] != NULL)
	{
		j = -1;
		while (main->map[i][++j] != '\0')
		{
			if (main->map[i][j] == 'E')
				true_e++;
			else if (main->map[i][j] == 'P')
			{
				true_p++;
				main->player.x = j;
				main->player.y = i;
			}
			else if (main->map[i][j] == 'C')
				main->player.col++;
		}
	}
	if (true_e != 1 || true_p != 1 || main->player.col < 1)
		exit(ft_putstr_fd("Erro no caracter\n", 1));
}

void	map_validate(t_main *main)
{
	int	i;

	i = 0;
	while (main->map[i] != NULL)
	{
		if (map_caracteres_valids(main->map[i]))
			i++;
		else
			exit(ft_putstr_fd("Erro nos caracteres\n", 1));
	}
}

void	check_map(char **av, t_main *main)
{
	int	fd;
    char **copy_map_temp;

	if (ft_strncmp(ft_strchr(av[1], '.'), ".ber\0", 5) != 0)
		exit(write(1, "Error, wrong extension\n", 23));
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		exit(ft_putstr_fd("Erro na abertura do FD\n", 1));
	main->map = save_map(NULL, fd);
	map_retagulo(main);
	map_validate(main);
	map_caracteres(main, 0, 0);
	map_paredes(main);
    copy_map_temp = copy_map(main);
	if (algoritmo(main->player.x, main->player.y, copy_map_temp,
			main->player.col) == 1)
		exit(ft_putstr_fd("caminho nao valido\n", 1));
    free_map(copy_map_temp);
}
