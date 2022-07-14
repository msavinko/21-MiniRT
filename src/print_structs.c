/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:13:45 by marlean           #+#    #+#             */
/*   Updated: 2022/07/06 11:37:34 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"



void print_array(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

void print_alight(t_alight *alight)
{
	printf("\n****Ambient light****\n");
	printf("Light range: %.2f\n", alight->light_range);
	printf("Color: %d,%d,%d\n", alight->color.r,
		   alight->color.g, alight->color.b);
	printf("*********************\n");
}

void print_camera(t_camera *camera)
{
	printf("\n*******Camera*******\n");
	printf("View point: %.2f,%.2f,%.2f\n", camera->view_point.x,
		   camera->view_point.y, camera->view_point.z);
	printf("Orientation vector: %.2f,%.2f,%.2f\n", camera->orient_vector.x,
		   camera->orient_vector.y, camera->orient_vector.z);
	printf("Horizontal degree: %.2f\n", camera->fov);
	printf("*********************\n");
}

void print_light(t_light *light)
{
	printf("\n********Light********\n");
	printf("Light point: %.2f,%.2f,%.2f\n", light->coord.x,
		   light->coord.y, light->coord.z);
	printf("Brightness: %.2f\n", light->bright);
	printf("*********************\n");
}

void print_sphere(t_sphere *sphere)
{
	printf("\n*******Sphere*******\n");
	printf("Coord: %.2f,%.2f,%.2f\n", sphere->coord.x,
		   sphere->coord.y, sphere->coord.z);
	printf("Diameter: %.2f\n", sphere->radius);
	printf("Color: %d,%d,%d\n", sphere->color.r,
		   sphere->color.g, sphere->color.b);
	printf("*********************\n");
}

void print_plane(t_plane *plane)
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

void print_cylind(t_cylind *cylind)
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

void print_screen(t_data *data)
{
	printf("\n******Screen******\n");
	printf("width: %.2f, height: %.2f\n", data->screen.width, data->screen.height);
	printf("x_pix: %.2f, y_pix: %.2f\n", data->screen.x_pixel, data->screen.y_pixel);
	printf("*********************\n");
}

void print_objects(t_data *data)
{
	int i = 0;
	print_screen(data);
	print_alight(&data->scene.alight);
	print_camera(&data->scene.camera);
	print_light(&data->scene.light);
	while (i < data->objects.nsphere)
	{
		print_sphere(&data->objects.sphere[i]);
		i++;
	}
	i = 0;
	while (i < data->objects.nplane)
	{
		print_plane(&data->objects.plane[i]);
		i++;
	}
	i = 0;
	while (i < data->objects.ncylinder)
	{
		print_cylind(&data->objects.cylind[i]);
		i++;
	}
}