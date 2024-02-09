# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 15:06:01 by albokanc          #+#    #+#              #
#    Updated: 2024/01/06 15:58:07 by albokanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
NAME 		= libftprintf.a
HEADER		= ft_printf.h
RUN			= run

SRCS 		= ft_printf.c ft_putchar.c ft_putstr.c ft_strnlen.c \
			ft_putnbr.c ft_putnbr_unsgnd.c ft_find_adress.c \
			ft_hex.c ft_putnbr_base.c

OBJS 		=	$(SRCS:.c=.o)

all: $(NAME)

%.o	: %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $^

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:			all clean fclean re run 

run: $(OBJS) 
	clear && $(CC) $(CFLAGS) -I $(HEADER) main.c $^ -o $(RUN)

ffclean: fclean
	rm -rf $(RUN)
