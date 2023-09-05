INC=/usr/include
INCLIB=$(INC)/../lib

MLX_PATH=libft/mlx/

INC_SRCH_PATH := 
INC_SRCH_PATH += -I$(MLX_PATH)

LFLAGS = -lbsd -L$(MLX_PATH) -lmlx -L$(INCLIB) -lXext -lX11 -lm

NAME = Cub3D
SRC = main.c ft_menu.c ft_bar_loader.c load_imgs.c keyboard.c ft_exit.c ft_check_map.c ft_utils.c ft_check_color.c ft_texture.c ft_check_tab.c ft_play.c ft_raycasting.c ft_minimap.c ft_macos.c ft_new_img.c ft_player_key.c ft_utils_2.c

OBJ = $(SRC:.c=.o)
CC = gcc

FLAGS = 

# ------------------------------ Colors ------------------------------

BOLD_RED		=		\033[1;31m

BOLD_PURPLE     =       \033[1;35m

BOLD_CYAN       =       \033[1;36m

BOLD_YELLOW     =       \033[1;33m

BOLD			=		\033[1m

NO_COLOR        =       \033[0m

# ------------------------------ Messages ------------------------------

HEADER_NAME		=		$(HEADER_TOP) $(HEADER_TOP_MID) $(HEADER_MID)$(HEADER_BOT)

HEADER_COMP     =       echo "\n👾 $(BOLD_PURPLE)Cub3D $(NO_COLOR)$(BOLD)by $(BOLD_RED)tde-los- & ...\n\n"

MLX_READY		=		echo "\n\n📥 $(BOLD)Compilation de la $(BOLD_YELLOW)Mlx$(NO_COLOR) $(BOLD)reussi !$(NO_COLOR)\n"

COMP_START      =       printf "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)$(BOLD)Debut de compilation...\r$(NO_COLOR)"

EXE_READY       =       echo "\n\n🎮 $(BOLD)Compilation de $(BOLD_PURPLE)Cub3D$(NO_COLOR) $(BOLD)reussi !$(NO_COLOR)\n"

CLEANED         =       echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Suppression des fichiers .o et de l'executable \n"

FCLEANED        =       echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Suppression des fichiers .o et de l'executable \n"

NORM			= 		echo "\n📢 $(BOLD_CYAN)NORMINETTE: $(BOLD_YELLOW)Verification de la norme de tous les fichiers en .c !\n$(BOLD_PURPLE)"

NORM_H			=		echo "\n📣 $(BOLD_CYAN)NORMINETTE: $(BOLD_YELLOW)Verification de la norme du .h\n$(BOLD_PURPLE)"

# ------------------------------ Rules ------------------------------
MAKEFLAGS += --silent

$(NAME): comp_start $(OBJ)
	@$(MAKE) -C $(MLX_PATH)
	@$(CC) libft/ft_printf/*.c libft/libft/*.c libft/gnl/*.c $(OBJ) -o $(NAME) $(INC_SRCH_PATH) $(LFLAGS)
	echo "\n"
	@$(MLX_READY)
	@$(EXE_READY)

all: $(NAME) norminette

macos: comp_start $(OBJ)
	@$(MAKE) -C $(MLX_PATH)
	@$(CC) -D WIDTH=960 -D HEIGHT=540 libft/ft_printf/*.c libft/libft/*.c libft/gnl/*.c $(OBJ) -o $(NAME) $(INC_SRCH_PATH) $(LFLAGS)
	echo "\n"
	@$(MLX_READY)
	@$(EXE_READY)

norminette:
	$(NORM)
	norminette *.c
	$(NORM_H)
	norminette -R checkDefine utils.h
	echo "\n"

comp_start:
	@$(HEADER_COMP)
	@$(COMP_START)

clean:
	$(CLEANED)
	rm -f $(NAME) $(OBJ) *~ core *.core

fclean: 
	rm -f $(NAME) $(OBJ) *~ core *.core
	$(FCLEANED)

re: clean all

%.o: %.c
	@printf "🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Compilation des fichiers :$(BOLD_CYAN) %-33.33s\r$(NO_COLOR)" $@
	@${CC} ${FLAGS} -c $< -o $@
