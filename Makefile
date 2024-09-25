# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ego <ego@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 18:54:06 by ego               #+#    #+#              #
#    Updated: 2024/09/25 20:07:06 by ego              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c
OBJS	=	$(SRCS:.c=.o)

TDIR	=	tests/
TMAIN	=	tests/test_libft.c
TESTS	=	$(addprefix $(TDIR)test_, $(SRCS))

CC		=	cc
RM		=	rm -f
AR		=	ar rcs
CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libft.a
TNAME	=	test_libft

all		:	$(NAME)

$(NAME)	:
			echo "Compiling object files..."
			$(CC) $(CFLAGS) -c $(SRCS) -I .
			echo "Creating archive..."
			$(AR) $(NAME) $(OBJS)
			echo "Generating index..."
			ranlib $(NAME)
			echo "[OK] libft is ready !"

debug	:
			echo "Compiling object files to debug memory issues..."
			$(CC) $(CFLAGS) -fsanitize=address -c $(SRCS) -I .
			echo "Creating archive..."
			$(AR) $(NAME) $(OBJS)
			echo "Generating index..."
			ranlib $(NAME)
			echo "[OK] AddressSanitizer is ready !"

test	:	$(NAME)
			$(CC) $(CFLAGS) $(TMAIN) $(TESTS) -o $(TNAME) -L. -lft -I $(TDIR)

norm	:
			norminette -R CheckForbiddenSourceHeader $(SRCS) libft.h

clean	:
			echo "Removing object files..."
			$(RM) $(OBJS)
			echo "[OK] All object files have been removed."

fclean	:	clean
			echo "Removing binary files..."
			$(RM) $(NAME) $(TNAME)
			echo "[OK] All binary files have been removed."

re		:	fclean all

.PHONY	:	all clean fclean re
.SILENT	:	all $(NAME) $(OBJS) norm debug clean fclean re
