/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariasavinova <mariasavinova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:48 by marlean           #+#    #+#             */
/*   Updated: 2022/06/27 15:11:16 by mariasavino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void read_file(t_parser *pars, char *arg)
{
	int len;

	len = ft_strlen(arg);
	if (ft_strncmp(&arg[len - 3], ".rt", 3))
		error_parser("You are trying to open file, which is not .rt");
	pars->file_fd = open(arg, O_RDONLY);
	if (pars->file_fd == -1)
		error_parser("Can not open this file");
	pars->read_res = gnl_fd(&pars->line, pars->file_fd);
	if (pars->read_res <= 0)
		error_parser("Can not read this file");
	pars->map = ft_split(pars->line, '\n');
	free(pars->line);
	if (pars->map == NULL)
		error_parser("Empty file");
}

void fill_scene(t_parser *pars, t_data *data)
{
	int i;

	i = 0;
	while (pars->map[i])
	{
		if (pars->map[i][0] == 'A')
			fill_a(pars->map[i], &data->scene.alight);
		else if (pars->map[i][0] == 'C')
			fill_c(pars->map[i], &data->scene.camera);
		else if (pars->map[i][0] == 'L')
			fill_l(pars->map[i], &data->scene.light);
		else if (!ft_strncmp(pars->map[i], "sp ", 3))
			fill_sp(pars->map[i], &data->objects.sphere);
		else if (!ft_strncmp(pars->map[i], "pl ", 3))
			fill_pl(pars->map[i], &data->objects.plane);
		else if (!ft_strncmp(pars->map[i], "cy ", 3))
			fill_cy(pars->map[i], &data->objects.cylind);
		i++;
	}
}

void print_objects(t_data *data)
{
	print_alight(&data->scene.alight);
	print_camera(&data->scene.camera);
	print_light(&data->scene.light);
	print_sphere(&data->objects.sphere);
	print_plane(&data->objects.plane);
	print_cylind(&data->objects.cylind);
}

int open_scene(int argc, char **argv, t_data *data)
{
	t_parser pars;

	init_parser(&pars);
	if (argc != 2)
		error_parser("Wrong number of arguments");
	read_file(&pars, argv[1]);
	capital_valid(&pars);
	obj_valid(&pars);
	letters_valid(&pars);
	fill_scene(&pars, data);
	print_objects(data);
	return (0);
}
