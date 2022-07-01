/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:06:29 by marlean           #+#    #+#             */
/*   Updated: 2022/07/01 12:42:43 by marlean          ###   ########.fr       */
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

void	draw(t_data *data);
void	ray_tracing(t_data *data);

#endif