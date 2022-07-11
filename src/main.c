/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/07/11 10:10:34 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int close_minirt(t_data *data)
{
	printf("\nExit\n");
	free_data(data);
	exit(0);
	return (0);
}

// void ft_key_hook_camera(int keycode, t_data *data)
//{
//	if (keycode == CAM_UP)
//	{
//		printf("cam up %f\n", data->scene.camera.orient_vector.y);
//		data->scene.camera.orient_vector.y += 1;
//	}
//	if (keycode == CAM_DOWN)
//		data->scene.camera.orient_vector.y -= 1;
//	if (keycode == CAM_RIGHT)
//		data->scene.camera.orient_vector.x += 1;
//	if (keycode == CAM_LEFT)
//		data->scene.camera.orient_vector.x -= 1;
// }
int ft_key_hook(int keycode, t_data *data)
{
	//(void)data;
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

int main(int argc, char **argv)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	open_scene(argc, argv, data);
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "miniRT");
	if (!data->window)
		exit(1);
	draw(data);
	mlx_hook(data->window, 2, (1L << 0), ft_key_hook, data);
	mlx_hook(data->window, 17, 0, close_minirt, data);
	mlx_loop(data->mlx);
	return (0);
}
