/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/07/28 14:31:23 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_data(t_data *data)
{
	if (data->objects.sphere)
		free(data->objects.sphere);
	if (data->objects.plane)
		free(data->objects.plane);
	if (data->objects.cylind)
		free(data->objects.cylind);
}

int	close_minirt(t_data *data)
{
	printf("\nExit\n");
	free_data(data);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

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
	mlx_mouse_hook(data->window, ft_mouse, data);
	mlx_loop(data->mlx);
	free_data(data);
	free(data);
	return (0);
}
