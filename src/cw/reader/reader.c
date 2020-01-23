#include "corewar.h"

void parse_to_cw(int fd, t_ply **ply)
{
	char *name;
	char *exec;
	char *cmnt;

	if (validate(fd, &name, &exec, &cmnt) == 0)
	{
		// free strings
		terminate(1, cw);
	}
	cw->ply = (t_ply*)malloc(sizeof(t_ply));
	cw->ply->id = cw->count_players;
	cw->ply->name = name;
	cw->ply->comment = cmnt;
	cw->ply->ply_code = exec;
	cw->ply->file_path =
}

void     reader(t_cw *cw, int ac, char **av)
{
    int i;

    (void)cw;
    i = 0;
    id = 0;
    while (++i < ac)
    {
    	if (ft_strcmp(av[i], "-dump") == 0)
		    cw->count_cycles = ft_atoi(av[(++i)++]);
	    if (i < ac && ft_strcmp(av[i], "-n") == 0)
		    id = ft_atoi(av[(++i)++]);
	    if (i < ac && (fd = open(av[i], O_RDONLY)) <= 0)
            terminate(1, cw);
	    if (i >= ac)
		    break;
	    cw->count_players++;
	    parse_to_ply(fd, cw);
	    cw->ply->file_path = av[i];
	    close(fd);
    }
}