/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:06:42 by marlean           #+#    #+#             */
/*   Updated: 2022/07/07 14:28:51 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_parser(t_parser *pars)
{
	pars->file_fd = 0;
	pars->read_res = 0;
	pars->line = NULL;
	pars->map = NULL;
}

void	init_scene(t_scene *scene)
{
	scene->alight.light_range = 0.00f;
	scene->alight.color.r = 0;
	scene->alight.color.g = 0;
	scene->alight.color.b = 0;
	scene->camera.view_point.x = 0.00f;
	scene->camera.view_point.y = 0.00f;
	scene->camera.view_point.z = 0.00f;
	scene->camera.orient_vector.x = 0.00f;
	scene->camera.orient_vector.y = 0.00f;
	scene->camera.orient_vector.z = 0.00f;
	scene->camera.fov = 0.00f;
	scene->light.coord.x = 0.00f;
	scene->light.coord.y = 0.00f;
	scene->light.coord.z = 0.00f;
	scene->light.bright = 0.00f;
}

void	init_objects(t_objects *obj)
{
	int	i;

	obj->sphere = malloc(sizeof(t_sphere) * obj->nsphere);
	if (!obj->sphere)
		error_parser("Malloc error");
	i = 0;
	while (i < obj->nsphere)
		init_sphere(&obj->sphere[i++]);
	obj->plane = malloc(sizeof(t_plane) * obj->nplane);
	if (!obj->plane)
		error_parser("Malloc error");
	i = 0;
	while (i < obj->nplane)
		init_plane(&obj->plane[i++]);
	obj->cylind = malloc(sizeof(t_cylind) * obj->ncylinder);
	if (!obj->cylind)
		error_parser("Malloc error");
	i = 0;
	while (i < obj->ncylinder)
		init_cylinder(&obj->cylind[i++]);
}

void	init_data(t_data *data)
{
	init_scene(&data->scene);
	init_objects(&data->objects);
}
