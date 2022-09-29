/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:23:53 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/29 21:03:14 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data *data;

/*
	-Adicionar as texturas conforme a direção do player
		Criar função que inicializa as testuras conforme o caminho delas.
	-Definir a cor do chão e do teto. 
	-Arrumar a movimentação do player. Falta fazer o player andar para a direita e para a esquerda. 
	-Inicializações e posição inicial do player. 
	-Deixar o programa rodando em tempo real.
	-Criar um mapa aleatório e verificar os raios que estão passando entre dois blocos, descobrir o porque e concertar.
	-Concertar os segfaults e ir em busca dos segfaults.
	-Colocar o mapa no tamanho certo 64 bits. (Não me parece necessário).
	-Colocar o tamanho da janela certo e desenhar já da forma certa na tela. 
	
	-Organizar o código que foi feito. 
	-Inicializar variáveis...
	-Conectar com a parte da dupla.

	Parser
	-Testar o parser do mapa. 
	-If any misconfiguration of any kind is encountered in the file, the program
	must exit properly and return "Error\n" followed by an explicit error message
	of your choice.
*/

void get_player_first_position()
{
	int i;
	int j;
	int height;
	int width;

	height = 0; 
	width = 0;
	i = 0;
	while (data->map_array[i])
	{
		j = 0;
		while (data->map_array[i][j])
		{
			if(data->map_array[i][j] == 'N') //Add all. 
			{
				data->player.x = width * MINI_MAP_SIZE;
				data->player.y = height * MINI_MAP_SIZE;
			}
			width++;
			j++;
		}
		width = 0;
		height++;
		i++;
	}
}



int	main(void)
{
	int		fd;
	char	*map_line;
	data = malloc(sizeof(t_data));
	data->map_string = ft_strdup("");

	fd = open("teste.txt", O_RDONLY);
	map_line = get_next_line(fd);
	data->map_string = ft_strjoin(data->map_string, map_line);

	while (map_line)
	{
		map_line = get_next_line(fd);
		if(map_line)
			data->map_string = ft_strjoin(data->map_string,
					map_line);
	}
	data->player_nbs = 0;
	data->mlx = NULL;
	data->win_ptr = NULL;
	data->walls_nbs = 0;
	data->no_texture = ft_strdup("texture.xpm");
    data->so_texture = ft_strdup("texture2.xpm");
    data->we_texture = ft_strdup("texture3.xpm");
    data->ea_texture = ft_strdup("texture4.xpm");
	parse_map();

	//Inicializa o array. 
	data->walls_position = malloc(sizeof(double *) * data->walls_nbs);
	int i;
	i = 0;
	while (i < data->walls_nbs)
	{
		data->walls_position[i] = malloc(sizeof(double) * 2);
		i++;
	}
	save_walls_position();
	printf("%f", data->walls_position[0][0]);
	get_player_first_position();
	data->player.dir_y = data->player.y - 50; 
	data->player.dir_x = data->player.x; 
	data->player.rotation = 0.0;
	
	i = 0;
	while (i < 320)
	{
	data->rays[i].x = 0;
	data->rays[i].y = 0;
	data->rays[i].rotation = 0.0;
	i++;
	}
	
	new_window();
	init_imgs();
	draw_minimap();
	//mlx_destroy_image(data->mlx, data->img.mlx_img);
	handle_hooks();
	mlx_loop(data->mlx);
}

