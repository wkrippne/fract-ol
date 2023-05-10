# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 09:48:39 by wkrippne          #+#    #+#              #
#    Updated: 2022/12/23 09:48:39 by wkrippne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

AR = ar

NAME = libft.a

ARFLAGS = rc

CFLAGS = -Wall -Werror -Wextra

SRCFILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
    ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
    ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
    ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
    ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
    ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
    ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
    ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
    ft_putendl_fd.c ft_putnbr_fd.c ft_isspace.c ft_ishexdigit.c

BSFILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
    ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
    ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJFILES = ${SRCFILES:.c=.o}

BFTS = $(BSFILES:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJFILES)
	$(AR) $(ARFLAGS) $(NAME) $(OBJFILES)

all : $(NAME)

bonus : $(OBJFILES) $(BFTS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJFILES) $(BFTS)
    
fclean : clean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJFILES) $(BFTS)

re : fclean $(NAME)

.PHONY: all bonus clean fclean re