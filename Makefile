# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 13:08:36 by benjamin          #+#    #+#              #
#    Updated: 2017/02/23 20:31:46 by benjamin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB_PATH = ./libft
PRINTF_PATH = ./src
OBJ_PATH = ./obj

LIB_SRCS = ft_atoi.c       ft_lstadd.c     ft_memcpy.c     ft_putstr_fd.c  ft_strjoin.c    ft_strrchr.c \
ft_bzero.c      ft_lstdel.c     ft_memdel.c     ft_strcat.c     ft_strlcat.c    ft_strsplit.c \
ft_intlen.c     ft_lstdelone.c  ft_memmove.c    ft_strchr.c     ft_strlen.c     ft_strstr.c \
ft_isalnum.c    ft_lstiter.c    ft_memset.c     ft_strclr.c     ft_strmap.c     ft_strsub.c \
ft_isalpha.c    ft_lstlen.c     ft_putchar.c    ft_strcmp.c     ft_strmapi.c    ft_strtrim.c \
ft_isascii.c    ft_lstmap.c     ft_putchar_fd.c ft_strcpy.c     ft_strncat.c    ft_tolower.c \
ft_isblank.c    ft_lstnew.c     ft_putendl.c    ft_strdel.c     ft_strncmp.c    ft_toupper.c \
ft_isdigit.c    ft_memalloc.c   ft_putendl_fd.c ft_strdup.c     ft_strncpy.c    ft_wordcount.c \
ft_isprint.c    ft_memccpy.c    ft_putnbr.c     ft_strequ.c     ft_strnequ.c    ft_wordlen.c \
ft_isxdigit.c   ft_memchr.c     ft_putnbr_fd.c  ft_striter.c    ft_strnew.c     ft_itoa.c \
ft_memcmp.c     ft_putstr.c     ft_striteri.c   ft_strnstr.c    get_next_line.c ft_revstr.c \
ft_strappend.c  ft_itoa_long.c  ft_longlen.c    ft_itoa_ulong.c ulong_len.c

PRINTF_SRCS = ft_printf.c    pf_init.c    pf_arg.c    pf_check.c

LIB_PREF = $(addprefix $(LIB_PATH)/, $(LIB_SRCS))
LIB_OBJN = $(LIB_SRCS:.c=.o)
PRINTF_PREF = $(addprefix $(PRINTF_PATH)/, $(PRINTF_SRCS))
PRINTF_OBJN = $(PRINTF_SRCS:.c=.o)

LIB_OBJ = $(addprefix $(OBJ_PATH)/, $(LIB_OBJN))
PRINTF_OBJ = $(addprefix $(OBJ_PATH)/, $(PRINTF_OBJN))
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIB_OBJ) $(PRINTF_OBJ)
	@ar rc $(NAME) $^
	@echo "ft_printf : \033[1;36mCompile !\033[0m"

$(OBJ_PATH)/%.o: $(PRINTF_PATH)/%.c
	gcc $(FLAGS) -c $< -o $@
	@echo "ft_printf : \033[1;36mCompilation of C files succesful\033[0m"

$(OBJ_PATH)/%.o: $(LIB_PATH)/%.c
	@gcc $(FLAGS) -c $< -o $@
	@echo "Libft : \033[1;36mCompilation of C files succesful\033[0m"

clean:
	@rm -f $(PRINTF_OBJ) $(LIB_OBJ)
	@echo "ft_printf : \033[1;36mObject deleted\033[0m"

fclean: clean
	@rm -f $(NAME)

fclean_only:
	@rm -f $(NAME)
	@echo "ft_printf : \033[1;36mFolder cleanup successful\033[0m"

re: fclean all
