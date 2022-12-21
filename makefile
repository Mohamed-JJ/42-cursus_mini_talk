NAME = minitalk
CC = cc

FLAGS = -Wall -Wextra -Werror


RM = rm -rf

SRC = helping.c
SOURCE_C = client.c
SOURCE_S = server.c

OBJ = $(SRC:.c=.o)

OBJECTS_S = $(SOURCE_S:.c=.o)
OBJECTS_C = $(SOURCE_C:.c=.o)

%.o : %.c mini_talk.h
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJECTS_C) $(OBJECTS_S) $(OBJ) minitalk.h
	@$(CC) $(FLAGS) $(OBJECTS_C) $(OBJ) -o client
	@$(CC) $(FLAGS) $(OBJECTS_S) $(OBJ) -o server

all: $(NAME)

clean:
	@$(RM) $(OBJECTS_C) $(OBJECTS_S) $(OBJ)

fclean: clean
	@$(RM)  $(OBJECTS_C) $(OBJECTS_S) client server

re: fclean all

.PHONY : re clean all fclean