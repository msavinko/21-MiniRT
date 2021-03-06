/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:06:29 by marlean           #+#    #+#             */
/*   Updated: 2022/07/28 15:45:55 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "minirt.h"
# define SPHERE 1
# define PLANE 2
# define CYLINDER 3
# define BOTTOM_DISK 4
# define TOP_DISK 5
# define BACK 11988192

typedef struct s_scene		t_scene;
typedef struct s_alight		t_alight;
typedef struct s_camera		t_camera;
typedef struct s_light		t_light;
typedef struct s_coord		t_coord;
typedef struct s_color		t_color;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylind		t_cylind;
typedef struct s_objects	t_objects;
typedef struct s_data		t_data;
typedef struct s_draw		t_draw;

typedef struct s_dist
{
	float			min_dist;
	float			dist;
	int				near_obj;
	int				n_obj;
	struct s_coord	*dot_light;
}	t_dist;

typedef struct s_coef
{
	float	a;
	float	b;
	float	c;
	float	discr;
}	t_coef;

int		draw_dot(t_data *data, t_dist *dist, float intens_light);
void	nearest_sphere(t_data *data, t_dist *dist, t_coord *ray);
void	nearest_plane(t_data *data, t_dist *dist, t_coord *ray);
void	nearest_cylind(t_data *data, t_dist *dist, t_coord *ray);
void	draw(t_data *data);
float	dot_normal(t_data *data, t_dist *dist, t_coord *dot);
void	get_discr(t_camera cam, t_coord ray, t_cylind *cylind, t_coef *coef);
void	get_nearest(t_dist *dist, float dist_min, float *dist_disc, int *i);
void	get_plane(t_plane *plane, t_cylind cylind);
int		shadow_sphere(t_data *data, t_dist *dist, t_coord *ray);
int		shadow_plane(t_data *data, t_dist *dist, t_coord *ray);
int		shadow_cylinder(t_data *data, t_dist *dist, t_coord *ray);
float	sphere_intersect(t_camera cam, t_coord ray, t_sphere *sphere);
float	plane_intersect(struct s_camera cam, t_coord ray, t_plane *plane);
float	cylindr_intersect(t_data *data, t_coord ray, t_dist *dist, int *i);
float	shadow_cylindr_intersect(t_coord *dot_light,
			t_cylind *cylind, t_coord *dot);
void	vector_normalize(t_coord *a);
void	vector_multiply(t_coord *direction, float multiply);
t_coord	mult(t_coord direction, float multiply);
t_coord	vec3_mul(t_coord a, t_coord b);
t_coord	vec_vec_mul(t_coord a, t_coord b);
float	vec_scl(t_coord a, t_coord b);
float	vec_len(t_coord a);
t_coord	new_vector3(float x, float y, float z);
t_coord	new_vector(t_coord vec);
t_coord	vec_sub(t_coord a, t_coord b);
t_coord	vector_addition(t_coord a, t_coord b);

#endif
