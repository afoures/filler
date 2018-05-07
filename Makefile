# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afoures <afoures@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/21 22:41:09 by marvin            #+#    #+#              #
#    Updated: 2018/05/04 15:39:48 by afoures          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME			=	players/afoures.filler
VISU			=	visu

CC				=	clang
CFLAGS			=	-Werror -Wall -Wextra -Ofast
CPPFLAGS		=	-I includes
VISU_CPPFLAGS	=	-I ~/.brew/include/SDL2

LDFLAGS			=	-Llibft
LDLIB			=	-lft

VISU_LDFLAGS	=	-L ~/.brew/lib/
VISU_LDLIBS		=	-lsdl2 -lsdl2_mixer -lsdl2_ttf

SRC_PATH		=	srcs/algo
SRC_NAME		=	main.c\
					get_map.c\
					get_piece.c\
					get_player.c\
					get_score.c\
					get_first_pos.c\
					recursive.c\
					update_map.c\
					algo.c

VISU_SRC_PATH	=	srcs/visu
VISU_SRC_NAME	=	main.c\
					start.c\
					colors.c\
					draw_turn.c\
					get_turn.c\
					get_event.c\
					get_vm_info.c\
					help.c\
					init.c\
					quit.c\
					draw_piece.c\
					put_winner.c\
					sdl_utils.c

OBJ_PATH		=	obj/algo
VISU_OBJ_PATH	=	obj/visu
OBJ_NAME		=	$(SRC_NAME:.c=.o)
VISU_OBJ_NAME	=	$(VISU_SRC_NAME:.c=.o)

SRC				=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ				=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
VISU_SRC		=	$(addprefix $(VISU_SRC_PATH)/,$(VISU_SRC_NAME))
VISU_OBJ		=	$(addprefix $(VISU_OBJ_PATH)/,$(VISU_OBJ_NAME))

LIB_PATH		=	libft
LIB				=	$(LIB_PATH)/libft.a

all: 
	@make lib
	@make $(NAME)
	@make $(VISU)

lib:
	@make -C $(LIB_PATH)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(LDFLAGS) $(LDLIB) $^ -o $@

$(VISU): $(VISU_OBJ) $(LIB)
	$(CC) $(LDFLAGS) $(LDLIB) $(VISU_LDFLAGS) $(VISU_LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c includes/filler.h
	@mkdir -p obj
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(VISU_OBJ_PATH)/%.o: $(VISU_SRC_PATH)/%.c includes/visu.h
	@mkdir -p obj
	@mkdir -p $(VISU_OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(VISU_CPPFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rm -f $(VISU_OBJ)
	@make clean -C $(LIB_PATH)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean:
	@make fclean -C $(LIB_PATH)
	@make clean
	@rm -f $(NAME)
	@rm -f $(VISU)

re: 
	@make fclean
	@make all
