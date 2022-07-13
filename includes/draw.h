/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:06:29 by marlean           #+#    #+#             */
/*   Updated: 2022/07/13 14:50:32 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
#define DRAW_H

#include "minirt.h"
# define SPHERE 1
# define PLANE 2
# define CYLINDER 3
# define DISK 4
# define BACK 11988192

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

typedef struct	s_dist
{
	float min_dist;
	float dist;
	int near_obj;
	int n_obj;
	struct s_coord *dot_light;
	struct s_coord *dot_normal;
}	t_dist;

void draw(t_data *data);
void ray_tracing(t_data *data);
void shadow(t_data *data, t_color *color, t_coord *ray, float min_dist);

t_coord new_vector3(float x, float y, float z);
t_coord vector_subtract(t_coord a, t_coord b);
t_coord vector_addition(t_coord a, t_coord b);
float vector_length(t_coord a);
void vector_normalize(t_coord *a);
void vector_multiply(t_coord *direction, float multiply);
float vector_sumpow2(t_coord a);
float vector_scalar(t_coord a, t_coord b);
t_coord vec3_mul(t_coord a, t_coord b);

float sphere_intersect(t_camera cam, t_coord ray, t_sphere *sphere);
float plane_intersect(struct s_camera cam, t_coord ray, t_plane *plane);
float cylindr_intersect(struct s_camera cam, t_coord ray, t_cylind *cylind);

// float set_color(t_color color);
char *ft_dectohex(unsigned int num);
unsigned long htoi(const char *s);

int	draw_dot(t_data *data, t_dist *dist, float flag);

//dist_obj.c
void nearest_sphere(t_data *data, t_dist *dist, t_coord *ray);
void nearest_plane(t_data *data, t_dist *dist, t_coord *ray);
void nearest_cylind(t_data *data, t_dist *dist, t_coord *ray);

//shadow.c
int shadow_sphere(t_data *data, t_dist *dist, t_coord * ray);
int shadow_plane(t_data *data, t_dist *dist, t_coord *ray);

float sphere_intersect(t_camera cam, t_coord ray, t_sphere *sphere);
float	plane_intersect(struct s_camera cam, t_coord ray,  t_plane *plane);
float cylindr_intersect(struct s_camera cam, t_coord ray,  t_cylind *cylind);

//shadow_intersect.c
float shadow_sphere_intersect(t_coord *dot_light, t_sphere *sphere, t_coord *dot_sphere);
float	shadow_plane_intersect(t_coord *dot_light, t_plane *plane, t_coord *dot_sphere);



#endif
