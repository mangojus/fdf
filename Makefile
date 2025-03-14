# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rshin <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 17:37:30 by rshin             #+#    #+#              #
#    Updated: 2025/03/14 14:31:09 by rshin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# === CONFIG ===

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

IFLAGS = -I $(INC) -I $(LIBMLX) -I $(LIBFT)/$(INC) -MMD -MP

LDFLAGS = -lX11 -lXext -lm -lz

RM = rm -rf

# === PATHING ===

SRC_DIR = src

BLD_DIR = .build

SRC = $(SRC_DIR)/main.c \
	  $(SRC_DIR)/utils.c \
	  $(SRC_DIR)/parsing.c \
	  $(SRC_DIR)/init.c \
	  $(SRC_DIR)/algo.c \
	  $(SRC_DIR)/rendering.c
#	  $(SRC_DIR)/controls.c

INC = include

LIBMLX = lib/minilibx-linux

LIBFT = lib/libft

LIB_A = $(LIBMLX)/libmlx.a \
		$(LIBFT)/libft.a

OBJ = $(patsubst $(SRC_DIR)/%.c, $(BLD_DIR)/%.o, $(SRC))

DEP = $(addsuffix .d, $(basename $(SRC)))

# === TARGET RULES ===

all: $(NAME)

$(NAME): $(OBJ) $(LIB_A) Makefile
	make -C $(LIBFT)
	make -C $(LIBMLX)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) $(LIB_A) $(LDFLAGS) -o $(NAME)

$(BLD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIB_A): FORCE
	make -C $(LIBFT)
	make -C $(LIBMLX)

clean:
	make -C $(LIBFT) clean
	make -C $(LIBMLX) clean

re: fclean all

fclean: clean
	$(RM) $(LIBFT)/$(BLD_DIR) $(LIB_A)
	$(RM) $(BLD_DIR) $(NAME)

FORCE:

-include $(DEP)

.PHONY: all clean fclean re FORCE
