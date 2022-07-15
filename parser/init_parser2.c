/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:28:15 by marlean           #+#    #+#             */
/*   Updated: 2022/07/07 14:31:23 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_sphere(t_sphere *sphere)
{
	sphere->coord.x = 0.0f;
	sphere->coord.y = 0.0f;
	sphere->coord.z = 0.0f;
	sphere->radius = 0.0f;
	sphere->color.r = 0;
	sphere->color.g = 0;
	sphere->color.b = 0;
}

void	init_plane(t_plane *plane)
{
	plane->coord.x = 0.0f;
	plane->coord.y = 0.0f;
	plane->coord.z = 0.0f;
	plane->orient_vector.x = 0.0f;
	plane->orient_vector.y = 0.0f;
	plane->orient_vector.z = 0.0f;
	plane->color.r = 0;
	plane->color.g = 0;
	plane->color.b = 0;
}

void	init_cylinder(t_cylind *cylind)
{
	cylind->coord.x = 0.0f;
	cylind->coord.y = 0.0f;
	cylind->coord.z = 0.0f;
	cylind->orient_vector.x = 0.0f;
	cylind->orient_vector.y = 0.0f;
	cylind->orient_vector.z = 0.0f;
	cylind->diameter = 0.0f;
	cylind->height = 0.0f;
	cylind->color.r = 0;
	cylind->color.g = 0;
	cylind->color.b = 0;
}
