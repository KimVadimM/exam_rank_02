/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Smeeblin <kvm1986@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:29:19 by ncolomer          #+#    #+#             */
/*   Updated: 2020/08/26 21:34:46 by Smeeblin         ###   ########.fr       */
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
	while ((get_next_line(r, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
}
