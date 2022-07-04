/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariasavinova <mariasavinova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:06:29 by marlean           #+#    #+#             */
/*   Updated: 2022/07/04 15:39:55 by mariasavino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
#define DRAW_H

#include "minirt.h"

typedef struct s_scene t_scene;
typedef struct s_alight t_alight;
typedef struct s_camera t_camera;
typedef struct s_light t_light;
typedef struct s_coord t_coord;
typedef struct s_color t_color;
typedef struct s_sphere t_sphere;
typedef struct s_plane t_plane;
typedef struct s_cylind t_cylind;
typedef struct s_objects t_objects;
typedef struct s_data t_data;

void draw(t_data *data);
void ray_tracing(t_data *data);

t_coord new_vector3(double x, double y, double z);
t_coord vector_subtract(t_coord a, t_coord b);
t_coord vector_addition(t_coord a, t_coord b);
double vector_length(t_coord a);
void vector_normalize(t_coord *a);
void vector_multiply(t_coord *direction, double multiply);
double vector_sumpow2(t_coord a);
double vector_scalar(t_coord a, t_coord b);

int sphere_intersect(t_camera cam, t_coord ray, t_sphere *sphere);

int set_color(t_color color);
#endif
