/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:48 by marlean           #+#    #+#             */
/*   Updated: 2022/07/07 14:26:31 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_parser(t_parser *pars)
{
	int	i;

	i = 0;
	while (pars->map[i])
		free(pars->map[i++]);
	free(pars->map);
}

void	error_parser(char *str)
{
	if (str)
		printf("Error\n%s\n", str);
	exit(1);
}

void	read_file(t_parser *pars, char *arg)
{
	int	len;

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

void	fill_scene(t_parser *pars, t_data *data)
{
	t_count_obj	num;

	num.i = 0;
	num.s = 0;
	num.p = 0;
	num.c = 0;
	while (pars->map[num.i])
	{
		if (pars->map[num.i][0] == 'A')
			fill_a(pars->map[num.i], &data->scene.alight);
		else if (pars->map[num.i][0] == 'C')
			fill_c(pars->map[num.i], &data->scene.camera);
		else if (pars->map[num.i][0] == 'L')
			fill_l(pars->map[num.i], &data->scene.light);
		else if (!ft_strncmp(pars->map[num.i], "sp ", 3))
			fill_sp(pars->map[num.i], &data->objects.sphere[num.s++]);
		else if (!ft_strncmp(pars->map[num.i], "pl ", 3))
			fill_pl(pars->map[num.i], &data->objects.plane[num.p++]);
		else if (!ft_strncmp(pars->map[num.i], "cy ", 3))
			fill_cy(pars->map[num.i], &data->objects.cylind[num.c++]);
		num.i++;
	}
	fill_screen(data);
}

int	open_scene(int argc, char **argv, t_data *data)
{
	t_parser	pars;

	init_parser(&pars);
	if (argc != 2)
		error_parser("Wrong number of arguments");
	read_file(&pars, argv[1]);
	capital_valid(&pars);
	obj_valid(&pars, &data->objects);
	letters_valid(&pars);
	init_data(data);
	fill_scene(&pars, data);
	free_parser(&pars);
	return (0);
}
