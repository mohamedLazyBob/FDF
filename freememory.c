/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 00:55:49 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/13 14:56:06 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	freememory(t_map *map, t_mlxparams *mlxparams)
{
	ft_memdel((void*)&(map->tab));
	ft_memdel((void*)&map);
	ft_memdel((void*)&mlxparams);
}
