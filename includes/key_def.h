/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_def.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:09:45 by mcherrie          #+#    #+#             */
/*   Updated: 2022/07/28 17:44:13 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_DEF_H
# define KEY_DEF_H

# include "minirt.h"

# define ESCAPE 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define DIST_PLUS 24
# define DIST_MIN 27

# define W 13
# define A 0
# define S 1
# define D 2
# define X 7
# define Y 16
# define Z 6
# define L 37
# define K 40
# define O 31
# define R 15
# define E 14

typedef struct s_data	t_data;
int	ft_key_hook(int keycode, t_data *data);
int	ft_mouse_hook(int mousecode, int x, int y, t_data *data);
int	ft_mouse(int mouse, int x, int y, t_data *data);
int	ft_key_hook_coord(int keycode, t_data *data);
int	ft_radius(int keycode, t_data *data);
int	ft_z_move(int keycode, t_data *data);
int	ft_y_move(int keycode, t_data *data);
int	ft_x_move(int keycode, t_data *data);
int	ft_o_move(int keycode, t_data *data);

#endif
