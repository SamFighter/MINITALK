# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 10:51:03 by salabbe           #+#    #+#              #
#    Updated: 2025/03/13 10:17:54 by salabbe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	libft.a

# **************************************************************************** #
#                                 INGREDIENTS                                  #
# **************************************************************************** #

MANDATORY		:=	MANDATORY/ft_atoi.c						\
					MANDATORY/ft_bzero.c					\
					MANDATORY/ft_calloc.c					\
					MANDATORY/ft_isalnum.c					\
					MANDATORY/ft_isalpha.c					\
					MANDATORY/ft_isascii.c					\
					MANDATORY/ft_isdigit.c					\
					MANDATORY/ft_isprint.c					\
					MANDATORY/ft_itoa.c						\
					MANDATORY/ft_memchr.c					\
					MANDATORY/ft_memcmp.c					\
					MANDATORY/ft_memcpy.c					\
					MANDATORY/ft_memmove.c					\
					MANDATORY/ft_memset.c					\
					MANDATORY/ft_putchar_fd.c				\
					MANDATORY/ft_putendl_fd.c				\
					MANDATORY/ft_putnbr_fd.c				\
					MANDATORY/ft_putstr_fd.c				\
					MANDATORY/ft_split.c					\
					MANDATORY/ft_strchr.c					\
					MANDATORY/ft_strdup.c					\
					MANDATORY/ft_striteri.c					\
					MANDATORY/ft_strjoin.c					\
					MANDATORY/ft_strlcat.c					\
					MANDATORY/ft_strlcpy.c					\
					MANDATORY/ft_strlen.c					\
					MANDATORY/ft_strmapi.c					\
					MANDATORY/ft_strncmp.c					\
					MANDATORY/ft_strnstr.c					\
					MANDATORY/ft_strrchr.c					\
					MANDATORY/ft_strtrim.c					\
					MANDATORY/ft_substr.c					\
					MANDATORY/ft_tolower.c					\
					MANDATORY/ft_toupper.c					\

BONUS			:=	BONUS/ft_lstadd_back.c					\
					BONUS/ft_lstadd_front.c					\
					BONUS/ft_lstclear.c						\
					BONUS/ft_lstdelone.c					\
					BONUS/ft_lstiter.c						\
					BONUS/ft_lstlast.c						\
					BONUS/ft_lstmap.c						\
					BONUS/ft_lstnew.c						\
					BONUS/ft_lstsize.c						\

ADD-ONS			:=	SF_DLC/sf_isnewline.c					\
					SF_DLC/ft_isspace.c						\
					SF_DLC/ft_putchar.c						\
					SF_DLC/ft_putstr.c						\
					SF_DLC/ft_putnbr.c						\
					SF_DLC/len_int.c						\
					SF_DLC/ft_strstr.c						\
					SF_DLC/ft_strcmp.c						\

FT_PRINTF		:=	FT_PRINTF/ft_printf.c					\
					FT_PRINTF/ft_sideprintf.c				\

GNL				:=	GET_NEXT_LINE/get_next_line_utils.c		\
					GET_NEXT_LINE/get_next_line.c			\

M_OBJS			:=	$(MANDATORY:%.c=.build/%.o)
B_OBJS			:=	$(BONUS:%.c=.build/%.o)
AO_OBJS			:=	$(ADD-ONS:%.c=.build/%.o)
FTP_OBJS		:=	$(FT_PRINTF:%.c=.build/%.o)
GNL_OBJS		:=	$(GNL:%.c=.build/%.o)
DEPS			:=	$(M_OBJS:%.o=%.d) $(B_OBJS:%.o=%.d) $(AO_OBJS:%.o=%.d) $(FTP_OBJS:%.o=%.d) $(GNL_OBJS:%.o=%.d)

CC				:=	clang
CFLAGS			:=	-Wall -Wextra -Werror -Ofast
CPPFLAGS		:=	-MP -MMD -Iinclude
LDFLAGS			:=

# **************************************************************************** #
#                                    TOOLS                                     #
# **************************************************************************** #

MAKEFLAGS		+= --silent --no-print-directory

# **************************************************************************** #
#                                   RECIPES                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(M_OBJS) $(B_OBJS) $(AO_OBJS) $(FTP_OBJS) $(GNL_OBJS) $(OBJS)
	ar -rc $(NAME) $(M_OBJS) $(B_OBJS) $(AO_OBJS) $(FTP_OBJS) $(GNL_OBJS)
	@printf "%b" "$(BLUE)CREATED $(CYAN)$(NAME)\n"

.build/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@


-include $(DEPS)

clean:
	rm -rf .build

fclean: clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

bonus: $(B_OBJS)
	ar -rc $(NAME) $(B_OBJS)

add-ons: $(AO_OBJS)
	ar -rc $(NAME) $(AO_OBJS)

# **************************************************************************** #
#                                    STYLE                                     #
# **************************************************************************** #

GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
CYAN			:= \033[0;36m
OFF				:= \033[m

header:
	@printf "%b" "$(GREEN)"
	@echo "		 _     _ _      __ _		"
	@echo "		| |   (_) |__  / _| |_		"
	@echo "		| |   | |  _ \| |_| __|		"
	@echo "		| |___| | |_) |  _| |_ 		"
	@echo "		|_____|_|____/|_|  \__|		"
	@echo "		      by Salabbe            "
	@echo
	@printf "%b" "$(CYAN)CC:	$(YELLOW)$(CC)\n"
	@printf "%b" "$(CYAN)CFlags:	$(YELLOW)$(CFLAGS)\n"
	@printf "%b" "$(OFF)"
	@echo

# **************************************************************************** #
#                                   SPECIAL                                    #
# **************************************************************************** #

.PHONY: all clean fclean re
.DELETE_ON_ERROR: