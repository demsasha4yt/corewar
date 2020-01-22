#include "corewar.h"

void     reader(t_cw *cw, int ac, char **av)
{
    int i;

    (void)cw;
    i = 0;
    while (++i < ac)
    {
        if ((fd = open(av[i], O_RDONLY)) == NULL || validate(fd) == 0)
            terminate(1, cw);
        if (ft_strcmp(av[i], "-n") != 0)
        {

        }
//        else
//        {
//
//        }
        fclose(fd);
    }
}