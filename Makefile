# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 18:09:35 by ybourais          #+#    #+#              #
#    Updated: 2023/02/18 22:34:58 by ybourais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c get_next_line.c get_next_line_utils.c cheak_map.c so_long_utils.c graphics.c utils2.c utils3.c utils4.c\

CC = cc

CFLAGS = -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
