/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:32:32 by marlean           #+#    #+#             */
/*   Updated: 2022/07/19 12:20:55 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void ft_key_hook_camera(int keycode, t_data *data)
{
	if (keycode == W)
	{
		if (data->scene.camera.orient_vector.y < 1)
			data->scene.camera.orient_vector.y += 0.1;
	}
	if (keycode == S)
	{
		if (data->scene.camera.orient_vector.y > -1)
			data->scene.camera.orient_vector.y -= 0.1;
	}
	if (keycode == A)
	{
		if (data->scene.camera.orient_vector.x > -1)
			data->scene.camera.orient_vector.x -= 0.1;
	}
	if (keycode == D)
	{
		if (data->scene.camera.orient_vector.x < 1)
			data->scene.camera.orient_vector.x += 0.1;
	}
}
int ft_key_hook(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		close_minirt(data);
	if (keycode == UP)
		data->scene.camera.view_point.y += 0.1;
	if (keycode == DOWN)
		data->scene.camera.view_point.y -= 0.1;
	if (keycode == RIGHT)
		data->scene.camera.view_point.x += 0.1;
	if (keycode == LEFT)
		data->scene.camera.view_point.x -= 0.1;
	if (keycode == DIST_PLUS)
		data->scene.camera.view_point.z -= 0.5;
	if (keycode == DIST_MIN)
		data->scene.camera.view_point.z += 0.5;
	// ft_key_hook_camera(keycode, data);
	draw(data);
	return (0);
}
