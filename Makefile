# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 23:44:24 by aanjaimi          #+#    #+#              #
#    Updated: 2022/02/15 14:35:45 by aanjaimi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
INC = so_long.h get_next_line.h
SRCS = main.c \
        check_map.c\
        check_ber.c \
        find_p.c \
        errors.c \
        check.c \
        get_next_line_utils.c \
        get_next_line.c \
		read_map.c \
		render.c \
		window.c
OBJS = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror
all:$(NAME)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^

%.o: %.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all