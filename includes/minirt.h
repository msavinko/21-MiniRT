/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:44:55 by marlean           #+#    #+#             */
/*   Updated: 2022/07/04 11:15:02 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
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
#include "draw.h"

#define ESCAPE 53
#define WIDTH_1 1920.00
#define HEIGHT_1 1080.00

#define WIDTH 800.00
#define HEIGHT 600.00


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
	double fov;
} t_camera;

typedef struct s_light //НАПРАВЛЕННЫЙ СВЕТ
{
	struct s_coord coord;
	double bright;
} t_light;

typedef struct s_sphere // СФЕРА
{
	struct s_coord coord;
	double radius;
	struct s_color color;
} t_sphere;

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

typedef struct s_scene //СТРУКТУРА С ОБЩИМ СВЕТОМ, КАМЕРОЙ, НАПРАВЛЕННЫМ СВЕТОМ
{
	struct s_alight alight;
	struct s_camera camera;
	struct s_light light;
} t_scene;

typedef struct s_screen // ЭКРАН
{
	double	width;
	double	height;
	double	x_pixel;
	double	y_pixel;
	// double	fov;
} t_screen;
// ОБЩАЯ СТРУКТУРА В КОТОРОЙ ХРАНЯТСЯ И ОБЪЕКТЫ И ОСВЕЩЕНИЕ
typedef struct s_data
{
	struct s_objects objects;
	struct s_scene scene;
	struct s_screen screen;
	void *mlx;
	void *window;
	void *img;
} t_data;

// free_all.c
void free_data(t_data *data);

// print_structs.c
void print_objects(t_data *data);

#endif
