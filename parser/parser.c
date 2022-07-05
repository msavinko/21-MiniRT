/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherrie <mcherrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:48 by marlean           #+#    #+#             */
/*   Updated: 2022/07/02 19:39:23 by mcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void free_parser(t_parser *pars)
{
	int i;

	i = 0;
	while (pars->map[i])
		free(pars->map[i++]);
	free(pars->map);
}

void error_parser(char *str)
{
	if (str)
		printf("Error\n%s\n", str);
	exit(1);
}

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

void fill_screen(t_data *data)
{
	data->screen.width = 2 * tan(data->scene.camera.fov / 180 * M_PI);
	data->screen.height = data->screen.width * HEIGHT / WIDTH;
	data->screen.x_pixel = data->screen.width / WIDTH;
	data->screen.y_pixel = data->screen.height / HEIGHT;
}

void fill_scene(t_parser *pars, t_data *data)
{
	int i;
	int s;
	int p;
	int c;

	i = 0;
	s = 0;
	p = 0;
	c = 0;
	while (pars->map[i])
	{
		if (pars->map[i][0] == 'A')
			fill_a(pars->map[i], &data->scene.alight);
		else if (pars->map[i][0] == 'C')
			fill_c(pars->map[i], &data->scene.camera);
		else if (pars->map[i][0] == 'L')
			fill_l(pars->map[i], &data->scene.light);
		else if (!ft_strncmp(pars->map[i], "sp ", 3))
			fill_sp(pars->map[i], &data->objects.sphere[s++]);
		else if (!ft_strncmp(pars->map[i], "pl ", 3))
			fill_pl(pars->map[i], &data->objects.plane[p++]);
		else if (!ft_strncmp(pars->map[i], "cy ", 3))
			fill_cy(pars->map[i], &data->objects.cylind[c++]);
		i++;
	}
	fill_screen(data);
}

int open_scene(int argc, char **argv, t_data *data)
{
	t_parser pars;
	(void)data;
	//(void)argv;
	init_parser(&pars);
	if (argc != 2)
		error_parser("Wrong number of arguments");
	read_file(&pars, argv[1]);
	capital_valid(&pars);
	obj_valid(&pars, &data->objects);
	letters_valid(&pars);
	init_data(data);
	fill_scene(&pars, data);
	// print_objects(data);
	free_parser(&pars);
	return (0);
}
