/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_def.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:10:34 by mariasavino       #+#    #+#             */
/*   Updated: 2022/07/12 15:16:06 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_DEF_H
#define KEY_DEF_H

#include "minirt.h"

#define ESCAPE 53
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define DIST_PLUS 24
#define DIST_MIN 27
#define CAM_LEFT 0
#define CAM_RIGHT 2
#define CAM_UP 13
#define CAM_DOWN 1
#define	W 13
#define A 0
#define S 1
#define D 2

typedef struct s_data t_data;
int ft_key_hook(int keycode, t_data *data);
#endif