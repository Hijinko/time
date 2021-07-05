#include "../include/sc.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

/*
* @brief creates and returns a sockaddr_in structure with the given parameters
* @param family integer representing the sock family i.e AF_INET
* @param port integer representing the socket port
* @param p_address char pointer that is the ip address for the 
*/
struct sockaddr_in * sc_get_sockaddr_in(int family, int port, char * p_address)
{
    struct sockaddr_in * p_saddr_t = calloc(1, sizeof(struct sockaddr_in));
    p_saddr_t->sin_family = family;
    p_saddr_t->sin_port = htons(port);
    inet_aton(p_address, &p_saddr_t->sin_addr);
    return p_saddr_t;
}
