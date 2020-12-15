NAME = lemipc

SRC = main.c sem.c shm.c msgq.c mainloop.c map.c proto.c proto_handle.c clear.c\
	handle_step.c map_utils.c\
	handler_done.c handler_enter.c handler_exit.c handler_kick.c handler_no.c \
	handler_req.c handler_yes.c
	
CC = gcc

SRCDIR = src

OBJDIR = obj

OBJ = $(addprefix ${OBJDIR}/, $(SRC:.c=.o))

DEP = $(addprefix ${OBJDIR}/, $(SRC:.c=.d))

CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = -Iincludes/ 

all: ${NAME}

${NAME}: ${OBJ}
	@${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJ} -lpthread

${OBJDIR}/%.o: ${SRCDIR}/%.c
	@/bin/mkdir -p ${OBJDIR}
	${CC} ${CFLAGS} ${INCLUDES} -c -o $@ $<

clean:
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	@/bin/rm -f ${NAME}
	@/bin/rm -Rf ${NAME}.dSYM

test:
	@${CC} -g ${INCLUDES} -I. -o ${NAME} $(addprefix src/, ${SRC})

re: fclean all
