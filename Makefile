# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schakor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 12:48:20 by schakor           #+#    #+#              #
#    Updated: 2018/11/14 16:51:56 by schakor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	21sh

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

CPPFLAGS	=	-I includes

LIB_DIR		=	./libft

LIB_NAME	=	libft.a

LDLIBS		=	$(addprefix $(LIB_DIR)/, $(LIB_NAME)) -ltermcap

SRC_PATH	= ./srcs

OBJ_PATH	= ./objs

SRC_FILES	=	main.c\
				terminal/init_shell.c\
				terminal/init_terminal.c\
				terminal/display_prompt.c\
				env/addlast_envl.c\
				env/envarr_2_envl.c\
				env/get_env_val.c\
				env/push_env.c\
				reader/read_raw_mode.c\
				reader/increase_buffer.c\
				reader/insert_buffer.c\
				reader/termcaps.c\
				history/controler_history.c\
				history/list_history.c\
				history/down_history.c\
				history/up_history.c\
				signal/ft_signal.c\
				cleaner/free_term.c\
				cleaner/fatal_exit.c

OBJ_FILES	=	$(SRC_FILES:.c=.o)

SRCS		=	$(addprefix $(SRC_PATH)/, $(SRC_FILES))

OBJS		=	$(addprefix $(OBJ_PATH)/, $(OBJ_FILES))

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $^ $(LDFLAGS) $(LDLIBS) -o $@

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH) :
	mkdir -p $@
	mkdir -p $(dir $(OBJS))
clean :
	make -C libft clean
	rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
