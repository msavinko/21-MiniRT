/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/06/30 13:37:14 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera2	*new_cam(t_coord *position, t_coord *orient, double fov)
{
	t_camera2	*camera;

	camera = malloc(sizeof(t_camera2));
	if (!camera)
		ft_error(1);
	camera->position = position;
	camera->orient = orient;
	camera->fov = fov;
	// camera->rotate = vector3_arotate(vector3_normalise(orient), camera->orient);
	// camera->rotate_origin = position;
	// camera->zoom = DEFAULT_ZOOM;
	// camera->defaults = copy_camera(position, orient, fov);
	return (camera);
}