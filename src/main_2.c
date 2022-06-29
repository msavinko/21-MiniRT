/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/06/24 19:08:03 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static int	close_minirt(void)
// {
// 	printf("\nExit\n");
// 	ft_exit(0);
// 	return (0);
// }
t_color	new_color(int r, int g, int b)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

t_vplane	*get_view_plane(double width, double height, double fov)
{
	t_vplane	*vplane;
	double		aspect_ratio;

	fov = 1;
	vplane = (t_vplane *)malloc(sizeof(t_vplane));
	if (!vplane)
		ft_error(1);
	aspect_ratio = width / height;
	vplane->width = 1;
	vplane->height = vplane->width / aspect_ratio;
	vplane->x_pixel = vplane->width / width;
	vplane->y_pixel = vplane->height / height;
	return (vplane);
}

void	ray_tracing(void *mlx, void *window, t_scene *scene)
{
	int			mlx_x;
	int			mlx_y;
	double		x_angle;
	double		y_angle;
	int			color;
	double		x_ray;
	double		y_ray;
	t_coord		ray;
	t_vplane	*vplane;

	vplane = get_view_plane(WIDTH, HEIGHT, scene->camera->fov);
	mlx_y = 0;
	y_angle = HEIGHT / 2;
	while (y_angle > (-1 * HEIGHT / 2))
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = -1 * WIDTH / 2;
		mlx_x = 0;
		while (x_angle <= WIDTH / 2)
		{
			x_ray = x_angle * vplane->x_pixel;
			ray = new_vector3(x_ray, y_ray, -1);
			vector_normalize(ray);
			if (sphere_intersect(scene->camera, ray, scene->sphere))
				color = 16777215;
			else
				color = 0;
			mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	t_color color = new_color(125, 125, 125);
	t_coord sphere_center = new_vector3(3, 2, -32);
	t_sphere *sphere = new_sphere(sphere_center, 6, color);
	t_coord cam_origin = new_vector3(0, 0, 0);
	t_coord cam_direction = new_vector3(0, 0, -1);
	t_camera *cam = new_camera(cam_origin, cam_direction, 70);
	t_scene *scene = new_scene(cam, sphere);
	window = mlx_new_window(mlx, WIDTH, HEIGHT, "miniRT");
	ray_tracing(mlx, window, scene);
	// mlx_hook(window, 17, 0, close_minirt, data);
	mlx_loop(mlx);
	return (0);
}
