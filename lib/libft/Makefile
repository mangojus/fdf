# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rshin <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 20:01:21 by rshin             #+#    #+#              #
#    Updated: 2025/03/03 23:16:28 by rshin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# ===== CONFIG =====

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

IFLAGS = -I $(INC_DIR) -MMD -MP 

RM = rm -rf

# ===== PATHS =====

INC_DIR = include/

SRC_DIR = src/

BLD_DIR = .build/

SRC =

OBJ = $(patsubst $(SRC_DIR)%.c, $(BLD_DIR)%.o, $(SRC))

DEP = $(patsubst $(SRC_DIR)%.c, $(BLD_DIR)%.d, $(SRC))

# ===== SRC FILES =====

LIBFD = ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

SRC += $(addprefix $(SRC_DIR)libfd/, $(LIBFD))

LIBMEM = ft_memset.c \
		 ft_memcpy.c \
		 ft_memmove.c \
		 ft_memchr.c \
		 ft_memcmp.c \
		 ft_bzero.c \
		 ft_calloc.c

SRC += $(addprefix $(SRC_DIR)libmem/, $(LIBMEM))

LIBCHAR = ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_iswhitespace.c \
		  ft_toupper.c \
		  ft_tolower.c

SRC += $(addprefix $(SRC_DIR)libchar/, $(LIBCHAR))

LIBSTR = ft_strlen.c \
		 ft_strchr.c \
		 ft_strrchr.c \
		 ft_strlcpy.c \
		 ft_strlcat.c \
		 ft_strcmp.c \
		 ft_strncmp.c \
		 ft_strnstr.c \
		 ft_strdup.c \
		 ft_substr.c \
		 ft_strjoin.c \
		 ft_strtrim.c \
		 ft_split.c \
		 ft_strmapi.c \
		 ft_striteri.c \
		 ft_atoi.c \
		 ft_atol.c \
		 ft_atoll.c \
		 ft_itoa.c \
		 ft_ltoa.c \
		 ft_ultoa.c \
		 ft_itoa_base.c \
		 ft_ltoa_base.c \
         ft_lltoa_base.c \
         ft_ultoa_base.c

SRC += $(addprefix $(SRC_DIR)libstr/, $(LIBSTR))

LIBLST = ft_lstnew.c \
		 ft_lstadd_front.c \
		 ft_lstadd_back.c \
		 ft_lstsize.c \
		 ft_lstlast.c \
		 ft_lstdelone.c \
		 ft_lstclear.c \
		 ft_lstiter.c \
		 ft_dlstnew.c \
		 ft_dlstadd_front.c \
 		 ft_dlstadd_back.c \
		 ft_dlstlink.c \
		 ft_dlstsplit.c \
		 ft_dlstsize.c \
		 ft_dlsthead.c \
		 ft_dlstlast.c \
		 ft_dlstfree.c \
		 ft_dlstdelone.c \
		 ft_dlstclear.c \
		 ft_dlstiter.c

SRC += $(addprefix $(SRC_DIR)liblst/, $(LIBLST))

LIBALGO = ft_power.c \
		  ft_sqrt.c \
		  ft_factorial.c \
		  ft_fibonacci.c \
		  ft_is_prime.c \
		  ft_next_prime.c

SRC += $(addprefix $(SRC_DIR)libalgo/, $(LIBALGO))

PRINTF = ft_printf.c \
		 ft_printf_utils.c

SRC += $(addprefix $(SRC_DIR)printf/, $(PRINTF))

GNL = get_next_line.c \
	  get_next_line_utils.c

SRC += $(addprefix $(SRC_DIR)gnl/, $(GNL))

# ===== TARGET RULES =====

all: $(NAME)

${NAME}: $(OBJ) Makefile
	ar rcs $(NAME) $(OBJ)
	@echo "$(OK) $(BOLD)$(NAME)$(NC)"

$(BLD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(OK) $(notdir $<)"

clean:
	$(RM) $(OBJ)
	@echo "$(OK) libft cleaned !"

fclean: clean
	$(RM) $(BLD_DIR) $(NAME)
	@echo "$(OK) libft force-cleaned !"

re: fclean all
	@echo "$(OK) libft re-compiled !"

-include $(DEP)

.PHONY: all clean fclean re

# ===== TYPO =====

NC = \033[0m
BOLD = \033[1m
RED = \033[31m
GRN = \033[32m

OK = [$(GRN)✔$(NC)]
ERR = [$(RED)✘$(NC)] 
