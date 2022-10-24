/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:12:20 by mvieira-          #+#    #+#             */
/*   Updated: 2022/10/25 00:28:52 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_intersections_utils_2(t_data *data,
		float *distance_horizontal, float *distance_vertical, int i)
{
	*distance_horizontal = distance_btw_two_points(data->player.x,
			data->player.y, data->rays[i].h_x, data->rays[i].h_y);
	*distance_vertical = distance_btw_two_points(data->player.x,
			data->player.y, data->rays[i].v_x, data->rays[i].v_y);
	get_ray_type_v_h(data, *distance_horizontal, *distance_vertical, i);
	data->rays[i].distance_to_wall = (data->rays[i].distance_to_wall)
		* cos(data->rays[i].diference_angle);
	printf("Distance to wall:%f\n", data->rays[i].distance_to_wall);
	if (data->rays[i].distance_to_wall > 108)
		return (0);
	else	
		return (1);
}


int	check_intersections_c_ray(t_data *data)
{
	float	distance_horizontal;
	float	distance_vertical;
	int		i;

	i = 0;
	while (i < 4)
	{
		data->c_rays[i].rotation = (data->player.rotation * DG)
			+ (DG * 90) * i;
		if (data->c_rays[i].rotation < 0)
			data->c_rays[i].rotation += 2 * PI;
		if (data->c_rays[i].rotation > 2 * PI)
			data->c_rays[i].rotation -= 2 * PI;
		check_intersections_h(data, &data->c_rays[i].h_x, &data->c_rays[i].h_y,
			data->c_rays[i].rotation);
		check_intersections_v(data, &data->c_rays[i].v_x,
			&data->c_rays[i].v_y, data->c_rays[i].rotation);
		return (check_intersections_utils_2(data, &distance_horizontal,
			&distance_vertical, i));
		i++;
	}
	return (0);
}