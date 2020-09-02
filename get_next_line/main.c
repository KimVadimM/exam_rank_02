/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Smeeblin <kvm1986@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:29:19 by ncolomer          #+#    #+#             */
/*   Updated: 2020/09/02 19:05:40 by smeeblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int
	main(int argc, char **argv)
{
	int		r;
	char	*line;
	
	if (argc != 2)
		return (0);

	r = open(argv[1], O_RDONLY);
	line = NULL;
	/*
	int i = 0;
	while(i < 3)
	{
		get_next_line(r, &line);
		printf("%s\n", line);
		free(line);
		i++;
	}
	*/

	while ((get_next_line(r, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s\n", line);

	free(line);
	line = NULL;
}
