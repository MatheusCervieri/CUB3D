/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:23:53 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/03 15:36:49 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data *data;

/*
	-Criar um mapa aleatório e verificar os raios que estão passando entre dois blocos, descobrir o porque e concertar.
	-Concertar os segfaults e ir em busca dos segfaults.
	-Bug texturas.
	-Colocar o mapa no tamanho certo 64 bits. (Não me parece necessário).
	-A tela fica piscando as vezes. 
	-Váriavel global. 
	
	-Organizar o código que foi feito. 
	-Inicializar variáveis...
	-Conectar com a parte da dupla.
	-Valgrind. 


	Última coisa:
	-Colocar o tamanho da janela certo e desenhar já da forma certa na tela.
	
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
				data->player.rotation = 3*PI/2;
			}
			if(data->map_array[i][j] == 'S') //Add all. 
			{
				data->player.x = width * MINI_MAP_SIZE;
				data->player.y = height * MINI_MAP_SIZE;
				data->player.rotation = PI/2;
			}
			if(data->map_array[i][j] == 'E') //Add all. 
			{
				data->player.x = width * MINI_MAP_SIZE;
				data->player.y = height * MINI_MAP_SIZE;
				data->player.rotation = 0;
			}
			if(data->map_array[i][j] == 'W') //Add all. 
			{
				data->player.x = width * MINI_MAP_SIZE;
				data->player.y = height * MINI_MAP_SIZE;
				data->player.rotation = 2*PI;
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
	data->floor_color = malloc (sizeof(int) * 1);
	data->ceiling_color = malloc (sizeof(int) * 1);
	*data->floor_color = 0x4169e1;
	*data->ceiling_color = 0x87ceeb;

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

	i = 0;
	while (i < 320)
	{
	data->rays[i].x = 0;
	data->rays[i].y = 0;
	data->rays[i].rotation = 0.0;
	data->rays[i].position = 0;
	i++;
	}
	
	check_intersections();
	new_window();
	init_imgs();
	draw_minimap();
	//mlx_destroy_image(data->mlx, data->img.mlx_img);
	handle_hooks();
	mlx_loop(data->mlx);
}

