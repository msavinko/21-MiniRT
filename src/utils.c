/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/06/24 19:08:03 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_exit(int status)
{
	// kd_free_all();
	exit(status);
}

void	ft_error(int error)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (error == -1)
		ft_putstr_fd("Malloc error!\n", STDERR_FILENO);
	else if (error == 1)
		ft_putstr_fd("Error with filename argument\n", STDERR_FILENO);
	else if (error == 2)
		ft_putstr_fd("Error during file opening\n", STDERR_FILENO);
	else if (error == 3)
		ft_putstr_fd("Error during sphere initialization\n", STDERR_FILENO);
	else if (error == 4)
		ft_putstr_fd("Error during camera initialization\n", STDERR_FILENO);
	else if (error == 5)
		ft_putstr_fd("Wrong type identifier\n", STDERR_FILENO);
	else if (error == 6)
		ft_putstr_fd("Error during ambient light init\n", STDERR_FILENO);
	else if (error == 7)
		ft_putstr_fd("Error during lighter initialization\n", STDERR_FILENO);
	else if (error == 8)
		ft_putstr_fd("Error during plane initialization\n", STDERR_FILENO);
	else if (error == 9)
		ft_putstr_fd("Error during cylinder initialization\n", STDERR_FILENO);
	else if (error == 10)
		ft_putstr_fd("Light color specified in the mandatory part\n",
			STDERR_FILENO);
	else if (error == 11)
		ft_putstr_fd("Error during screen resulution setting up.\n", STDERR_FILENO);
	ft_exit(error);
}
