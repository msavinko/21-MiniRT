/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:38:38 by marlean           #+#    #+#             */
/*   Updated: 2022/07/28 17:45:12 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	move_obj(int keycode, float *num)
{
	if (keycode == L)
		*num += 1.0;
	if (keycode == K)
		*num -= 1.0;
}

int	ft_x_move(int keycode, t_data *data)
{
	printf("You move obj on X axis\n");
	if (keycode == E)
	{
		printf("You pressed E\n");
		data->m_dist.near_obj = 0;
		return (0);
	}
	if (data->m_dist.near_obj == 1)
		move_obj(keycode, &data->objects.sphere[data->m_dist.n_obj].coord.x);
	if (data->m_dist.near_obj == 2)
		move_obj(keycode, &data->objects.plane[data->m_dist.n_obj].coord.x);
	if (data->m_dist.near_obj == 3 || data->m_dist.near_obj == 4
		|| data->m_dist.near_obj == 5)
		move_obj(keycode, &data->objects.cylind[data->m_dist.n_obj].coord.x);
	draw(data);
	return (0);
}

int	ft_y_move(int keycode, t_data *data)
{
	printf("You move obj on Y axis\n");
	if (keycode == E)
	{
		printf("You pressed E\n");
		data->m_dist.near_obj = 0;
		return (0);
	}
	if (data->m_dist.near_obj == 1)
		move_obj(keycode, &data->objects.sphere[data->m_dist.n_obj].coord.y);
	if (data->m_dist.near_obj == 2)
		move_obj(keycode, &data->objects.plane[data->m_dist.n_obj].coord.y);
	if (data->m_dist.near_obj == 3 || data->m_dist.near_obj == 4
		|| data->m_dist.near_obj == 5)
		move_obj(keycode, &data->objects.cylind[data->m_dist.n_obj].coord.y);
	draw(data);
	return (0);
}

int	ft_z_move(int keycode, t_data *data)
{
	printf("You move obj on Z axis\n");
	if (keycode == E)
	{
		printf("You pressed E\n");
		data->m_dist.near_obj = 0;
		return (0);
	}
	if (data->m_dist.near_obj == 1)
		move_obj(keycode, &data->objects.sphere[data->m_dist.n_obj].coord.z);
	if (data->m_dist.near_obj == 2)
		move_obj(keycode, &data->objects.plane[data->m_dist.n_obj].coord.z);
	if (data->m_dist.near_obj == 3 || data->m_dist.near_obj == 4
		|| data->m_dist.near_obj == 5)
		move_obj(keycode, &data->objects.cylind[data->m_dist.n_obj].coord.z);
	draw(data);
	return (0);
}

int	ft_radius(int keycode, t_data *data)
{
	printf("You pressed R\nI am changing radius\n");
	if (data->m_dist.near_obj == 1)
		move_obj(keycode, &data->objects.sphere[data->m_dist.n_obj].radius);
	if (data->m_dist.near_obj == 3 || data->m_dist.near_obj == 4
		|| data->m_dist.near_obj == 5)
		move_obj(keycode, &data->objects.cylind[data->m_dist.n_obj].diameter);
	draw(data);
	return (0);
}
