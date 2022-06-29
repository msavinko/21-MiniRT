/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:41:57 by marlean           #+#    #+#             */
/*   Updated: 2022/06/24 19:24:49 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"

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

typedef struct s_parser
{
	int		file_fd;
	int		read_res;
	char	*line;
	char	**map;
}	t_parser;

//init_parser.c
void	init_parser(t_parser *pars);
void	init_scene(t_scene *scene);
void	init_objects(t_objects *obj);
void	init_cylinder(t_objects *obj);
void	init_data(t_data *data);

//parser.c
void	read_file(t_parser *pars, char *arg);
void	fill_scene(t_parser *pars, t_data *data);
int		open_scene(int argc, char **argv, t_data *data);

// utils_parser.c
void	print_array(char **arr);
void	error_parser(char *str);
void	capital_valid(t_parser *pars);
void	obj_valid(t_parser *pars);

//fill_scene.c
void	fill_color(int *ind, char *str, t_color *color);
void	fill_coord(int *ind, char *str, t_coord *coord);
void	fill_a(char *str, t_alight *alight);
void	fill_c(char *str, t_camera *camera);
void	fill_l(char *str, t_light *light);

//fill_obj.c
void	fill_sp(char *str, t_sphere *sphere);
void	fill_pl(char *str, t_plane *plane);
void	fill_cy(char *str, t_cylind *cylind);

#endif