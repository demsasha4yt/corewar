RM = rm

# LIBS
D_LIBS = ./libs
D_LIBFT = ${D_LIBS}/libft
L_LIBFT = -L ${D_LIBFT} -lft
I_LIBFT = -I $(D_LIBFT)/includes


# INCLUDES
I_DIR = ./includes
I_I = -I $(I_DIR) 

#COMPILER OPTIONS
CC = gcc
LFLAGS = $(L_LIBFT)
IFLAGS = $(I_I) $(I_LIBFT)
DFLAGS = -g
CFLAGS = $(DFLAGS) $(IFLAGS)
CCFLAGS = $(DFLAGS) $(IFLAGS) $(LFLAGS)

# COREWAR EXECUTABLE
COREWAR_EXEC = corewar
COREWAR_SRCS = $(wildcard ./src/corewar/*.c ./src/corewar/**/*.c)
COREWAR_OBJS = $(patsubst %.c,%.o,$(COREWAR_SRCS))

all: $(COREWAR_EXEC)

$(COREWAR_EXEC): $(COREWAR_OBJS)
	@$(CC) $(CCFLAGS) -o $(COREWAR_EXEC) $(COREWAR_OBJS)
	@echo ...........The $(COREWAR_EXEC) program builded!............

%.o: %.c
	@$(CC) $(CFLAGS) $< -c -o $@
	@echo [OBJS]:    [$@ Builded...]

clean:
	@$(RM) -f $(COREWAR_OBJS)
	@echo [RM]: All .o cleaned!

fclean: clean
	@$(RM) -f $(COREWAR_EXEC)
	@echo [RM]: All executables cleaned!

re: fclean all