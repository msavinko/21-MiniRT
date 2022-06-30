/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariasavinova <mariasavinova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:54 by marlean           #+#    #+#             */
/*   Updated: 2022/06/30 13:52:44 by mariasavino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void capital_valid(t_parser *pars)
{
	int i;
	int a;
	int c;
	int l;

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

void obj_valid(t_parser *pars, t_objects *obj)
{
	int i;

	i = 0;
	obj->nplane = 0;
	obj->nsphere = 0;
	obj->ncylinder = 0;
	while (pars->map[i])
	{
		if (!ft_strncmp(pars->map[i], "sp ", 3))
			obj->nsphere++;
		if (!ft_strncmp(pars->map[i], "pl ", 3))
			obj->nplane++;
		if (!ft_strncmp(pars->map[i], "cy ", 3))
			obj->ncylinder++;
		i++;
	}
	if (!obj->nplane || !obj->nsphere || !obj->ncylinder)
		error_parser("You need at least these 3 simple geometric objects: plane, sphere, cylinder.");
	// printf("plane: %d, sphere: %d, cylinder: %d", obj->nplane, obj->nsphere, obj->ncylinder);
}

void letters_valid(t_parser *pars)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (pars->map[i])
	{
		while (ft_isalpha(pars->map[i][j]))
			j++;
		while (pars->map[i][j])
		{
			// printf("1 %c\n", pars->map[i][j]);
			while (ft_isspace(pars->map[i][j]))
				j++;
			// printf("2 %c\n", pars->map[i][j]);
			if (ft_isdigit(pars->map[i][j]) || pars->map[i][j] == '.' || pars->map[i][j] == ',' || pars->map[i][j] == '-' || pars->map[i][j] == '+')
				j++;
			else
				error_parser("Map contains non-valid caracters");
			// printf("3 %c\n", pars->map[i][j]);
		}
		j = 0;
		i++;
	}
}