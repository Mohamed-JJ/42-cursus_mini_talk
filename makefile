NAME = minitalk
CC = cc

FLAGS = -Wall -Wextra -Werror


RM = rm -rf

SRC = helping.c
SOURCE_C = client.c
SOURCE_S = server.c
SOURCE_C_B = client_bonus.c
SOURCE_S_B = server_bonus.c

OBJ = $(SRC:.c=.o)

OBJECTS_S = $(SOURCE_S:.c=.o)
OBJECTS_C = $(SOURCE_C:.c=.o)
OBJECTS_S_B = $(SOURCE_S_B:.c=.o)
OBJECTS_C_B = $(SOURCE_C_B:.c=.o)

%.o : %.c mini_talk.h
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJECTS_C) $(OBJECTS_S) $(OBJ) minitalk.h
	@$(CC) $(FLAGS) $(OBJECTS_C) $(OBJ) -o client
	@$(CC) $(FLAGS) $(OBJECTS_S) $(OBJ) -o server

bonus : $(OBJECTS_C_B) $(OBJECTS_S_B) $(OBJ)
		@$(CC) $(FLAGS) $(OBJECTS_C_B) $(OBJ) -o client_bonus
		@$(CC) $(FLAGS) $(OBJECTS_S_B) $(OBJ) -o server_bonus

all: $(NAME)

clean:
	@$(RM) $(OBJECTS_C) $(OBJECTS_S) $(OBJ)

fclean: clean
	@$(RM)  $(OBJECTS_C) $(OBJECTS_S) client server
	@$(RM)  $(OBJECTS_C_B) $(OBJECTS_S_B) client_bonus server_bonus

re: fclean all

.PHONY : re clean all fclean