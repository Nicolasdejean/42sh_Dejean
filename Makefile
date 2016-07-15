##
## Makefile for makee in /home/dejean_n/PSU_2015_42sh
##
## Made by nicolas dejean
## Login   <dejean_n@epitech.net>
##
## Started on  Tue May 17 18:25:10 2016 nicolas dejean
## Last update Sat Jun  4 05:49:31 2016 girard_z
##

CC	=	gcc

RM	=	rm -rf

NAME	=	42sh

SRCS	=	main_functions/main.c		\
		main_functions/prompt.c		\
		tools/my_putstr.c		\
		tools/my_strcmp.c		\
		tools/my_perror.c		\
		tools/my_strlen.c		\
		tools/my_str_to_tab.c		\
		tools/my_putnbr.c		\
		tools/my_show_list.c		\
		tools/get_next_line.c		\
		tools/get_next_line2.c		\
		tools/delete_space.c		\
		tools/my_strcat.c		\
		tools/free_tab.c		\
		tools/list_to_tab.c		\
		env_management/set_env.c	\
		env_management/unsetenv.c	\
		env_management/list_env.c	\
		env_management/free_env.c	\
		lexeme/init_lexeme.c		\
		lexeme/place_lexer_cmd.c	\
		lexeme/precise_lexer.c		\
		lexeme/free_lexeme_list.c	\
		lexeme/assemble_cmd.c		\
		lexeme/err_op.c			\
		grammar/start_grammar.c		\
		grammar/insert_in_tree.c	\
		grammar/free_tree.c		\
		execution/hub_execution.c	\
		execution/execute_simple_cmd.c	\
		execution/exe_cd.c		\
		execution/exe_cd_two.c		\
		execution/exe_echo.c		\
		execution/exe_execve.c		\
		execution/hub_exec_op.c		\
		execution/exe_simple_op.c	\
		execution/exe_exit.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror
CFLAGS	+=	-g3
CPPFLAGS +=	-I ./include

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
