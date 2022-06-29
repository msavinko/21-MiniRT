/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:54 by marlean           #+#    #+#             */
/*   Updated: 2022/06/24 18:45:15 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	error_parser(char *str)
{
	if (str)
		printf("Error\n%s\n", str);
	exit(1);
}

void	capital_valid(t_parser *pars)
{
	int	i;
	int	a;
	int	c;
	int	l;

	i = 0;
	a = 0;
	c = 0;
	l = 0;
	while (pars->map[i])
	{
		if (pars->map[i][0] == 'A')
			a++;
		else if (pars->map[i][0] == 'C')
			c++;
		else if (pars->map[i][0] == 'L')
			l++;
		i++;
	}
	if (a != 1 || c != 1 || l != 1)
		error_parser("Elements which are defined by a capital \
		letter can only be declared once in the scene");
}

void	obj_valid(t_parser *pars)
{
	int	i;
	int	plane;
	int	sphere;
	int	cylinder;

	i = 0;
	plane = 0;
	sphere = 0;
	cylinder = 0;
	while (pars->map[i])
	{
		if (!ft_strncmp(pars->map[i], "sp ", 3))
			sphere++;
		if (!ft_strncmp(pars->map[i], "pl ", 3))
			plane++;
		if (!ft_strncmp(pars->map[i], "cy ", 3))
			cylinder++;
		i++;
	}
	if (!plane || !sphere || !cylinder)
		error_parser("You need at least these 3 simple geometric \
		objects: plane, sphere, cylinder.");
}
