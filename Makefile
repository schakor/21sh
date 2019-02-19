# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schakor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 12:48:20 by schakor           #+#    #+#              #
#    Updated: 2019/02/19 13:49:29 by schakor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	21sh

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g3  -fsanitize=address

CPPFLAGS	=	-I includes

LIB_DIR		=	./libft

LIB_NAME	=	libft.a

LDLIBS		=	$(addprefix $(LIB_DIR)/, $(LIB_NAME)) -ltermcap

SRC_PATH	= ./srcs

OBJ_PATH	= ./objs

SRC_FILES	=	main.c\
				readline/readline.c\
				readline/rl_termcaps.c\
				readline/rl_buffer.c\
				readline/rl_prompt.c\
				readline/rl_moving_ctrl.c\
				readline/rl_moving_esc.c\
				readline/rl_delete_ctrl.c\
				readline/rl_delete_line.c\
				terminal/terminal.c\
				terminal/shell.c\
				env/addlast_envl.c\
				env/init_shell_envl.c\
				env/get_env_val.c\
				env/push_env.c\
				signal/ft_signal.c\
				cleaner/free_term.c\
				cleaner/fatal_exit.c\
				history/controler_history.c\
				history/down_history.c\
				history/file_history.c\
				history/history_cmd.c\
				history/list_history.c\
				history/up_history.c\
				history/history.c\
				history/init_shell_history.c\
				lexer/lexer.c\

OBJ_FILES	=	$(SRC_FILES:.c=.o)

SRCS		=	$(addprefix $(SRC_PATH)/, $(SRC_FILES))

OBJS		=	$(addprefix $(OBJ_PATH)/, $(OBJ_FILES))

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $^ $(CFLAGS) $(LDLIBS) -o $@

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH) :
	mkdir -p $@
	mkdir -p $(dir $(OBJS))

clean :
	make -C libft clean
	rm -rf $(OBJ_PATH)

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
