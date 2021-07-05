CMD = cc -Wall -Wextra

all: time_server time_client
time_server: time_server.o time_functs.o
	$(CMD) time_server.o time_functs.o -o time_server
time_server.o: ./src/time_server.c 
	$(CMD) -c ./src/time_server.c
time_functs.o: ./src/time_functs.c ./include/time_functs.h
	$(CMD) -c ./src/time_functs.c
time_client: time_client.o sc.o
	$(CMD) time_client.o ./src/sc.c -o time_client
time_client.o: ./src/time_client.c
	$(CMD) -c ./src/time_client.c
sc.o: ./src/sc.c ./include/sc.h
	$(CMD) -c ./src/sc.c
clean:
	rm -rf time_server time_client time_server.o time_functs.o time_client.o \
	sc.o
debug: $(CMD) += -g
debug: clean time_server time_client 
