/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:23:16 by marlean           #+#    #+#             */
/*   Updated: 2022/07/05 12:52:45 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int set_color(t_color color, float l)
{
	float result;
	(void)l;
	// float r = color.r * l;
	// float g = color.g * l;
	// float b = color.b * l;
	// result = r * 65536.0f + g * 256.0f + b ;
	result = color.r  * 65536.0f + color.g * 256.0f + color.b;
	// printf("r: %.2f g: %.2f b: %.2f color: %.2f\n", r, g, b, result);
	// printf("res: %.2f\n", result);
	return (result);
}