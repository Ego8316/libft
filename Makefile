# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 18:54:06 by ego               #+#    #+#              #
#    Updated: 2024/10/01 17:30:16 by hcavet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_isalpha.c	\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_strlen.c		\
			ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_strchr.c
OBJS	=	$(SRCS:.c=.o)
IDIR	=	.

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

$(NAME)	:	header	$(OBJS)
			echo "Creating archive..."
			$(AR) $(NAME) $(OBJS)
			echo "Generating index..."
			ranlib $(NAME)
			echo "$(GREEN)[OK] libft is ready!$(RESET)"

.c.o	:
			echo "Compiling $<..."
			$(CC) $(CFLAGS) -I $(IDIR) -c $< -o $(<:.c=.o)

debug	:
			echo "Compiling object files to debug memory issues..."
			$(CC) $(CFLAGS) -fsanitize=address -c $(SRCS) -I .
			echo "Creating archive..."
			$(AR) $(NAME) $(OBJS)
			echo "Generating index..."
			ranlib $(NAME)
			echo "$(VIOLET)[OK] AddressSanitizer is ready !$(RESET)"

test	:	$(NAME)
			echo "Compiling test files..."
			$(CC) $(CFLAGS) $(TMAIN) $(TESTS) -o $(TNAME) -L. -lft -I $(TDIR)
			echo "$(GREEN)[OK] libft tester is ready!$(RESET)"

norm	:
			norminette -R CheckForbiddenSourceHeader $(SRCS) libft.h

clean	:
			echo "Removing object files..."
			$(RM) $(OBJS)
			echo "$(ORANGE)[OK] All object files have been removed.$(RESET)"

fclean	:	clean
			echo "Removing binary files..."
			$(RM) $(NAME) $(TNAME)
			echo "$(ORANGE)[OK] All binary files have been removed.$(RESET)"

re		:	fclean all

.PHONY	:	all clean fclean re
.SILENT	:	all $(NAME) $(OBJS) norm debug clean fclean re header test

RED     = \033[31m
ORANGE  = \033[38;5;214m
YELLOW  = \033[33m
GREEN   = \033[32m
BLUE    = \033[34m
VIOLET  = \033[38;5;93m
ITALIC  = \033[3m
RESET   = \033[0m

header	:
			echo "============================"
			echo "$(RED)  _      _  _       __  _   $(RESET)"
			echo "$(ORANGE) | |    (_)| |__   / _|| |_ $(RESET)"
			echo "$(YELLOW) | |    | || '_ \ | |_ | __|$(RESET)"
			echo "$(GREEN) | |___ | || |_) ||  _|| |_ $(RESET)"
			echo "$(BLUE) |_____||_||_.__/ |_|   \__|$(RESET)"
			echo "$(ITALIC)$(VIOLET)           by Ego           \n$(RESET)"
			echo "============================\n"