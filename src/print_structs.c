/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:13:45 by marlean           #+#    #+#             */
/*   Updated: 2022/06/24 19:49:21 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

void	print_alight(t_alight *alight)
{
	printf("\n****Ambient light****\n");
	printf("Light range: %.2f\n", alight->light_range);
	printf("Color: %d,%d,%d\n", alight->color.r,
		alight->color.g, alight->color.b);
	printf("*********************\n");
}

void	print_camera(t_camera *camera)
{
	printf("\n*******Camera*******\n");
	printf("View point: %.2f,%.2f,%.2f\n", camera->position.x,
		camera->position.y, camera->position.z);
	printf("Orientation vector: %.2f,%.2f,%.2f\n", camera->orient.x,
		camera->orient.y, camera->orient.z);
	printf("Horizontal degree: %.2f\n", camera->fov);
	printf("*********************\n");
}

void	print_light(t_light *light)
{
	printf("\n********Light********\n");
	printf("Light point: %.2f,%.2f,%.2f\n", light->coord.x,
		light->coord.y, light->coord.z);
	printf("Brightness: %.2f\n", light->bright);
	printf("*********************\n");
}

void	print_sphere(t_sphere *sphere)
{
	printf("\n*******Sphere*******\n");
	printf("Coord: %.2f,%.2f,%.2f\n", sphere->position.x,
		sphere->position.y, sphere->position.z);
	printf("Diameter: %.2f\n", sphere->radius);
	printf("Color: %d,%d,%d\n", sphere->color.r,
		sphere->color.g, sphere->color.b);
	printf("*********************\n");
}

void	print_plane(t_plane *plane)
{
	printf("\n*******Plane*******\n");
	printf("Coord: %.2f,%.2f,%.2f\n", plane->coord.x,
		plane->coord.y, plane->coord.z);
	printf("Orientation vector: %.2f,%.2f,%.2f\n", plane->orient_vector.x,
		plane->orient_vector.y, plane->orient_vector.z);
	printf("Color: %d,%d,%d\n", plane->color.r,
		plane->color.g, plane->color.b);
	printf("*********************\n");
}

void	print_cylind(t_cylind *cylind)
{
	printf("\n******Cylinder******\n");
	printf("Coord: %.2f,%.2f,%.2f\n", cylind->coord.x,
		cylind->coord.y, cylind->coord.z);
	printf("Orientation vector: %.2f,%.2f,%.2f\n", cylind->orient_vector.x,
		cylind->orient_vector.y, cylind->orient_vector.z);
	printf("Diameter: %.2f\n", cylind->diameter);
	printf("Height: %.2f\n", cylind->height);
	printf("Color: %d,%d,%d\n", cylind->color.r,
		cylind->color.g, cylind->color.b);
	printf("*********************\n");
}
