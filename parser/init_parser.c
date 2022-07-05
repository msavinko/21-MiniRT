/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherrie <mcherrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:06:42 by marlean           #+#    #+#             */
/*   Updated: 2022/07/02 19:38:44 by mcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void init_parser(t_parser *pars)
{
	pars->file_fd = 0;
	pars->read_res = 0;
	pars->line = NULL;
	pars->map = NULL;
}

void init_scene(t_scene *scene)
{
	// scene = malloc(sizeof(t_scene));
	// if (!scene)
	// 	error_parser("Malloc error");
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

void init_objects(t_objects *obj)
{
	int i;

	// obj = malloc(sizeof(t_objects));
	// if (!obj)
	// 	error_parser("Malloc error");
	obj->sphere = malloc(sizeof(t_sphere) * obj->nsphere);
	if (!obj->sphere)
		error_parser("Malloc error");
	i = 0;
	while (i < obj->nsphere)
	{
		init_sphere(&obj->sphere[i]);
		i++;
	}
	obj->plane = malloc(sizeof(t_plane) * obj->nplane);
	if (!obj->plane)
		error_parser("Malloc error");
	i = 0;
	while (i < obj->nplane)
	{
		init_plane(&obj->plane[i]);
		i++;
	}
	obj->cylind = malloc(sizeof(t_cylind) * obj->ncylinder);
	if (!obj->cylind)
		error_parser("Malloc error");
	i = 0;
	while (i < obj->ncylinder)
	{
		init_cylinder(&obj->cylind[i]);
		i++;
	}
}
void init_sphere(t_sphere *sphere)
{
	sphere->coord.x = 0.0f;
	sphere->coord.y = 0.0f;
	sphere->coord.z = 0.0f;
	sphere->radius = 0.0f;
	sphere->color.r = 0;
	sphere->color.g = 0;
	sphere->color.b = 0;
}
void init_plane(t_plane *plane)
{
	plane->coord.x = 0.0f;
	plane->coord.y = 0.0f;
	plane->coord.z = 0.0f;
	plane->orient_vector.x = 0.0f;
	plane->orient_vector.y = 0.0f;
	plane->orient_vector.z = 0.0f;
	plane->color.r = 0;
	plane->color.g = 0;
	plane->color.b = 0;
}

void init_cylinder(t_cylind *cylind)
{
	cylind->coord.x = 0.0f;
	cylind->coord.y = 0.0f;
	cylind->coord.z = 0.0f;
	cylind->orient_vector.x = 0.0f;
	cylind->orient_vector.y = 0.0f;
	cylind->orient_vector.z = 0.0f;
	cylind->diameter = 0.0f;
	cylind->height = 0.0f;
	cylind->color.r = 0;
	cylind->color.g = 0;
	cylind->color.b = 0;
}

void init_data(t_data *data)
{
	init_scene(&data->scene);
	init_objects(&data->objects);
}
