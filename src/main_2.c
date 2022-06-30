/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/06/30 14:11:55 by rdanyell         ###   ########.fr       */
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
	vplane = (t_vplane *)malloc(sizeof(t_vplane *));
	if (!vplane)
		ft_error(1);
	aspect_ratio = width / height;
	vplane->width = 1;
	vplane->height = vplane->width / aspect_ratio;
	vplane->x_pixel = vplane->width / width;
	vplane->y_pixel = vplane->height / height;
	return (vplane);
}

void	ray_tracing(void *mlx, void *window, t_scene2 *scene)
{
	int			mlx_x;
	int			mlx_y;
	double		x_angle;
	double		y_angle;
	int			color;
	double		x_ray;
	double		y_ray;
	t_coord		*ray;
	t_vplane	*vplane;

	vplane = get_view_plane(WIDTH, HEIGHT, scene->camera->fov);
	mlx_y = 0;
	y_angle = HEIGHT / 2;
	while (y_angle >= (HEIGHT / 2) * (-1))
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = (WIDTH / 2) * (-1);
		mlx_x = 0;
		while (x_angle <= WIDTH / 2)
		{
			x_ray = x_angle * vplane->x_pixel;
			ray = new_vec(x_ray, y_ray, -1);
			vec_normalize(ray);
			if (sphere_intersect2(scene->camera, ray, scene->sphere))
				color = 16777215;
			else
				color = 0;
			mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);
			//printf("mlx_x = %d mlx_y = %d\n", mlx_x, mlx_y);
			free(ray);
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
	t_color color = new_color(0, 125, 125);
	t_coord *sphere_center = new_vec(-2, 5, -100);
	t_sphere2 *sphere = new_sphere2(sphere_center, 6, color);
	t_coord *cam_origin = new_vec(0, 0, 0);
	t_coord *cam_direction = new_vec(0, 0, -1);
	t_camera2 *cam = new_cam(cam_origin, cam_direction, 70);
	t_scene2 *scene = new_scene2(cam, sphere);
	printf("Hello\n");
	window = mlx_new_window(mlx, WIDTH, HEIGHT, "miniRT");
	ray_tracing(mlx, window, scene);
	// mlx_hook(window, 17, 0, close_minirt, data);
	mlx_loop(mlx);
	//free_scene(scene);
	return (0);
}
