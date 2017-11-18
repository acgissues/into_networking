#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<arpa/inet.h> // inet_addr

int main(int argc, char *argv[])
{
    int socket_desc;
    struct sockaddr_in server;
    char *message, server_reply[2000];

    // socket creation
    // int domain, int type, int protocol
    socket_desc = socket(AF_INET, SOCK_STREAM, 0); // socket(2)

    if(socket_desc == -1)
    {
        printf("could not create socket");
    }

    server.sin_addr.s_addr = inet_addr("216.58.219.174"); // inet(3)
    server.sin_family = AF_INET;

    // host short to network short
    server.sin_port = htons(80); // byteorder(3)

    // connect(3p)
    // necessary because of tcp before sending packets
    if(connect(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }

    puts("connected");

    // sending data send(3p)
    message = "GET / HTTP/1.1\r\n\r\n";
    if(send(socket_desc, message, strlen(message), 0) < 0)
    {
        puts("send failed");
        return 1;
    }

    puts("data sent\n");

    // revceiving reply
    if(recv(socket_desc, server_reply, 2000, 0) < 0)
    {
        puts("recv failed");
        return 1;
    }

    puts("reply received\n");
    puts(server_reply);

    close(socket_desc);

    return 0;
}
