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
LFLAGS = $(L_LIBFT) -lncurses
IFLAGS = $(I_I) $(I_LIBFT)
DFLAGS = -g
EFLAGS = -Wall -Wextra -Werror
CFLAGS = $(DFLAGS) $(IFLAGS) $(EFLAGS)
CCFLAGS = $(DFLAGS) $(IFLAGS) $(LFLAGS) $(EFLAGS)

# COREWAR EXECUTABLE
COREWAR_EXEC = corewar
COREWAR_SRCS = $(wildcard ./src/cw/*.c ./src/cw/**/*.c)
COREWAR_OBJS = $(patsubst %.c,%.o,$(COREWAR_SRCS))

# ASM EXECUTABLE

ASM_EXEC = asm
ASM_SRCS = $(wildcard ./src/_asm/*.c ./src/_asm/**/*.c)
ASM_OBJS = $(patsubst %.c,%.o,$(ASM_SRCS))

all: $(COREWAR_EXEC) $(ASM_EXEC)

$(COREWAR_EXEC): $(COREWAR_OBJS)
	@$(CC) $(CCFLAGS) -o $(COREWAR_EXEC) $(COREWAR_OBJS)
	@echo ...........The $(COREWAR_EXEC) program builded!............

$(ASM_EXEC): $(ASM_OBJS)
	@$(CC) $(CCFLAGS) -o $(ASM_EXEC) $(ASM_OBJS)
	@echo ...........The $(ASM_EXEC) program builded!............

%.o: %.c
	@$(CC) $(CFLAGS) $< -c -o $@
	@echo [OBJS]:    [$@ Builded...]

clean:
	@$(RM) -f $(COREWAR_OBJS)
	@$(RM) -f $(ASM_OBJS)
	@echo [RM]: All .o cleaned!

fclean: clean
	@$(RM) -f $(COREWAR_EXEC)
	@$(RM) -f $(ASM_EXEC)
	@echo [RM]: All executables cleaned!

re: fclean all