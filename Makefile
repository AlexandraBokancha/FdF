NAME			=	fdf

SRCS			=	main.c color_manager.c

OBJS			=	${SRCS:.c=.o}

LD_FLAGS		=	-L mlx

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-I mlx

CC				=	cc

CFLAGS			= -g3

.c.o			:
	${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS}
	make -C mlx
	${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} ${MLX_FLAGS}

all				:	${NAME}

val				:	${NAME}
	valgrind \
		--leak-check=full --tool=memcheck \
		--show-reachable=yes \
		--track-fds=yes \
		--errors-for-leak-kinds=all \
		--show-leak-kinds=all ./${NAME} "maps/map10x10.ber"

clean			:
	make clean -C mlx
	@rm -rf ${OBJS}

fclean			:	clean
	@rm -rf ${NAME}

re				:	fclean all
	./fdf &

.PHONY			:	all clean fclean re
