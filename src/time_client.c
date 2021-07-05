#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../include/sc.h" 

void display_usage(void){
    printf("USAGE: time_client <server ip> <server_port>\n");
}

int main(int argc, char * argv[])
{
    // check the user arguments 
    if (argc != 3){
        display_usage();
        exit(EXIT_SUCCESS);
    }

    enum {MAX_BUFF = 256};

    // create server struct
    struct sockaddr_in * p_server_addr_t  = sc_get_sockaddr_in(AF_INET, atoi(argv[2]), argv[1]);

    // create socket
    printf("creating socket...\n");
    int h_client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (h_client_socket < 0){
        perror("error creating socket ");
        exit(EXIT_FAILURE);
    }

    // connect to socket
    printf("connecting to socket...\n");
    if (connect(h_client_socket, (struct sockaddr *)p_server_addr_t, sizeof(struct sockaddr_in)) < 0){
        perror("error connecting to socket ");
        exit(EXIT_FAILURE);
    }

    // receive data
    printf("receiving data...\n");
    char buff[MAX_BUFF] = {'\0'}; 
    if (recv(h_client_socket, buff, MAX_BUFF - 1, 0) < 0){
        perror("error receiving data ");
        exit(EXIT_FAILURE);
    }
   
    // display data
    printf("The current time is %s", buff);

    // close socket
    close(h_client_socket);
    free(p_server_addr_t);
}
// end of file
