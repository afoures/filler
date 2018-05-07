# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afoures <afoures@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 15:32:53 by afoures           #+#    #+#              #
#    Updated: 2018/04/03 13:09:00 by afoures          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME		=	libft.a

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g -Ofast

INCLUDES	=	includes/

FT_PRINTF	=	ft_printf.c\
				ft_dprintf.c\
				ft_sprintf.c\
				parser.c\
				buf.c\
				put.c\
				put1.c\
				utils.c\
				utils1.c\
				utils2.c\
				utils3.c\
				utils4.c\
				init_table.c\
				arg.c\
				arg1.c\
				arg2.c\
				arg3.c\
				arg4.c\
				h_flags.c\
				h_flags1.c\
				h_modifier.c\
				h_color.c\
				h_no_behavior.c\
				h_d.c\
				h_u.c\
				h_x.c\
				h_o.c\
				h_b.c\
				h_n.c\
				h_p.c\
				h_c.c\
				h_s.c\
				h_r.c\
				h_m.c\
				h_k.c\
				h_w.c\
				h_float.c\
				h_float1.c\
				h_float2.c\
				h_f.c\
				h_e.c\
				h_g.c\
				h_a.c

FT_PF_PATH	=	ft_printf/
FT_PF_SRCS	=	$(addprefix $(FT_PF_PATH), $(FT_PRINTF))

GNL			=	get_next_line.c

GNL_PATH	=	gnl/
GNL_SRCS	=	$(addprefix $(GNL_PATH), $(GNL))

MEM			=	ft_memalloc.c \
				ft_memalcpy.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c

MEM_PATH	=	mem/
MEM_SRCS	=	$(addprefix $(MEM_PATH), $(MEM))

LST			=	ft_lstadd.c \
				ft_lstaddlast.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstnew.c

LST_PATH	=	lst/
LST_SRCS	=	$(addprefix $(LST_PATH), $(LST))

PUT			=	ft_putchar.c \
				ft_putchar_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_puterror.c \
				ft_putitab.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putstab.c \
				ft_putstr.c \
				ft_putstr_fd.c

PUT_PATH	=	put/
PUT_SRCS	=	$(addprefix $(PUT_PATH), $(PUT))

STR 		=	ft_strcat.c \
				ft_strchr.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_strequ.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strjoinfree.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnequ.c \
				ft_strnew.c \
				ft_strnstr.c \
				ft_strrev.c \
				ft_strrchr.c \
				ft_strsplit.c \
				ft_strsplitfree.c \
				ft_strstr.c \
				ft_strsub.c \
				ft_strtrim.c

STR_PATH	=	str/
STR_SRCS	=	$(addprefix $(STR_PATH), $(STR))

CHAR		=	ft_abs.c \
				ft_atoi.c \
				ft_bzero.c \
				ft_countword.c \
				ft_intlen.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isspace.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_sortint.c \
				ft_swap.c \
				ft_tablen.c \
				ft_tolower.c \
				ft_toupper.c

CHAR_PATH	=	char/
CHAR_SRCS	=	$(addprefix $(CHAR_PATH), $(CHAR))

OBJ 		= $(FT_PF_SRCS:.c=.o) $(GNL_SRCS:.c=.o) $(LST_SRCS:.c=.o) $(MEM_SRCS:.c=.o) $(PUT_SRCS:.c=.o) $(STR_SRCS:.c=.o) $(CHAR_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

%.o:	%.c $(INCLUDES)*.h Makefile
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDES)

clean:
	@rm -f $(OBJ)

fclean: 
	@make clean
	@rm -f $(NAME)

re : 
	@make fclean
	@make all
