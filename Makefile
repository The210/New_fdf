# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/05 17:34:18 by dhorvill          #+#    #+#              #
#    Updated: 2018/06/05 17:34:20 by dhorvill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Werror -Wextra

SRCS = fdf.c draw_line.c rot_interactive.c init_matrix.c\
get_map.c num_len.c draw.c rotation.c get_next_line.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
		make -C libft
			gcc -o $(NAME) $(OBJS) -Iusr/local/inculde -Ilibft libft/libft.a -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit
%.o: %.c
		gcc $(CFLAGS) -c $<
clean:
		make clean -C libft
			rm -f $(OBJS)

fclean: clean
		rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re
