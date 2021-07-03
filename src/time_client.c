#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

int main(void)
{
    enum {MAX_BUFF = 256};

    // create server struct
    struct sockaddr_in server_addr_t;
    socklen_t server_len = sizeof(server_addr_t);
    memset(&server_addr_t, 0, server_len);
    server_addr_t.sin_family = AF_INET;
    server_addr_t.sin_addr.s_addr = INADDR_ANY;
    server_addr_t.sin_port = htons(8080);

    // create socket
    printf("creating socket...\n");
    int h_client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (h_client_socket < 0){
        perror("error creating socket ");
        exit(EXIT_FAILURE);
    }

    // connect to socket
    printf("connecting to socket...\n");
    if (connect(h_client_socket, (struct sockaddr *)&server_addr_t, server_len) < 0){
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
}
// end of file
