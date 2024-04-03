#target
NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wextra -Wall -Werror

#libft
LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT 	   = $(LIBFT_PATH)$(LIBFT_NAME)

INC			= -I./includes -I./$(LIBFT_PATH)

SRC_PATH	= ./src/
SRC			= push_swap.c
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	= ./obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(LIBFT) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(LIBFT):
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INC)

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean