# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 15:03:39 by acaetano          #+#    #+#              #
#    Updated: 2024/02/08 19:50:29 by albokanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
NAME 		= libft.a
HEADER		= libft.h
RUN			= run

SRCS 		=	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	   			ft_isdigit.c ft_isprint.c ft_memcpy.c \
	   			ft_memmove.c ft_memset.c \
	   			ft_strlcpy.c ft_strlen.c \
				ft_strlcat.c ft_toupper.c ft_tolower.c \
				ft_strchr.c ft_strrchr.c ft_strncmp.c \
				ft_memchr.c ft_memcmp.c ft_strstr.c ft_atoi.c \
				ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
				ft_strmapi.c ft_striteri.c ft_strtrim.c \
				ft_split.c ft_itoa.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				get_next_line.c ft_atoi_base.c utils_split.c

OBJS 		=	$(SRCS:.c=.o)

BONUS		= 	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c  ft_lstiter_bonus.c ft_lstmap_bonus.c
					   			
BONUS_OBJS  =	$(BONUS:.c=.o)

all: $(NAME)

%.o	: %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $^

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

#so :
#	$(CC) -fPIC $(CFLAGS) $(SRC) -shared -o libft.so $(OBJS) $(BONUS_OBJS) 

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME)

re:	fclean all

bonus : $(OBJS) $(BONUS_OBJS)
	ar rc $(NAME) $(BONUS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus run so

run: $(OBJS) $(BONUS_OBJS)
	clear && $(CC) $(CFLAGS) -I $(HEADER) main.c $^ -o $(RUN)

ffclean: fclean
	rm -rf $(RUN)
