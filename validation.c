/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:47:01 by ricardo           #+#    #+#             */
/*   Updated: 2023/10/01 01:22:25 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_paredes(t_main *main)
{
    int i;
    int j;
    int altura;
    int largura;

    i = 0;
    j = 0;
    altura = main->altura - 1;
    largura = main->large - 2;

    while(main->map[0][j] != '\0')
    {
        if(main->map[0][j] == '1' || main->map[0][j] == '\n')
            j++;
        else 
            exit(ft_putstr_fd("erro na parede de cima\n", 1));
    }
    j = 0;
    while(main->map[altura][j] != '\0')
    {
        if(main->map[altura][j] == '1' || main->map[altura][j] == '\n')
            j++;
        else 
            exit(ft_putstr_fd("erro na parede de baixo\n", 1));
    }
    while(main->map[i] != NULL)
    {
        if(main->map[i][0] == '1')
            i++;
        else 
            exit(ft_putstr_fd("erro na parede da esquerda\n", 1));
    }
    i = 0;
    while(main->map[i] != NULL)
    {
        printf("%d\n", main->map[i][largura]);
        if(main->map[i][largura] == '1')
            i++;
        else 
            exit(ft_putstr_fd("erro na parede da direita\n", 1));
    }
}

void map_retagulo(t_main *main)
{
    int i;

    i = 1;
    main->large = ft_strlen(main->map[0]);
    while(main->map[i] != NULL)
    {
        if(main->large == ft_strlen(main->map[i]))
            i++;
        else 
            exit(ft_putstr_fd("O mapa não é retangulo\n", 1));
    }
    main->altura = i;
}

void map_caracteres(t_main *main)
{
    int i;
    int trueE;
    int trueP;
    char *map;
    int trueC;
    int j;

    i = 0;
    trueE = 0;
    trueP = 0;
    trueC = 0;
    map = "EPC";
    j = 0;

    while(main->map[i] != NULL)
    {
        while(main->map[i][j] != '\0')
        {
            if(main->map[i][j] == map[0])
                trueE++;
            else if(main->map[i][j] == map[1])
                {
                    trueP++;
                    main->player.x = j;
                    main->player.y = i;
                    
                }

            else if(main->map[i][j] == map[2])
                trueC++;
            j++;
        }
        j = 0;
        i++;
    }
    if(trueE != 1)
        exit(ft_putstr_fd("Erro no caracter E\n", 1));
    else if(trueP != 1)
        exit(ft_putstr_fd("Erro no caracter P\n", 1));
    else if(trueC < 1)
        exit(ft_putstr_fd("Erro no caracter C\n", 1));
    main->player.col = trueC;
}

void map_validate(t_main *main)
{
    int i;

    i=0;
    while(main->map[i] != NULL)
    {
        if(map_caracteres_valids(main->map[i]))
            i++;
        else 
            exit(ft_putstr_fd("Erro nos caracteres\n", 1));
    }
}

void check_map(char **av, t_main *main)
{
    int fd;
    int i;

    i = 0;
    
    if(ft_strncmp(ft_strchr(av[1], '.'), ".ber\0", 5) != 0)
        exit(write(2, "Error, wrong extension\n", 23));

    fd = open(av[1], O_RDONLY);

    if(fd <= 0)
        exit(ft_putstr_fd("Erro na abertura do FD\n", 1));
    main->map = save_map(NULL, fd);
    map_retagulo(main);
    map_validate(main);
    map_caracteres(main);
    map_paredes(main);
    int x;
    x = algoritmo(main->player.x, main->player.y, copy_map(main), main->player.col);
    if(x == 1)
        exit(ft_putstr_fd("caminho nao valido\n", 1));
    while(main->map[i] != NULL)
    {
        printf("%s", main->map[i++]);
    }
}
