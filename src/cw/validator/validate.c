#include "corewar.h"

int validate(int fd, char **name, char **exec, char **cmnt)
{
	char    *b4;
	size_t  exec_sz;

	b4 = (char*)malloc(4);
	read(fd, b4, 4);                    //magic
	name = (char*)malloc(PROG_NAME_LENGTH);
	read(fd, *name, PROG_NAME_LENGTH);  //name
	read(fd, b4, 4);                    //NULL
	read(fd, b4, 4);                    //exec size
	exec_sz = (exec_sz = ft_atoi_base(b4, 16)) == 0 ? CHAMP_MAX_SIZE : exec_sz;
	cmnt = (char*)malloc(COMMENT_LENGTH);
	read(fd, *cmnt, COMMENT_LENGTH);    //comment
	read(fd, b4, 4);                    //NULL
	*exec = (char*)malloc(exec_sz);
	read(fd, b4, exec_sz);              //exec
	return (0);
}