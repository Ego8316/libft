# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 16:30:27 by vviterbo          #+#    #+#              #
#    Updated: 2024/07/10 17:07:46 by vviterbo         ###   ########.fr        #
                                                                              #
# **************************************************************************** #

CFILES	=	main.c					\
			conversion_utils.c		\
			ft_string_utils.c		\
			ft_char_bool.c			\
			file_parser.c			\
			just_do_it.c			\
			cl_parser.c				\
			ft_string.c				\
			arr_utils.c				\
			ft_math.c				\
			display.c				\
			solver.c				\
			coor.c					\
			map.c
SDIR	=	srcs/
IDIR	=	includes/
SRCS	=	$(addprefix $(SDIR), $(CFILES))
OBJS	=	$(SRCS:.c=.o)

CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	bsq

all		:	$(NAME)

$(NAME)	:	$(SRCS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -I $(IDIR)

debug	:	$(SRCS)
			$(CC) $(CFLAGS) -fsanitize=address $(SRCS) -o $(NAME) -I $(IDIR)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:
			make fclean
			make all

.PHONY	:	all clean fclean re
.SILENT	:	all $(NAME) debug clean fclean re
