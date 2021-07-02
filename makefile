CMD = cc -Wall -Wextra

time_server: time_server.o
	$(CMD) time_server.o -o time_server
time_server.o: time_server.c
	$(CMD) -c time_server.c
clean:
	rm -rf time_server time_server.o
debug: $(CMD) += -g
debug: clean time_server 
