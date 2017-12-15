#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
        int socket_desc, new_socket, c;
        struct sockaddr_in server, client;


        // create the socket file descriptor
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        if(socket_desc == -1){
                perror("socket");
                return 1;
        }

        server.sin_family = AF_INET;
        server.sin_addr.s_addr = INADDR_ANY;
        server.sin_port = htons(8888);

        // bind port for listening
        if(bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0){
                perror("bind failed");
                return 1;
        }
        puts("bind done.");

        // listen on the already bind port
        listen(socket_desc, 3);

        puts("listening on port: 8888");
        c = sizeof(struct sockaddr_in);
        new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
        if(new_socket < 0){
                perror("accept failed");
                return 1;
        }

        puts("connection accepted");
        free(socket_desc);
        free(new_socket);
        return 0;
}
