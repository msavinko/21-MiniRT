/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:01:15 by marlean           #+#    #+#             */
/*   Updated: 2022/07/28 17:44:30 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_key_hook_coord(int keycode, t_data *data)
{
	if (keycode == X)
		mlx_hook(data->window, 2, (1L << 0), ft_x_move, data);
	if (keycode == Y)
		mlx_hook(data->window, 2, (1L << 0), ft_y_move, data);
	if (keycode == Z)
		mlx_hook(data->window, 2, (1L << 0), ft_z_move, data);
	if (keycode == O)
		mlx_hook(data->window, 2, (1L << 0), ft_o_move, data);
	if (keycode == R)
		mlx_hook(data->window, 2, (1L << 0), ft_radius, data);
	if (keycode == E)
		mlx_hook(data->window, 2, (1L << 0), ft_key_hook, data);
	return (0);
}

int	ft_mouse_hook(int mousecode, int x, int y, t_data *data)
{
	t_coord	m_ray;
	float	x_ray;
	float	y_ray;

	printf("Hello\n");
	if (mousecode == 5)
		printf("mousecode 5\n");
	x_ray = (x - WIDTH / 2) / (WIDTH);
	y_ray = (HEIGHT / 2 - y) / (HEIGHT);
	m_ray = new_vector3(x_ray, y_ray, data->scene.camera.orient_vector.z);
	printf("I found coord %f %f %f\n", m_ray.x, m_ray.y, m_ray.z);
	data->m_dist.min_dist = INT32_MAX;
	nearest_sphere(data, &data->m_dist, &m_ray);
	nearest_plane(data, &data->m_dist, &m_ray);
	nearest_cylind(data, &data->m_dist, &m_ray);
	printf("dist near obj %d\n", data->m_dist.near_obj);
	printf("number of object %d\n", data->m_dist.n_obj);
	if (data->m_dist.near_obj > 0)
	{
		mlx_hook(data->window, 2, (1L << 0), ft_key_hook_coord, data);
	}
	draw(data);
	return (0);
}

int	ft_mouse(int mouse, int x, int y, t_data *data)
{
	if (mouse == 1)
		ft_mouse_hook(mouse, x, y, data);
	if (mouse == 2)
	{
		printf("You pressed 2\n");
		mlx_hook(data->window, 2, (1L << 0), ft_key_hook, data);
		mlx_hook(data->window, 17, 0, close_minirt, data);
		return (1);
	}
	if (mouse != 1 && mouse != 2)
	{
		printf("exit from mouse\n");
		draw(data);
	}
	return (0);
}
