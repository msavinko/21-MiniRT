/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/06/30 14:08:29 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*new_scene(t_camera *camera, t_sphere *sphere)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		ft_error(1);
	scene->camera = camera;
	scene->sphere = sphere;
	return (scene);
}

t_scene2	*new_scene2(t_camera2 *camera, t_sphere2 *sphere)
{
	t_scene2	*scene;

	scene = malloc(sizeof(t_scene2));
	if (!scene)
		ft_error(1);
	scene->camera = camera;
	scene->sphere = sphere;
	return (scene);
}
