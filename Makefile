SRC_DIR=srcs/
AUX_DIR=auxiliar/
LST_DIR=listas/
PAR_DIR=parsing/
BONUS_DIR=bonus/
INS_DIR=instructions/
GNL_DIR=get_next_line/
CHECK_AUX_DIR=checker_instructions/

SRC_FILES=  $(wildcard ${SRC_DIR}*.c)\
			$(wildcard ${AUX_DIR}*.c)\
			$(wildcard ${PAR_DIR}*.c)\
			$(wildcard ${INS_DIR}*.c)\
			$(wildcard ${LST_DIR}*.c)

OBJ_FILES=${SRC_FILES:.c=.o}

SRC_BONUS=	$(wildcard ${CHECK_AUX_DIR}*.c)\
			$(wildcard ${GNL_DIR}*.c)\
			$(wildcard ${AUX_DIR}*.c)\
			$(wildcard ${PAR_DIR}*.c)\
			$(wildcard ${LST_DIR}*.c)

OBJ_BONUS=${SRC_BONUS:.c=.o}

NAME=libft.a

HDR_FILE=libft.h

CC=cc

CFLAGS= 
#-Wall -Wextra -Werror -g -s 

all: ${NAME} push_swap
	clear

push_swap: ${NAME} push_swap.c
	${CC} ${CFLAGS} push_swap.c ${NAME} -o push_swap

${NAME}: ${OBJ_FILES}
	@ar rcs $@ $?
	@echo "library created"

bonus: .bonus checker

checker:
	${CC} ${CFLAGS} bonus.c ${NAME} -o checker

.bonus: ${OBJ_BONUS} $(OBJ_BONUS)
	ar rcs ${NAME} $?
	@touch .bonus
	@echo "bonus library created"
	
clean: 
	@rm -f $(OBJ_BONUS) $(OBJ_FILES) 
	@rm -f .bonus
	@echo "files removed"

fclean: clean 
	@rm -f ${NAME}
	@echo "files really removed"

re: fclean all

.PHONY: re fclean clean all

# so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC_FILES)
#	gcc -nostartfiles -shared -o libft.so $(OBJ_FILES)
# 