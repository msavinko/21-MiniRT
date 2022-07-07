/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:05:40 by marlean           #+#    #+#             */
/*   Updated: 2022/06/24 14:07:27 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_fd(char **line, int fd)
{
	int		result;
	int		i;
	char	*buffer;

	buffer = malloc(100000);
	if (!buffer)
		return (0);
	i = 0;
	*line = buffer;
	result = read(fd, &buffer[i], 1);
	while (result > 0 && buffer[i] != '\0')
	{
		i++;
		result += read(fd, &buffer[i], 1);
	}	
	buffer[i] = '\0';
	return (result);
}
