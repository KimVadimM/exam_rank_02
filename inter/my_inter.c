/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Smeeblin <kvm1986@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:23:59 by Smeeblin          #+#    #+#             */
/*   Updated: 2020/08/26 14:43:20 by Smeeblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    char mass[255];
    int i = 0;
    int y = 0;
    while (i != 255)
    { 
        mass[i] = 0;
        i++;
    }
    if (argc == 3)
    {
        i = 2;
        while (argv[2][y])
        {
            if (mass[argv[2][y]] != 1)
                mass[argv[2][y]] = 1;
            y++;
        }
        y = 0;
        while (argv[1][y])
        {
            if (mass[argv[1][y]] == 1)
            {
                mass[argv[1][y]] = 0;
                write(1, &argv[1][y], 1);
            }
            y++;
        }
    }
    write(1, "\n", 1);
    return (0);


}