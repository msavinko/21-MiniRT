/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:06:42 by marlean           #+#    #+#             */
/*   Updated: 2022/06/24 19:14:26 by marlean          ###   ########.fr       */
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
	scene->camera->position.x = 0.00f;
	scene->camera->position.y = 0.00f;
	scene->camera->position.z = 0.00f;
	scene->camera->orient.x = 0.00f;
	scene->camera->orient.y = 0.00f;
	scene->camera->orient.z = 0.00f;
	scene->camera->fov = 0.00f;
	scene->light.coord.x = 0.00f;
	scene->light.coord.y = 0.00f;
	scene->light.coord.z = 0.00f;
	scene->light.bright = 0.00f;
	scene->sphere->position.x = 0.0f;
	scene->sphere->position.y = 0.0f;
	scene->sphere->position.z = 0.0f;
	scene->sphere->radius = 0.0f;
	scene->sphere->color.r = 0;
	scene->sphere->color.g = 0;
	scene->sphere->color.b = 0;
}

void	init_objects(t_objects *obj)
{
	obj->sphere.position.x = 0.0f;
	obj->sphere.position.y = 0.0f;
	obj->sphere.position.z = 0.0f;
	obj->sphere.radius = 0.0f;
	obj->sphere.color.r = 0;
	obj->sphere.color.g = 0;
	obj->sphere.color.b = 0;
	obj->plane.coord.x = 0.0f;
	obj->plane.coord.y = 0.0f;
	obj->plane.coord.z = 0.0f;
	obj->plane.orient_vector.x = 0.0f;
	obj->plane.orient_vector.y = 0.0f;
	obj->plane.orient_vector.z = 0.0f;
	obj->plane.color.r = 0;
	obj->plane.color.g = 0;
	obj->plane.color.b = 0;
}

void	init_cylinder(t_objects *obj)
{
	obj->cylind.coord.x = 0.0f;
	obj->cylind.coord.y = 0.0f;
	obj->cylind.coord.z = 0.0f;
	obj->cylind.orient_vector.x = 0.0f;
	obj->cylind.orient_vector.y = 0.0f;
	obj->cylind.orient_vector.z = 0.0f;
	obj->cylind.diameter = 0.0f;
	obj->cylind.height = 0.0f;
	obj->cylind.color.r = 0;
	obj->cylind.color.g = 0;
	obj->cylind.color.b = 0;
}

void	init_data(t_data *data)
{
	init_scene(&data->scene);
	init_objects(&data->objects);
	init_cylinder(&data->objects);
}
