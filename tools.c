/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:06:30 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/06 20:38:41 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_memdup(void *mem, size_t size)
{
	void	*dup;

	if (!(dup = malloc(size)))
	{
		perror("");
		exit(0);
	}
	ft_memcpy(dup, mem, size);
	return (dup);
}

t_map	dupmap(t_map map)
{
	t_map dup;

	dup.tab = ft_memdup(map.tab, sizeof(*map.tab) * map.dim.length * map.dim.width);
	dup.dim.length = map.dim.length;
	dup.dim.width = map.dim.width;
	return (dup);
}

void	skip_space(char **s)
{
	while (**s && ft_isspace(**s))
		(*s)++;
}

void	skip_notspace(char **s)
{
	while (**s && !ft_isspace(**s))
		(*s)++;
}

int		digitlength(int n)
{
	int i;

	i = 1;
	while ((n /= 10))
		i++;
	return (i);
}

void	printmap(t_map map)
{
	int index;
//	int i;
//	int j;
	int count;

	index = 0;
	while (map.dim.width--)
	{
		count = 0;
		while (count < map.dim.length)
		{
			ft_putnbr(map.tab[index].y);
			ft_putstr(" ");
			if (digitlength(map.tab[index].y) == 2)
				//ft_putchar(' ');
				ft_putstr("    ");
			else if (digitlength(map.tab[index].y) == 1)
				ft_putstr("  ");
			index++;
			count++;
		}
		ft_putchar('\n');
	}
}
