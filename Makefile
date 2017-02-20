##
## Makefile for mf in /home/simonn_s//minilibx
##
## Made by styve simonneau
## Login   <simonn_s@epitech.net>
##
## Started on  Thu Oct 25 11:16:18 2012 styve simonneau
## Last update Sun Jun  9 19:02:13 2013 styve simonneau
##

CFLAGS	= -W -Wall -Wextra -I./includes/

LIBNAME	= libmy.a

EXENAME = mysh

SRC	= lib/

SRC_LIB	= $(SRC)my_getnbr.c \
	  $(SRC)my_strcmp.c \
	  $(SRC)my_strcat.c \
	  $(SRC)my_str_to_wordtab.c \
	  $(SRC)get_next_line.c

SRC_EXE	= exec_builtins.c \
	exec_builtins2.c \
	exec_builtins3.c \
	builtins_1.c \
	builtins_2.c \
	replace_with_alias.c \
	get.c \
	init.c \
	main.c \
	usefull.c \
	error.c \
	parser.c \
	file.c \
	free.c \
	cd.c \
	cd2.c \
	add_entries.c \
	get_alias.c \
	history/history.c \
	history/init.c \
	history/fonction_history.c \
	history/my_put_in_list.c \
	history/touche.c \
	history/fonction_util.c \
	history/shift_bit.c \
	history/auto_complet.c \
	history/auto_complet2.c \
	pipe/main.c \
	pipe/redirection.c \
	pipe/redirection2.c \
	pipe/redirection_l.c \
	pipe/redirection_l2.c \
	pipe/operand_cond.c \
	pipe/pipe_end_beg.c \
	pipe/exec.c \
	pipe/closer.c \
	pipe/reinit.c \
	pipe/pars_exe.c \
	pipe/my_error_.c \
	pipe/get_data_2.c

OBJ_LIB	= $(SRC_LIB:.c=.o)

OBJ_EXE	= $(SRC_EXE:.c=.o)

$(EXENAME): $(OBJ_EXE) $(LIBNAME)
	cc $(SRC_EXE) \
	-L./ -lmy \
	-ltermcap \
	-I./includes/ \
	-o $(EXENAME)

$(LIBNAME): $(OBJ_LIB)
	  ar rc $(LIBNAME) $(OBJ_LIB)
	  ranlib $(LIBNAME)

all: $(LIBNAME) $(EXENAME)

clean:
	rm -f $(OBJ_LIB) $(OBJ_EXE)

fclean:
	rm -f $(OBJ_LIB) $(OBJ_EXE) $(LIBNAME) $(EXENAME)

re: fclean all