NAME			=	fdf

SRC			=	src/fdf.c src/hooks.c src/parse_map.c src/utils.c src/draw_line.c src/offset_axis.c src/errors.c

OBJS			=	${SRC:.c=.o}

LD_FLAGS		=	-L mlx -L libs/printf -L libs/libft

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-Ifdf.h

CC				=	cc

LIBS 			= libs/printf/libftprintf.a libs/libft/libft.a

CFLAGS			= -Wall -Wextra -Werror -g3

all				:	${NAME}

%.o: %.c fdf.h
	@${CC} ${CFLAGS} ${HEAD} -c $< -o $@ >/dev/null 2>&1

$(NAME)			:	${OBJS}
	@make -C mlx >/dev/null 2>&1
	@make -C libs/libft >/dev/null 2>&1
	@make -C libs/printf >/dev/null 2>&1
	@${CC} ${CFLAGS} -g3 ${LD_FLAGS} ${OBJS} -o ${NAME} ${LIBS} ${MLX_FLAGS} >/dev/null 2>&1
	@echo "\nFDF is created"


clean			:
	@make clean -C mlx >/dev/null 2>&1
	@make clean -C libs/libft >/dev/null 2>&1
	@make clean -C libs/printf >/dev/null 2>&1
	@rm -rf ${OBJS}

fclean			:	clean
	@make fclean -C libs/libft >/dev/null 2>&1
	@make fclean -C libs/printf >/dev/null 2>&1
	@rm -rf ${NAME}

re				:	fclean all
	./fdf &

.PHONY			:	all clean fclean re
