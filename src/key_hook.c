/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariasavinova <mariasavinova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:32:32 by marlean           #+#    #+#             */
/*   Updated: 2022/07/12 16:54:58 by mariasavino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void ft_key_hook_camera(int keycode, t_data *data)
{
	if (keycode == CAM_UP)
	{
		if (data->scene.camera.orient_vector.y <= 1)
			data->scene.camera.orient_vector.y += 0.1;
	}
	if (keycode == CAM_DOWN)
	{
		if (data->scene.camera.orient_vector.y >= -1)
			data->scene.camera.orient_vector.y -= 0.1;
	}
	if (keycode == CAM_LEFT)
	{
		if (data->scene.camera.orient_vector.x <= 1)
			data->scene.camera.orient_vector.x += 0.1;
	}
	if (keycode == CAM_RIGHT)
	{
		if (data->scene.camera.orient_vector.x >= -1)
			data->scene.camera.orient_vector.x -= 0.1;
	}
}
int ft_key_hook(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		close_minirt(data);
	if (keycode == UP)
		data->scene.camera.view_point.y += 1;
	if (keycode == DOWN)
		data->scene.camera.view_point.y -= 1;
	if (keycode == RIGHT)
		data->scene.camera.view_point.x += 1;
	if (keycode == LEFT)
		data->scene.camera.view_point.x -= 1;
	if (keycode == DIST_PLUS)
		data->scene.camera.view_point.z -= 1;
	if (keycode == DIST_MIN)
		data->scene.camera.view_point.z += 1;
	ft_key_hook_camera(keycode, data);
	draw(data);
	return (0);
}
