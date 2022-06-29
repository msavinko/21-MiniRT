/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/06/24 19:08:03 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	close_minirt(void)
{
	printf("\nExit\n");
	ft_exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_error(1);
	init_data(data);
	open_scene(argc, argv, data);
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_error(-1);
	data->window = mlx_new_window(data->mlx, 1920, 1080, "miniRT");
	if (!data->window)
		ft_error(-1);
	mlx_hook(data->window, 17, 0, close_minirt, data);
	mlx_loop(data->mlx);
	return (0);
}
