/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:41:29 by marlean           #+#    #+#             */
/*   Updated: 2022/07/28 17:48:04 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	mov(int keycode, float *num)
{
	if (keycode == L)
		*num += 0.1;
	if (keycode == K)
		*num -= 0.1;
}

static int	ft_ox_move(int keycode, t_data *data)
{
	printf("You move orient vector X\n");
	if (data->m_dist.near_obj == 2)
		mov(keycode, &data->objects.plane[data->m_dist.n_obj].orient_vector.x);
	if (data->m_dist.near_obj == 3 || data->m_dist.near_obj == 4
		|| data->m_dist.near_obj == 5)
		mov(keycode, &data->objects.cylind[data->m_dist.n_obj].orient_vector.x);
	draw(data);
	return (0);
}

static int	ft_oy_move(int keycode, t_data *data)
{
	printf("You move orient vector Y\n");
	if (data->m_dist.near_obj == 2)
		mov(keycode, &data->objects.plane[data->m_dist.n_obj].orient_vector.y);
	if (data->m_dist.near_obj == 3 || data->m_dist.near_obj == 4
		|| data->m_dist.near_obj == 5)
		mov(keycode, &data->objects.cylind[data->m_dist.n_obj].orient_vector.y);
	draw(data);
	return (0);
}

static int	ft_oz_move(int keycode, t_data *data)
{
	printf("You move orient vector Z\n");
	if (data->m_dist.near_obj == 2)
		mov(keycode, &data->objects.plane[data->m_dist.n_obj].orient_vector.z);
	if (data->m_dist.near_obj == 3 || data->m_dist.near_obj == 4
		|| data->m_dist.near_obj == 5)
		mov(keycode, &data->objects.cylind[data->m_dist.n_obj].orient_vector.z);
	draw(data);
	return (0);
}

int	ft_o_move(int keycode, t_data *data)
{
	printf("You pressed O\nI am in orient move\n");
	if (data->m_dist.near_obj == 3 || data->m_dist.near_obj == 4
		|| data->m_dist.near_obj == 5)
	{
		if (keycode == X)
			mlx_hook(data->window, 2, (1L << 0), ft_ox_move, data);
		if (keycode == Y)
			mlx_hook(data->window, 2, (1L << 0), ft_oy_move, data);
		if (keycode == Z)
			mlx_hook(data->window, 2, (1L << 0), ft_oz_move, data);
	}
	draw(data);
	return (0);
}
