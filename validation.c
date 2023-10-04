

#include "so_long.h"

void	map_paredes(t_main *main)
{
	int	i;
	int	altura;
	int	largura;

	i = -1;
	altura = main->altura - 1;
	largura = main->larg - 1;
	while (main->map[0][++i] != '\n')
	{
		if ((main->map[0][i] != '1' && main->map[0][i] != '\n')
			|| (main->map[altura][i] != '1' && main->map[altura][i] != '\n'))
		{
			free_map(main->map);
			exit(ft_putstr_fd("erro na parede de cima ou baixo\n", 1));
		}
	}
	i = -1;
	while (++i < altura)
	{
		if (main->map[i][0] != '1' && main->map[i][largura] != '1')
		{
			free_map(main->map);
			exit(ft_putstr_fd("erro na parede dos lados\n", 1));
		}
	}
}

void	map_rectangle(t_main *main)
{
	int	alt;
	int	i;

	alt = 1;
	i = 1;
	main->larg = ft_strlen_sl(main->map[0]);
	while (main->map[i] != NULL)
	{
		if (main->larg == ft_strlen_sl(main->map[alt]))
		{
			alt++;
			i++;
		}
		else if (main->map[i][0] == '\n')
			i++;
		else
		{
			free_map(main->map);
			exit(ft_putstr_fd("O mapa não é retangulo\n", 1));
		}
	}
	main->altura = alt;
}

void	check_letters(t_main *main, int i, int j, int *true_p)
{
	if (main->map[i][j] == 'P')
	{
		(*true_p)++;
		main->player.x = j;
		main->player.y = i;
	}
	else if (main->map[i][j] == 'C')
		main->col++;
}

void	map_caracteres(t_main *main)
{
	int	i;
	int	j;
	int	true_e;
	int	true_p;

	i = -1;
	true_e = 0;
	true_p = 0;
	main->col = 0;
	while (main->map[++i] != NULL)
	{
		j = -1;
		while (main->map[i][++j] != '\0')
		{
			if (main->map[i][j] == 'E')
				true_e++;
			check_letters(main, i, j, &true_p);
		}
	}
	if (true_e != 1 || true_p != 1 || main->col < 1)
	{
		free_map(main->map);
		exit(ft_putstr_fd("Erro no caracter\n", 1));
	}
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
		{
			free_map(main->map);
			exit(ft_putstr_fd("Erro nos caracteres\n", 1));
		}
	}
}
