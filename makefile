CMD = cc -Wall -Wextra

time_server: time_server.o time_functs.o
	$(CMD) time_server.o time_functs.o -o time_server
time_server.o: ./src/time_server.c 
	$(CMD) -c ./src/time_server.c
time_functs.o: ./src/time_functs.c ./include/time_functs.h
	$(CMD) -c ./src/time_functs.c
clean:
	rm -rf time_server time_server.o time_functs.o
debug: $(CMD) += -g
debug: clean time_server 
