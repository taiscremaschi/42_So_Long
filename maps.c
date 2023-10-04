

#include "so_long.h"

void	check_map(char **av, t_main *main)
{
	int	fd;

	if (ft_strchr(av[1], '.') == NULL || ft_strncmp(ft_strchr(av[1], '.'),
			".ber\0", 5) != 0)
		exit(write(1, "Error, wrong extension\n", 23));
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		exit(ft_putstr_fd("Erro na abertura do FD\n", 1));
	main->map = save_map(NULL, fd);
	map_rectangle(main);
	map_validate(main);
	map_caracteres(main);
	map_paredes(main);
	check_map_alg(main, copy_map(main));
}

int	map_caracteres_valids(char *s)
{
	char	*map;
	int		i;
	int		count;

	i = 0;
	count = 0;
	map = "PEC01\n";
	while (s[count] != '\0')
	{
		if (s[count] == map[i])
		{
			count++;
			i = 0;
		}
		else if (i == 6)
			return (0);
		else if (s[count] != map[i])
			i++;
	}
	return (1);
}

char	**save_map(char **map, int fd)
{
	static int	i;
	char		*lines_map;

	lines_map = get_next_line(fd);
	if (lines_map)
	{
		i++;
		map = save_map(map, fd);
	}
	if (!map && i != 0)
		map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		exit(ft_putstr_fd("Erro, o mapa é falso\n", 1));
	map[i--] = lines_map;
	return (map);
}
