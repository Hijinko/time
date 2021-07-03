#include "../include/time_functs.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

int main(void)
{
    // create the server struct
    struct sockaddr_in server_addr_t;
    socklen_t server_len = sizeof(server_addr_t);
    memset(&server_addr_t, 0, server_len);
    server_addr_t.sin_family = AF_INET;
    server_addr_t.sin_addr.s_addr = INADDR_ANY;
    server_addr_t.sin_port = htons(8080);

    // create server socket
    printf("creating socket...\n");
    int h_server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (h_server_socket < 0){
        perror("error creating socket ");
        exit(EXIT_FAILURE);
    }

    // bind to server to socket
    printf("binding socket...\n");
    if (bind(h_server_socket, (struct sockaddr *)&server_addr_t, server_len) < 0){
        perror("error binding socket ");
        exit(EXIT_FAILURE);
    }

    // listen for connections
    printf("listening on socket...\n");
    listen(h_server_socket, 5);

    // accept connections
    int h_client_socket = accept(h_server_socket, (struct sockaddr *)&server_addr_t, &server_len);
    if (h_client_socket < 0){
        perror("error accepting connection ");
        exit(EXIT_FAILURE);
    }

    // send data to client
    printf("sending data to client...\n");
    char * p_server_data = time_get(); 
    if (send(h_client_socket, p_server_data, strlen(p_server_data), 0) < 0){
        perror("error sending data ");
        exit(EXIT_FAILURE);
    }

    // close sockets
    close(h_server_socket);
    close(h_client_socket);
}
// end of file


