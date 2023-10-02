
#include "so_long.h"

int map_caracteres_valids(char *s)
{
    char *map;
    int i;
    int count;

    i = 0;
    count = 0;
    map = "PEC01\n";
    while(s[count] != '\0') 
    {
        if(s[count] == map[i])
        {
            count++;
            i = 0;
        }   
        else if(i == 6)
            exit(ft_putstr_fd("Erro! Caracter nao válido\n", 1));
        else if(s[count] != map[i])
            i++;
    }
    return(1);    
}

char **save_map(char **map, int fd)
{
    static int i;
    char *lines_map;

    lines_map = get_next_line(fd);
    if(lines_map)
    {
        i++;
        map = save_map(map, fd);
    }
    if(!map && i != 0)
        map = malloc(sizeof(char *) * (i + 1));
    if(!map)
        exit(ft_putstr_fd("Erro, o mapa é falso\n", 1));
    map[i--] = lines_map;
    return (map);
}

void print_map(char **map)
{
    int j = 0;

     while(map[j] != NULL)
    {
        printf("%s", map[j]);
        j++;
    }
}