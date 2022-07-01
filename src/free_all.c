/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:34:06 by mariasavino       #+#    #+#             */
/*   Updated: 2022/07/01 13:43:59 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void free_data(t_data *data)
{
	if (data->objects.sphere)
		free(data->objects.sphere);
	if (data->objects.plane)
		free(data->objects.plane);
	if (data->objects.cylind)
		free(data->objects.cylind);
	// if (data)
	// 	free(data);
}
