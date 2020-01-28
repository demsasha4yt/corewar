#include "corewar.h"

static int  null_check(char *b4)
{
	return (*b4 == 0 && *(b4 + 1) == 0 && *(b4 + 2) == 0 && *(b4 + 3) == 0 ? 0 : 1);
}

int         validate(int fd, char **name, char **exec, char **cmnt)
{
    char    *b4;
    size_t  exec_sz;

    if ((b4 = (char*)malloc(4 + 1)) == NULL)
    	return (1);
    b4[4] = 0;
	if (read(fd, b4, 4) != 4)
		return (1);
    if ((*name = (char*)malloc(PROG_NAME_LENGTH + 1)) == NULL)
    	return (1);
    (*name)[PROG_NAME_LENGTH] = 0;
	if (read(fd, *name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		return (1);
	if (read(fd, b4, 4) != 4)
		return (1);
	if (null_check(b4))
		return (1);
	if (read(fd, b4, 4) != 4)
		return (1);
    ft_printf("%d", ft_atoi_base(b4, 16));
    exec_sz = 0;
    exec_sz = (exec_sz = ft_atoi_base(b4, 16)) == 0 ? CHAMP_MAX_SIZE : exec_sz;
    if ((*cmnt = (char*)malloc(COMMENT_LENGTH + 1)) == NULL)
    	return (1);
    (*cmnt)[COMMENT_LENGTH] = 0;
    if (read(fd, *cmnt, COMMENT_LENGTH) != COMMENT_LENGTH)
        return (1);
    if (read(fd, b4, 4) != 4)
	    return (1);
    if (null_check(b4))
    	return (1);
    if ((*exec = (char*)malloc(exec_sz + 1)) == NULL)
    (*exec)[exec_sz] = 0;
    if (read(fd, *exec, exec_sz) != exec_sz)
    	return (1);
    return (0);
}