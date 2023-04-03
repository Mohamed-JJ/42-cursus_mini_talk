CLIENT = client
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
SERVER = server
NAME = $(CLIENT) $(SERVER)

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = helping.c \

SRC_B = helping_bonus.c \

SOURCE_C = client.c \

SOURCE_S = server.c \

SOURCE_C_B = client_bonus.c \

SOURCE_S_B = server_bonus.c	utils_bonus.c \

all: $(NAME)

$(CLIENT) : $(SOURCE_C) $(SRC) minitalk.h
	@$(CC) $(FLAGS) -c $(SOURCE_C) $(SRC)
	@ld -r helping.o client.o -o c_combined.o
	@$(CC) $(FLAGS) c_combined.o -o $(CLIENT)

$(SERVER) : $(SOURCE_S) $(SRC) minitalk.h
	@$(CC) $(FLAGS) -c $(SOURCE_S) $(SRC)
	@ld -r helping.o server.o -o s_combined.o
	@$(CC) $(FLAGS) s_combined.o -o $(SERVER)


bonus : $(SERVER_BONUS) $(CLIENT_BONUS) minitalk_bonus.h

$(CLIENT_BONUS) : $(SOURCE_C_B) $(SRC_B) minitalk_bonus.h
	@$(CC) $(FLAGS) -c $(SOURCE_C_B) $(SRC_B)
	@ld -r helping_bonus.o client_bonus.o -o c_combined_bonus.o
	@$(CC) $(FLAGS) c_combined_bonus.o -o $(CLIENT_BONUS)

$(SERVER_BONUS) : $(SOURCE_S_B) $(SRC_B) minitalk_bonus.h
	@$(CC) $(FLAGS) -c $(SOURCE_S_B) $(SRC_B)
	@ld -r helping_bonus.o server_bonus.o utils_bonus.o -o s_combined_bonus.o
	@$(CC) $(FLAGS) s_combined_bonus.o -o $(SERVER_BONUS)

clean:
	@$(RM) helping.o client.o server.o s_combined.o c_combined.o

fclean: clean
		@$(RM) $(SERVER_BONUS) $(SERVER) $(CLIENT) $(CLIENT_BONUS) helping_bonus.o client_bonus.o server_bonus.o s_combined_bonus.o c_combined_bonus.o utils_bonus.o


re: fclean all

.PHONY : re clean all fclean

