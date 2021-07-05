CMD = cc -Wall -Wextra
OBJ = ./bin/
SRC = ./src/
INC = ./include/

all: time_server time_client
time_server: $(OBJ)time_server.o $(OBJ)time_functs.o
	$(CMD) $(OBJ)time_server.o $(OBJ)time_functs.o -o time_server
$(OBJ)time_server.o: $(SRC)time_server.c 
	$(CMD) -c $(SRC)time_server.c -o $(OBJ)time_server.o
$(OBJ)time_functs.o: $(SRC)time_functs.c $(INC)time_functs.h
	$(CMD) -c $(SRC)time_functs.c -o $(OBJ)time_functs.o
time_client: $(OBJ)time_client.o $(OBJ)sc.o
	$(CMD) $(OBJ)time_client.o $(SRC)sc.c -o time_client
$(OBJ)time_client.o: $(SRC)time_client.c
	$(CMD) -c $(SRC)time_client.c -o $(OBJ)time_client.o
$(OBJ)sc.o: $(SRC)sc.c $(INC)sc.h
	$(CMD) -c $(SRC)sc.c -o $(OBJ)sc.o
clean:
	rm -rf time_server time_client $(OBJ)*.o
debug: $(CMD) += -g
debug: clean time_server time_client 
