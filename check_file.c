/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:13:41 by nkhribec          #+#    #+#             */
/*   Updated: 2019/11/24 18:25:08 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_file_valid(int nbr_of_arg, char **arg)
{
	int		fd;
	char	c;

	if (nbr_of_arg == 2)
	{
		fd = open(arg[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putstr("No file ");
			ft_putendl(arg[1]);
		}
		else if (read(fd, &c, 0) < 0)
			ft_putendl("No data found.");
		else
			return (fd);
	}
	else
	{
		ft_putstr("Usage : ");
		ft_putstr(arg[0]);
		ft_putendl(" <filename> [ case_size z_size ]");
	}
	return (0);
}
