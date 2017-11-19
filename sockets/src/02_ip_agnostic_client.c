/*
 * making code work with ipv4 & ipv6
 */

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
        int socket_desc; // socket descriptor
        struct addrinfo hints; // manually added details
        struct addrinfo *server; // holds the results
        char *message; // message to be sent
        char server_reply[1000];

        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_UNSPEC; // AF_INET or AF_INET6
        hints.ai_socktype = SOCK_STREAM; // for tcp

        if(getaddrinfo("www.google.com", "80", &hints, &server) < 0){
                puts("invalid address");
                return 1;
        }

        socket_desc = socket(server->ai_family, server->ai_socktype, server->ai_protocol);

        if(socket_desc == -1){
                printf("could not create socket");
                return 1;
        }

        if(connect(socket_desc, server->ai_addr, server->ai_addrlen) < 0){
                puts("could not connect");
                return 1;
        }
        puts("connected\n");

        message = "GET / HTTP/1.1\r\n\r\n";
        if(send(socket_desc, message, strlen(message), 0) < 1){
                puts("error sending message");
                return 1;
        }
        puts("message sent\n");

        if(recv(socket_desc, server_reply, 1000, 0) < 0){
                puts("error getting reply");
                return 1;
        }

        puts("reply received\n");
        puts(server_reply);

        freeaddrinfo(server);
        close(socket_desc);
        return 0;
}
