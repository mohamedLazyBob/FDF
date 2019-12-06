/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:58:38 by nkhribec          #+#    #+#             */
/*   Updated: 2019/11/23 16:50:28 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define BUFF_SIZE 1000
# define MAX_FD 4864

int		get_next_line(const int fd, char **line);

#endif
