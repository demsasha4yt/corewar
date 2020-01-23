#include "corewar.h"
#include <fcntl.h>

int     reader(t_cw *cw, int ac, char **av)
{
    int     i;
    int     fd;
	int     id;
	char    *name;
	char    *exec;
	char    *cmnt;
	t_ply   *plyr;
	t_ply   *tmp;
	t_ply   *prev;

    (void)cw;
    i = 0;
    id = 0;
    while (++i < ac)
    {
    	if (ft_strcmp(av[i], "-dump") == 0)
		{
			cw->count_cycles = ft_atoi(av[(++i)]);
			i++;
		}
		    
	    id = ++cw->count_players;
	    if (i >= ac)
		    return (1);
	    if (i < ac && ft_strcmp(av[i], "-n") == 0)
		{
			id = ft_atoi(av[(++i)]);
			i++;
		}
		    
	    if (i < ac && (fd = open(av[i], O_RDONLY)) <= 0)
            terminate(1, cw);
	    if (i >= ac)
		    return (2);
	    if (validate(fd, &name, &exec, &cmnt) == 1)
	    {
		    // free strings
		    terminate(1, cw);
	    }
	    plyr = (t_ply*)malloc(sizeof(t_ply));
	    plyr->id = id;
	    plyr->name = ft_strdup(name);
		ft_printf("%p\n", cmnt);
	    plyr->comment = ft_strdup(cmnt);
	    plyr->ply_code = ft_strdup(exec);
	    plyr->file_path = ft_strdup(av[i]);
	    tmp = cw->players;
	    prev = NULL;
	    while (tmp != NULL || tmp->id > plyr->id)
	    {
	    	prev = tmp;
	    	tmp = tmp->next;
	    }
	    plyr->prev = prev;
	    plyr->next = tmp;
	    close(fd);
    }
    return (0);
}
