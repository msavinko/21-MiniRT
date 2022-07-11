/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:32:32 by marlean           #+#    #+#             */
/*   Updated: 2022/07/11 10:48:59 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


// void ft_key_hook_camera(int keycode, t_data *data)
// {
// 	if (keycode == CAM_UP)
// 	{
// 		printf("cam up %f\n", data->scene.camera.orient_vector.y);
// 		data->scene.camera.orient_vector.y += 0.1;
// 	}
// 	if (keycode == CAM_DOWN)
// 		data->scene.camera.orient_vector.y -= 0.1;
// 	if (keycode == CAM_RIGHT)
// 		data->scene.camera.orient_vector.x += 0.1;
// 	if (keycode == CAM_LEFT)
// 		data->scene.camera.orient_vector.x -= 0.1;
// }
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
	// ft_key_hook_camera(keycode, data);
	draw(data);
	return (0);
}
