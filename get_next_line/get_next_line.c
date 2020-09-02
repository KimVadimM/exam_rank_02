#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
// 1 fail - 1.16
// 2 semifail - 1.01
// 3 not full success - 25 min;

int ft_strlen(char *str)
{
    int i = 0;
    if (!str)
        return (0);
    while(str[i])
        i++;
    return (i);
}

char *ft_strjoin(char *remains, char *buffer)
{
    if (!remains && !buffer)
        return (0);
    int i = 0;
    int j = 0;
    char *array;
    int mass;
    mass = ft_strlen(remains) + ft_strlen(buffer);
    array = malloc(sizeof(char) * (mass + 1));
    if (remains)
    {
        while(remains[i])
        {
            array[j] = remains[i];
            i++;
            j++;
        }
        i = 0;
    }
    while(buffer[i])
    {
        array[j] = buffer[i];
        i++;
        j++;
    }
    array[j] = '\0';
    free(remains);
    return (array);
}

char *ft_putline(char *remains)
{
    char *array;
    int i = 0;

    while(remains[i] && remains[i] != '\n')
        i++;
    array = malloc(sizeof(char) * (i + 1));
    i = 0;
    while(remains[i] && remains[i] != '\n')
    {
        array[i] = remains[i];
        i++;
    } 
    array[i] = '\0';
    return (array);
}

char *ft_newremains(char *remains)
{
    char *array;
    int i = 0;
    int j = 0;
    while(remains[i] && remains[i] != '\n')
        i++;
    if (!remains)
    {
        free(remains);
        return (0);
    }
    if(!(array = malloc(sizeof(char) * (ft_strlen(remains) - i + 1))))
        return (0);
    i++;

    while(remains[i])
    {
        array[j] = remains[i];
        j++;
        i++;
    }
    array[j] = '\0';
    free(remains);
    return(array);
}




int get_next_line(int fd, char **line)
{
    static char *remains;
    int sizeofbuffer = 1;
    char *buffer;
    int sizeofread = 1;
    if (!line)
        return (-1);
	buffer = malloc(sizeof(char) * (sizeofbuffer + 1));

    while(buffer[0] != '\n' && sizeofread != 0)
    {
        if((sizeofread = read(fd, buffer, sizeofbuffer)) == (-1))
            return (-1);
        buffer[sizeofread] = '\0';
        remains = ft_strjoin(remains, buffer);
    }
	free(buffer);
  //  printf("%s", remains);
    *line = ft_putline(remains);
    remains = ft_newremains(remains);
    return ((sizeofread == 0) ? 0 : 1);
}
