/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherrie <mcherrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:44:55 by marlean           #+#    #+#             */
/*   Updated: 2022/07/22 16:14:27 by mcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../mlx_1/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include "parser.h"
# include "draw.h"
# include "key_def.h"

# define WIDTH 1200.00
# define HEIGHT 1000.00

typedef struct s_color //ЦВЕТ
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_coord //КООРДИНАТЫ
{
	float	x;
	float	y;
	float	z;
}	t_coord;

typedef struct s_alight //ОБЩЕЕ ОСВЕЩЕНИЕ
{
	float			light_range;
	struct s_color	color;
}	t_alight;

typedef struct s_camera //КАМЕРА
{
	struct s_coord	view_point;
	struct s_coord	orient_vector;
	float			fov;
}	t_camera;

typedef struct s_light //НАПРАВЛЕННЫЙ СВЕТ
{
	struct s_coord	coord;
	float			bright;
}	t_light;

typedef struct s_sphere // СФЕРА
{
	struct s_coord	coord;
	float			radius;
	struct s_color	color;
}	t_sphere;

typedef struct s_plane // ПЛОСКОСТЬ
{
	struct s_coord	coord;
	struct s_coord	orient_vector;
	struct s_color	color;
}	t_plane;

typedef struct s_cylind // ЦИЛИНДР
{
	struct s_coord	coord;
	struct s_coord	orient_vector;
	float			diameter;
	float			height;
	struct s_color	color;
}	t_cylind;

typedef struct s_objects //СТРУКТУРА С ОБЪЕКТАМИ
{
	struct s_sphere	*sphere;
	struct s_plane	*plane;
	struct s_cylind	*cylind;
	int				nplane;
	int				nsphere;
	int				ncylinder;
}	t_objects;

typedef struct s_scene //СТРУКТУРА С ОБЩИМ СВЕТОМ, КАМЕРОЙ, НАПРАВЛЕННЫМ СВЕТОМ
{
	struct s_alight	alight;
	struct s_camera	camera;
	struct s_light	light;
}	t_scene;

typedef struct s_screen // ЭКРАН
{
	float	width;
	float	height;
	float	x_pixel;
	float	y_pixel;
}	t_screen;

typedef struct s_draw
{
	int		mlx_x;
	int		mlx_y;
	int		x_angle;
	int		y_angle;
	int		color;
	float	x_ray;
	float	y_ray;
	t_coord	*ray;
}	t_draw;

// ОБЩАЯ СТРУКТУРА В КОТОРОЙ ХРАНЯТСЯ И ОБЪЕКТЫ И ОСВЕЩЕНИЕ
typedef struct s_data
{
	struct s_objects	objects;
	struct s_scene		scene;
	struct s_screen		screen;
	struct s_dist		m_dist;
	void				*mlx;
	void				*window;
	void				*img;
}	t_data;

void	free_data(t_data *data);
int		close_minirt(t_data *data);

#endif
