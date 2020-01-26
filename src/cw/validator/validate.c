#include "corewar.h"

int validate(int fd, char **name, char **exec, char **cmnt)
{
    char    *b4;
    size_t  exec_sz;

    b4 = (char*)malloc(4 + 1);
    b4[4] = 0;
    ft_printf("%d\n", read(fd, b4, 4));                    //magic
    *name = (char*)malloc(PROG_NAME_LENGTH + 1);
    (*name)[PROG_NAME_LENGTH] = 0;
    ft_printf("%d\n", read(fd, *name, PROG_NAME_LENGTH));  //name
    ft_printf("%d\n", read(fd, b4, 4));                    //NULL
    ft_printf("%d\n", read(fd, b4, 4));                    //exec size
    ft_printf("%d", ft_atoi_base(b4, 16));
    exec_sz = 0;
    exec_sz = (exec_sz = ft_atoi_base(b4, 16)) == 0 ? CHAMP_MAX_SIZE : exec_sz;
    *cmnt = (char*)malloc(COMMENT_LENGTH + 1);
    (*cmnt)[COMMENT_LENGTH] = 0;
    read(fd, *cmnt, COMMENT_LENGTH);    //comment
    read(fd, b4, 4);                    //NULL
    *exec = (char*)malloc(exec_sz + 1);
    (*exec)[exec_sz] = 0;
    read(fd, *exec, exec_sz);              //exec
    return (0);
}