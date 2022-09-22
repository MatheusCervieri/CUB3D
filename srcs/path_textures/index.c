/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:56:23 by mamaro-d          #+#    #+#             */
/*   Updated: 2022/09/21 20:41:42 by mamaro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_no_texture(char *no_path, t_data *data)
{
    if(!access(no_path, R_OK))
    {
        data->no_texture = no_path;
        return (1);
    }
    return (0);
}

int get_so_texture(char *so_path, t_data *data)
{
    if(!access(so_path, R_OK))
    {
        data->no_texture = so_path;
        return (1);
    }
    return (0);
}

int get_ea_texture(char *ea_path, t_data *data)
{
    if(!access(ea_path, R_OK))
    {
        data->no_texture = ea_path;
        return (1);
    }
    return (0);
}

int get_we_texture(char *we_path, t_data *data)
{
    if(!access(we_path, R_OK))
    {
        data->no_texture = we_path;
        return (1);
    }
    return (0);
}