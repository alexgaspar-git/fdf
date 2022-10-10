SRCS		= fdf.c \
				parsing.c \
				parsing_utils.c \
				utils.c \
				utils_bis.c \
				split.c \
				init.c \
				init_utils.c \
				colors.c \
				draw_line.c \
				draw_matrix.c \
				free.c \
				get_next_line.c \
				get_next_line_utils.c

SRCS_BONUS	= fdf_bonus.c \
				init_bonus.c \
				init_utils_bonus.c \
				parsing_bonus.c \
				parsing_utils_bonus.c \
				utils_bonus.c \
				utils_bis_bonus.c \
				split_bonus.c \
				colors_bonus.c \
				rotate_bonus.c \
				key_reg_bonus.c \
				draw_line_bonus.c \
				draw_matrix_bonus.c \
				free_bonus.c \
				get_next_line_bonus.c \
				get_next_line_utils_bonus.c 

SRCS		:= $(addprefix src/,$(SRCS))

SRCS_BONUS	:= $(addprefix src_bonus/,$(SRCS_BONUS))

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME		= fdf

NAME_BONUS	= fdf_bonus

CC			= gcc

RM			= rm -rf

%.o: %.c
	${CC} -Wall -Wextra -Werror -Imlx -Iinclude -c $< -o $@

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -lmlx -framework OpenGL -framework AppKit -o ${NAME} ${OBJS}

all:		${NAME}

$(NAME_BONUS):	${OBJS_BONUS}
				${CC} ${CFLAGS} -lmlx -framework OpenGL -framework AppKit -o ${NAME_BONUS} ${OBJS_BONUS}

bonus:		$(NAME_BONUS)

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME} ${NAME_BONUS}

re:			fclean all

.PHONY:		all clean fclean re bonus
