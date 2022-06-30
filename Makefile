# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kannie <kannie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 19:49:47 by kannie            #+#    #+#              #
#    Updated: 2022/06/30 21:48:59 by kannie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

HEADER 		=	libft.h

CC 			=	cc

FLAGS 		=	-Wall -Werror -Wextra

SRCS		=	ft_isalpha.c ft_isprint.c ft_memset.c  ft_bzero.c \
				ft_isascii.c ft_memcpy.c ft_strlcpy.c ft_isalnum.c \
				ft_isdigit.c ft_memmove.c ft_strlen.c ft_toupper.c \
				ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
				ft_memchr.c ft_memcmp.c ft_strnstr.c ft_strlcat.c \
				ft_atoi.c ft_substr.c ft_calloc.c ft_strdup.c \
				ft_strjoin.c ft_strtrim.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_strmapi.c ft_itoa.c ft_split.c

SRCS_B		=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				ft_lstmap.c ft_lstnew.c ft_lstsize.c
				
OBJ 		=	$(SRCS:%.c=%.o)

OBJ_B 		=	$(SRCS_B:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			ar rcs $(NAME) $?

%.o:		%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

bonus:		${OBJ_B}
			@ar rcs ${NAME} ${OBJ_B}

clean:
			@rm -f $(OBJ) $(OBJ_B)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		 all bonus clean fclean re
