/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:01:15 by marlean           #+#    #+#             */
/*   Updated: 2022/07/15 10:17:57 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_x_move(int keycode, t_data *data)
{
	printf("I am in coord move\n");
	if (keycode == E)
	{
		printf("You pressed E\n");
		data->m_dist.near_obj = 0;
		return (0);
	}
	if (data->m_dist.near_obj == 1)
	{
		printf("I am moving sphere x\n");
		if (keycode == L)
			data->objects.sphere[data->m_dist.n_obj].coord.x += 1.0;
		if (keycode == K)
			data->objects.sphere[data->m_dist.n_obj].coord.x -= 1.0;
	}
	if (data->m_dist.near_obj == 2)
	{
		printf("I am moving plane x\n");
		if (keycode == L)
			data->objects.plane[data->m_dist.n_obj].coord.x += 1.0;
		if (keycode == K)
			data->objects.plane[data->m_dist.n_obj].coord.x -= 1.0;
	}
	if (data->m_dist.near_obj == 3 || data->m_dist.near_obj == 4 || data->m_dist.near_obj == 5)
	{
		printf("I am moving cylind x\n");
		if (keycode == L)
			data->objects.cylind[data->m_dist.n_obj].coord.x += 1.0;
		if (keycode == K)
			data->objects.cylind[data->m_dist.n_obj].coord.x -= 1.0;
	}
	draw(data);
	return (0);
}

int	ft_y_move(int keycode, t_data *data)
{
	printf("I am in coord move\n");
	if (keycode == E)
	{
		printf("You pressed E\n");
		data->m_dist.near_obj = 0;
		return (0);
	}
	if (data->m_dist.near_obj == 1)
	{
		printf("I am moving sphere y\n");
		if (keycode == L)
			data->objects.sphere[data->m_dist.n_obj].coord.y += 1.0;
		if (keycode == K)
			data->objects.sphere[data->m_dist.n_obj].coord.y -= 1.0;
	}
	if (data->m_dist.near_obj == 2)
	{
		printf("I am moving plane y\n");
		if (keycode == L)
			data->objects.plane[data->m_dist.n_obj].coord.y += 1.0;
		if (keycode == K)
			data->objects.plane[data->m_dist.n_obj].coord.y -= 1.0;
	}
	if (data->m_dist.near_obj == 3 || data->m_dist.near_obj == 4 || data->m_dist.near_obj == 5)
	{
		printf("I am moving cylind y\n");
		if (keycode == L)
			data->objects.cylind[data->m_dist.n_obj].coord.y += 1.0;
		if (keycode == K)
			data->objects.cylind[data->m_dist.n_obj].coord.y -= 1.0;
	}
	draw(data);
	return (0);
}


int	ft_z_move(int keycode, t_data *data)
{
	printf("I am in coord move\n");
	if (keycode == E)
	{
		printf("You pressed E\n");
		data->m_dist.near_obj = 0;
		return (0);
	}
	if (data->m_dist.near_obj == 1)
	{
		printf("I am moving sphere z\n");
		if (keycode == L)
			data->objects.sphere[data->m_dist.n_obj].coord.z += 1.0;
		if (keycode == K)
			data->objects.sphere[data->m_dist.n_obj].coord.z -= 1.0;
	}
	if (data->m_dist.near_obj == 2)
	{
		printf("I am moving plane z\n");
		if (keycode == L)
			data->objects.plane[data->m_dist.n_obj].coord.z += 1.0;
		if (keycode == K)
			data->objects.plane[data->m_dist.n_obj].coord.z -= 1.0;
	}
	if (data->m_dist.near_obj == 3 || data->m_dist.near_obj == 4 || data->m_dist.near_obj == 5)
	{
		printf("I am moving cylind z\n");
		if (keycode == L)
			data->objects.cylind[data->m_dist.n_obj].coord.z += 1.0;
		if (keycode == K)
			data->objects.cylind[data->m_dist.n_obj].coord.z -= 1.0;
	}
	draw(data);
	return (0);
}

int	ft_ox_move(int keycode, t_data *data) // ?? ограничить ли рамками +1 / -1 ???
{
	printf("I am in orient vector move\n");
	if (data->m_dist.near_obj == 2)
	{
		printf("I am moving plane orient x\n");
		if (keycode == L)
			data->objects.plane[data->m_dist.n_obj].orient_vector.x += 0.1; 
		if (keycode == K)
			data->objects.plane[data->m_dist.n_obj].orient_vector.x -= 0.1;
	}
	if (data->m_dist.near_obj == 3 || data->m_dist.near_obj == 4 || data->m_dist.near_obj == 5)
	{
		printf("I am moving cylind orient x\n");
		if (keycode == L)
			data->objects.cylind[data->m_dist.n_obj].orient_vector.x += 0.1;
		if (keycode == K)
			data->objects.cylind[data->m_dist.n_obj].orient_vector.x -= 0.1;
	}
	draw(data);
	return (0);
}

int	ft_oy_move(int keycode, t_data *data) // ?? ограничить ли рамками +1 / -1 ???
{
	printf("I am in orient vector move\n");
	if (data->m_dist.near_obj == 2)
	{
		printf("I am moving plane orient y\n");
		if (keycode == L)
			data->objects.plane[data->m_dist.n_obj].orient_vector.y += 0.1; 
		if (keycode == K)
			data->objects.plane[data->m_dist.n_obj].orient_vector.y -= 0.1;
	}
	if (data->m_dist.near_obj == 3 || data->m_dist.near_obj == 4 || data->m_dist.near_obj == 5)
	{
		printf("I am moving cylind orient y\n");
		if (keycode == L)
			data->objects.cylind[data->m_dist.n_obj].orient_vector.y += 0.1;
		if (keycode == K)
			data->objects.cylind[data->m_dist.n_obj].orient_vector.y -= 0.1;
	}
	draw(data);
	return (0);
}

int	ft_oz_move(int keycode, t_data *data) // ?? ограничить ли рамками +1 / -1 ???
{
	printf("I am in orient vector move\n");
	if (data->m_dist.near_obj == 2)
	{
		printf("I am moving plane orient z\n");
		if (keycode == L)
			data->objects.plane[data->m_dist.n_obj].orient_vector.z += 0.1; 
		if (keycode == K)
			data->objects.plane[data->m_dist.n_obj].orient_vector.z -= 0.1;
	}
	if (data->m_dist.near_obj == 3 || data->m_dist.near_obj == 4 || data->m_dist.near_obj == 5)
	{
		printf("I am moving cylind orient z\n");
		if (keycode == L)
			data->objects.cylind[data->m_dist.n_obj].orient_vector.z += 0.1;
		if (keycode == K)
			data->objects.cylind[data->m_dist.n_obj].orient_vector.z -= 0.1;
	}
	draw(data);
	return (0);
}

int	ft_o_move(int keycode, t_data *data)
{
	printf("I am in orient move\n");
	// if (data->m_dist.near_obj == 2)
	// {
	// 	printf("I am moving plane vector\n");
	// 	if (keycode == L)
	// 		data->objects.plane[data->m_dist.n_obj].orient_vector += 1.0;
	// 	if (keycode == K)
	// 		data->objects.plane[data->m_dist.n_obj].coord.z -= 1.0;
	// }
	if (data->m_dist.near_obj == 3 || data->m_dist.near_obj == 4 || data->m_dist.near_obj == 5)
	{
		if (keycode == X)
		{
			printf("You pressed X\n");
			mlx_hook(data->window, 2, (1L << 0), ft_ox_move, data);
		}
		if (keycode == Y)
		{
			printf("You pressed Y\n");
			mlx_hook(data->window, 2, (1L << 0), ft_oy_move, data);
		}
		if (keycode == Z)
		{
			printf("You pressed Z\n");
			mlx_hook(data->window, 2, (1L << 0), ft_oz_move, data);
		}
	}
	draw(data);
	return (0);
}

int	ft_radius(int keycode, t_data *data)
{
	printf("I am changing radius\n");
	if (data->m_dist.near_obj == 1)
	{
		printf("I am changing sphere radius\n");
		if (keycode == L)
			data->objects.sphere[data->m_dist.n_obj].radius += 0.5;
		if (keycode == K)
			data->objects.sphere[data->m_dist.n_obj].radius -= 0.5;
	}
	if (data->m_dist.near_obj == 3 || data->m_dist.near_obj == 4 || data->m_dist.near_obj == 5)
	{
		printf("I am changing cylind radius\n");
		if (keycode == L)
			data->objects.cylind[data->m_dist.n_obj].diameter += 1.0;
		if (keycode == K)
			data->objects.cylind[data->m_dist.n_obj].diameter -= 1.0;
	}
	draw(data);
	return (0);
}

int	ft_key_hook_coord(int keycode, t_data *data)
{
	if (keycode == X)
	{
		printf("You pressed X\n");
		// printf("x before : data->objects.sphere[data->m_dist.n_obj].coord.x");
		// data->objects.sphere[data->m_dist.n_obj].coord.x += 2.0;
		// printf("x after : data->objects.sphere[data->m_dist.n_obj].coord.x");
		mlx_hook(data->window, 2, (1L << 0), ft_x_move, data);
	}
	if (keycode == Y)
	{
		printf("You pressed Y\n");
		// printf("x before : data->objects.sphere[data->m_dist.n_obj].coord.x");
		// data->objects.sphere[data->m_dist.n_obj].coord.x += 2.0;
		// printf("x after : data->objects.sphere[data->m_dist.n_obj].coord.x");
		mlx_hook(data->window, 2, (1L << 0), ft_y_move, data);
	}
	if (keycode == Z)
	{
		printf("You pressed Z\n");
		// printf("x before : data->objects.sphere[data->m_dist.n_obj].coord.x");
		// data->objects.sphere[data->m_dist.n_obj].coord.x += 2.0;
		// printf("x after : data->objects.sphere[data->m_dist.n_obj].coord.x");
		mlx_hook(data->window, 2, (1L << 0), ft_z_move, data);
	}
	if (keycode == O)
	{
		printf("You pressed O\n");
		// printf("x before : data->objects.sphere[data->m_dist.n_obj].coord.x");
		// data->objects.sphere[data->m_dist.n_obj].coord.x += 2.0;
		// printf("x after : data->objects.sphere[data->m_dist.n_obj].coord.x");
		mlx_hook(data->window, 2, (1L << 0), ft_o_move, data);
	}
	if (keycode == R)
	{
		printf("You pressed R\n");
		// printf("x before : data->objects.sphere[data->m_dist.n_obj].coord.x");
		// data->objects.sphere[data->m_dist.n_obj].coord.x += 2.0;
		// printf("x after : data->objects.sphere[data->m_dist.n_obj].coord.x");
		mlx_hook(data->window, 2, (1L << 0), ft_radius, data);
	}
	if (keycode == E)
	{
		printf("You pressed E\n");
		mlx_hook(data->window, 2, (1L << 0), ft_key_hook, data);
		return (0);
	}
	return (0);
}

int ft_mouse_hook(int mousecode, int x, int y, t_data *data)
{
	t_coord	m_ray;
//	t_dist	m_dist;
	float x_ray;
	float y_ray;

	printf("Hello\n");
	if (mousecode == 5)
	{
		printf("mousecode 5\n");
	}
		x_ray = (x - WIDTH / 2) / (WIDTH);
		y_ray = (HEIGHT / 2 - y) / (HEIGHT);
		m_ray = new_vector3(x_ray, y_ray, -1); // -1 или вектор камеры?
		printf("I found coord %f %f %f\n", m_ray.x, m_ray.y, m_ray.z);
		// m_ray->x = x_ray;
		// m_ray->y = y_ray;
		// m_ray->z = -1;
	data->m_dist.near_obj = 0;
	data->m_dist.min_dist = INT32_MAX;
	nearest_sphere(data, &data->m_dist, &m_ray);
	nearest_plane(data, &data->m_dist, &m_ray);
	nearest_cylind(data, &data->m_dist, &m_ray);
	printf("dist near obj %d\n", data->m_dist.near_obj);
	printf("number of object %d\n", data->m_dist.n_obj);
	if (data->m_dist.near_obj > 0)
	{
		mlx_hook(data->window, 2, (1L << 0), ft_key_hook_coord, data);
		// printf("x before : %f\n", data->objects.sphere[data->m_dist.n_obj].coord.x);
		// data->objects.sphere[data->m_dist.n_obj].coord.x += 2.0;
		// printf("x after :  %f\n", data->objects.sphere[data->m_dist.n_obj].coord.x);
	}
	draw(data);
	return (0);
}