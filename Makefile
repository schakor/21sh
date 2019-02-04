# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schakor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 12:48:20 by schakor           #+#    #+#              #
#    Updated: 2019/02/01 18:49:29 by schakor          ###   ########.fr        #
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
				readline/readline.c\
				readline/rl_termcaps.c\
				readline/rl_buffer.c\
				readline/rl_prompt.c\
				readline/rl_moving_ctrl.c\
				readline/rl_moving_esc.c\
				readline/rl_delete_ctrl.c\
				readline/rl_delete_line.c\
				terminal/init_shell.c\
				terminal/init_terminal.c\
				terminal/run_shell.c\
				terminal/singleton_shell.c\
				terminal/display_prompt.c\
				env/addlast_envl.c\
				env/envarr_2_envl.c\
				env/get_env_val.c\
				env/push_env.c\
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
	rm -rf $(OBJ_PATH)

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
