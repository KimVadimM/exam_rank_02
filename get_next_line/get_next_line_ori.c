#include "get_next_line.h"

int     ft_strlen(char *str)
{
    int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char    *ft_strjoin(char *remains, char *buffer)
{
    char *array;
    unsigned int size;
    int i;
    int j;

    if (!remains && !buffer)
        return (NULL);
    size = ft_strlen(remains) + ft_strlen(buffer);
    if (!(array = (char *)malloc(sizeof(char) * (size + 2))))
        return (NULL);
    i = 0;
    j = 0;
    if (remains)
    {
        while (remains[i])
        {
            array[j] = remains[i];
            i++;
            j++;
        }
        i = 0;
    }
    while (buffer[i])
    {
        array[j] = buffer[i];
        i++;
        j++;
    }
    array[size] = '\0';
    free((void *)remains);
    return (array);
}

char    *push_line(char *remains)
{
    int i;
    char *array;

    i = 0;
    while (remains[i] && remains[i] != '\n')
        i++;
    if (!(array = (char *)malloc(sizeof(char) * (i + 1))))
        return (NULL);
    i = 0;
    while (remains[i] && remains[i] != '\n')
    {
        array[i] = remains[i];
        i++;
    }
    array[i] = '\0';
    return (array);
}

char    *cut_next_line(char *remains)
{
    int i;
    int j;
    char *array;

    i = 0;
    j = 0;
	
    while (remains[i] && remains[i] != '\n')
        i++;
    if (!remains[i])
    {
        free(remains);
        return (NULL);
    }
//	printf("%d", i);
//	printf("%d", ft_strlen(remains));
    	               
  	if (!(array = (char *)malloc(sizeof(char) * ((ft_strlen(remains) - i) + 1))))
        return (NULL);
   i++;  	
    while (remains[i])
    {
     	array[j] = remains[i];
        i++;
        j++;
    }
    array[j] = '\0';

    free((void *)remains);	
    return (array);
	
}

int get_next_line(int fd, char **line)
{
	static char *remains;

	int buffer_size = 1;	
	char *buffer;
	int sizeofread;
//	int fd = 0;
	
	sizeofread = 1;
	if (!line)
		return (-1);
    buffer = malloc(sizeof(char) * (buffer_size +1));
	while (buffer[0] != '\n' && sizeofread != 0)
	{
		if((sizeofread = read(fd, buffer, buffer_size)) == (-1))
			return (-1);
		buffer[sizeofread] = '\0';
		remains = ft_strjoin(remains, buffer);
	}
	free(buffer);	
	*line = push_line(remains);
	remains = cut_next_line(remains); 
	return ((sizeofread == 0) ? 0 : 1);
}





