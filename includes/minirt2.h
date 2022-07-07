/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:44:55 by marlean           #+#    #+#             */
/*   Updated: 2022/06/30 13:16:18 by rdanyell         ###   ########.fr       */
=======
/*   By: mariasavinova <mariasavinova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:44:55 by marlean           #+#    #+#             */
/*   Updated: 2022/06/30 13:08:09 by mariasavino      ###   ########.fr       */
>>>>>>> 6ee1e8cd219280c94f3ae0fe14c61170dfbf4d9a
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
<<<<<<< HEAD
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

#define WIDTH 800
#define HEIGHT 600
=======
#define MINIRT_H

#include "../mlx_1/mlx.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "parser.h"

#define ESCAPE 53
#define WIDTH 1920
#define WIDTH_S 1440
#define HEIGHT 1080
#define HEIGHT_S 800
>>>>>>> 6ee1e8cd219280c94f3ae0fe14c61170dfbf4d9a

typedef struct s_parser t_parser;

typedef struct s_color //ЦВЕТ
{
	int r;
	int g;
	int b;
} t_color;

typedef struct s_coord //КООРДИНАТЫ
{
	double x;
	double y;
	double z;
} t_coord;

typedef struct s_alight //ОБЩЕЕ ОСВЕЩЕНИЕ
{
	double light_range;
	struct s_color color;
} t_alight;

typedef struct s_camera //КАМЕРА
{
	struct s_coord view_point;
	struct s_coord orient_vector;
	double horiz_degrees;
} t_camera;

typedef struct s_camera2 //КАМЕРА
{
	struct s_coord	*position;
	struct s_coord	*orient;
	double			fov;
}	t_camera2;

typedef struct s_light //НАПРАВЛЕННЫЙ СВЕТ
{
	struct s_coord coord;
	double bright;
} t_light;

typedef struct s_scene //СТРУКТУРА С ОБЩИМ СВЕТОМ, КАМЕРОЙ, НАПРАВЛЕННЫМ СВЕТОМ
{
<<<<<<< HEAD
	struct s_alight	alight;
	struct s_camera	*camera;
	struct s_sphere	*sphere;
	// float			width;
	// float			height;
	struct s_light	light;
}	t_scene;

typedef struct s_scene2 //СТРУКТУРА С ОБЩИМ СВЕТОМ, КАМЕРОЙ, НАПРАВЛЕННЫМ СВЕТОМ
{
	struct s_alight	alight;
	struct s_camera2	*camera;
	struct s_sphere2	*sphere;
	// float			width;
	// float			height;
	struct s_light	light;
}	t_scene2;

typedef struct s_sphere // СФЕРА 
=======
	struct s_alight alight;
	struct s_camera camera;
	struct s_light light;
} t_scene;

typedef struct s_sphere // СФЕРА
>>>>>>> 6ee1e8cd219280c94f3ae0fe14c61170dfbf4d9a
{
	struct s_coord coord;
	double diameter;
	struct s_color color;
} t_sphere;

typedef struct s_sphere2 // СФЕРА 
{
	struct s_coord	*position;
	double			radius;
	struct s_color	color;
}	t_sphere2;

typedef struct s_plane // ПЛОСКОСТЬ
{
	struct s_coord coord;
	struct s_coord orient_vector;
	struct s_color color;
} t_plane;

typedef struct s_cylind // ЦИЛИНДР
{
	struct s_coord coord;
	struct s_coord orient_vector;
	double diameter;
	double height;
	struct s_color color;
} t_cylind;

typedef struct s_objects //СТРУКТУРА С ОБЪЕКТАМИ
{
	struct s_sphere *sphere;
	struct s_plane *plane;
	struct s_cylind *cylind;
	int nplane;
	int nsphere;
	int ncylinder;
} t_objects;

// ОБЩАЯ СТРУКТУРА В КОТОРОЙ ХРАНЯТСЯ И ОБЪЕКТЫ И ОСВЕЩЕНИЕ
typedef struct s_data
{
<<<<<<< HEAD
	struct s_objects	objects;
	struct s_scene		scene;
	void				*mlx;
	void				*window;
	t_img				*img;
}	t_data;

//print_structs.c
void	print_array(char **arr);

void	print_alight(t_alight *alight);
void	print_camera(t_camera *camera);
void	print_light(t_light *light);
void	print_sphere(t_sphere *sphere);
void	print_plane(t_plane *plane);
void	print_cylind(t_cylind *cylind);

//vector.c
// t_vector2	new_vector2(double u, double v);
// t_coord		new_vector3(double x, double y, double z);
// t_coord		vector_subtract(t_coord a, t_coord b);
// t_coord		vector_addition(t_coord a, t_coord b);
// t_coord		vector_multiply(t_coord direction, double multiply);
// double		vector_length(t_coord a);
// double		vector_sumpow2(t_coord a);
// double		vector_scalar(t_coord a, t_coord b);
// void		vector_normalize(t_coord a);

//utils.c
void	ft_error(int error);
void	ft_exit(int status);

//sphere.c
//t_sphere	*new_sphere(t_coord position, double radius, t_color color);
int			sphere_intersect(t_camera *cam, t_coord ray, t_sphere *sphere);

//scene.c
t_scene	*new_scene(t_camera *camera, t_sphere *sphere);

//camera.c
t_camera	*new_camera(t_coord position, t_coord orient, double fov);

//rdanyell

t_coord	*new_vec(double x, double y, double z);
double	vec_length(t_coord *a);
t_coord	*vec_subtract(t_coord *a, t_coord *b);
void	vec_normalize(t_coord *a);
t_coord	*vec_addition(t_coord *a, t_coord *b);
double	vec_scalar(t_coord *a, t_coord *b); // vec_dot_product
t_sphere2	*new_sphere2(t_coord *position, double radius, t_color color);
t_camera2	*new_cam(t_coord *position, t_coord *orient, double fov);
int	sphere_intersect2(t_camera2 *cam, t_coord *ray, t_sphere2 *sphere);
t_scene2	*new_scene2(t_camera2 *camera, t_sphere2 *sphere);

=======
	struct s_objects objects;
	struct s_scene scene;
	void *mlx;
	void *window;
} t_data;

// print_structs.c
void print_objects(t_data *data);

void print_array(char **arr);
void print_alight(t_alight *alight);
void print_camera(t_camera *camera);
void print_light(t_light *light);
void print_sphere(t_sphere *sphere);
void print_plane(t_plane *plane);
void print_cylind(t_cylind *cylind);
>>>>>>> 6ee1e8cd219280c94f3ae0fe14c61170dfbf4d9a
#endif