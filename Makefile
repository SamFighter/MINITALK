# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/09 14:45:29 by salabbe           #+#    #+#              #
#    Updated: 2025/04/17 17:57:00 by salabbe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

N_NAME		= client

B_NAME		= client_bonus

SERVER		= server

B_SERVER	= server_bonus

# **************************************************************************** #
#								    										   #
#				=======>		INGREDIENTS			<=======		   		   #
#																			   #
# **************************************************************************** #

LIBFT 		= ./libft/libft.a

MANDA_C		= 	srcs/client/client.c								\

MANDA_S 	=	srcs/server/server.c								\

BONUS_C		= 	srcs/client/client_bonus.c							\

BONUS_S		=	srcs/server/server_bonus.c							\

N_OBJS		=	$(MANDA_C:%.c=.build/%.o)
S_OBJS		=	$(MANDA_S:%.c=.build/%.o)

B_C_OBJS	=	$(BONUS_C:%.c=.build/%.o)
B_S_OBJS	=	$(BONUS_S:%.c=.build/%.o)

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g
CPPFLAGS	=	-MP	-MMD -Iinclude									\
				-Iincludes/minitalk.h								\
				-Iincludes/minitalk_bonus.h
				
LDFLAGS		=	-Llibft -lft

# **************************************************************************** #
#								    										   #
#			    	=======>		TOOLS			<=======		   		   #
#																			   #
# **************************************************************************** #

MAKEFLAGS	+=	--silent --no-print-directory

# **************************************************************************** #
#								    										   #
#			    	=======>		RECIPES			<=======		   		   #
#																			   #
# **************************************************************************** #

all:	header	$(N_NAME)	$(SERVER)

$(N_NAME): $(LIBFT) $(N_OBJS)
		$(CC) $(CFLAGS) $(N_OBJS) $(LDFLAGS) -o $(N_NAME)
		@printf "$(PURPLE)CREATED$(OFF) $(CYAN)$(_BOLD)OBJS$(_RESET) $(CYAN)in /MINITALK/.build$(OFF)\n"
		@printf "$(PURPLE)CREATED$(OFF) $(CYAN)$(N_NAME)$(OFF)\n"

$(SERVER): $(LIBFT) $(S_OBJS)
		$(CC) $(CFLAGS) $(S_OBJS) $(LDFLAGS) -o $(SERVER)
		@printf "$(PURPLE)CREATED$(OFF) $(CYAN)$(_BOLD)OBJS$(_RESET) $(CYAN)in /MINITALK/.build$(OFF)\n"
		@printf "$(PURPLE)CREATED$(OFF) $(CYAN)$(SERVER)$(OFF)\n"

$(LIBFT):
		$(MAKE) -C libft
		
bonus:	header	$(B_NAME) $(B_SERVER)

$(B_NAME): $(B_C_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(B_C_OBJS) $(LDFLAGS) -o $(B_NAME)
	@printf "$(PURPLE)CREATED$(OFF) $(CYAN)$(_BOLD)OBJS$(_RESET) $(CYAN)in /MINITALK/.build$(OFF)\n"
	@printf "$(PURPLE)CREATED$(OFF) $(CYAN)ADDED $(B_NAME)$(OFF)\n"

$(B_SERVER): $(B_S_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(B_S_OBJS) $(LDFLAGS) -o $(B_SERVER)
	@printf "$(PURPLE)CREATED$(OFF) $(CYAN)$(_BOLD)OBJS$(_RESET) $(CYAN)in /MINITALK/.build$(OFF)\n"
	@printf "$(PURPLE)CREATED$(OFF) $(CYAN)ADDED $(B_SERVER)$(OFF)\n"

.build/%.o: %.c
		mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@

clean:
		$(MAKE) -C libft clean
		@printf "$(PURPLE)$(_BOLD)SUPPRESSION$(OFF)$(_RESET) $(CYAN)/MINITALK/.build$(OFF)\n"
		rm -rf .build

fclean: clean
		$(MAKE) -C libft fclean
		@printf "$(PURPLE)$(_BOLD)ERRADICATION$(OFF)$(_RESET) $(CYAN)$(N_NAME)$(OFF)\n"
		@printf "$(PURPLE)$(_BOLD)ERRADICATION$(OFF)$(_RESET) $(CYAN)$(SERVER)$(OFF)\n"
		@printf "$(PURPLE)$(_BOLD)LOOKED FOR ANNIHILATION OF$(OFF)$(_RESET) $(CYAN)$(B_NAME) AND $(B_SERVER)$(OFF)\n"
		rm -rf $(N_NAME)
		rm -rf $(SERVER)
		rm -rf $(B_NAME)
		rm -rf $(B_SERVER)

re:
		@printf "$(RED)$(_BOLD)RE-STARTED FROM SCRATCH$(OFF)$(_RESET)\n"
		$(MAKE) fclean
		$(MAKE) all

# **************************************************************************** #
#								    										   #
#			    	=======>		PIMPER			<=======		   		   #
#																			   #
# **************************************************************************** #


OFF			:= \033[0m
RED			:= \033[0;31m
GREEN		:= \033[0;32m
YELLOW		:= \033[0;33m
CYAN		:= \033[0;36m
PURPLE		:= \033[0;35m
TPUT = tput -T xterm-256color
_RESET := $(shell $(TPUT) sgr0)
_BOLD := $(shell $(TPUT) bold)

header:
	@printf "%b" "$(GREEN)"
	@echo
	@echo
	@echo	"					███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗		"
	@echo	"					████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝		"
	@echo	"					██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ 		"
	@echo	"					██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ 		"
	@echo	"					██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗		"
	@echo	"					╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝		"
	@echo	"											    						  by Salabbe    "
	@echo
	@echo
	@printf "%b" "$(CYAN)CC:	$(YELLOW)$(CC)\n"
	@printf "%b" "$(CYAN)CFlags:	$(YELLOW)$(CFLAGS)\n"
	@printf "%b" "$(OFF)"
	@echo
