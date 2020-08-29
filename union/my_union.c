#include <unistd.h>
//7.15
int main (int argc, char **argv)
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
        while (argv[1][y])
        {
            if (mass[argv[1][y]] == 0)
                {
                    mass[argv[1][y]] = 1;
                    write(1, &argv[1][y], 1);
                }
            y++;
        }
        y = 0;
        while (argv[2][y])
        {
            if(mass[argv[2][y]] == 0)
            {
                mass[argv[2][y]] = 1;
                write(1, &argv[2][y], 1);
            }
            y++;
        }
    }
    write(1, "\n", 1);
    return (0);
}