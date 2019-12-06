/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 00:38:50 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/01 14:29:49 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>



int main()
{
	int		*fd;

	//fd = open("adam", O_RDONLY);
	fd = malloc(sizeof(int) * 10000000000);
	//if (fd < 0)
	//{
		printf("%d\n", errno);
		perror("yes it work");
	//}
	return (0);
}
