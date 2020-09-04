#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
// 1 fail - 1.16
// 2 semifail - 1.01
// 3 not full success - 25 min;

#include "get_next_line.h"

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
		return (NULL);
	int i = 0;
	int j = 0;
	char *array;
	unsigned mass;
	mass = ft_strlen(remains) + ft_strlen(buffer);
	if(!(array = (char *)malloc(sizeof(char) * (mass + 1))))
		return (0);
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
	free((void *)remains);
	return (array);
}

char *put_line(char *remains)
{
	int i = 0;
	char *array; 
	while(remains[i] && remains[i] != '\n')
		i++;
	if(!(array = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	while(remains[i] && remains[i] != '\n')
	{
		array[i] = remains[i];
		i++;
	}
	return (array);
}

char *new_line(char *remains)
{
	int i = 0;
	int j = 0;
	char *array;
	while(remains[i] && remains[i] != '\0')
		i++;
	if(!remains[i])
	{
		free(remains);
		return (NULL);
	}
	if(!(array = (char *)malloc(sizeof(char) * (ft_strlen(remains) - i + 1))))
		return (NULL);
	i++;
	while(remains[i])
	{
		array[j] = remains[i];
		i++;
		j++;
	}
	array[j] = '\0';
	free(remains);
	return(array);
}


int get_next_line(int fd, char **line)
{
	static char *remains;
	int buffer_size = 1;
	char buffer[buffer_size +1];
	int count = 1;
	while (buffer[0] != '\n' && count != 0)
	{
		if((count = read(fd, buffer, buffer_size)) == (-1))
			return (-1);
		buffer[count] = '\0';
		remains = ft_strjoin(remains, buffer);
	}
	*line = put_line(remains);
	remains = new_line(remains);
	return((count == 0) ? 0 : 1);
}
