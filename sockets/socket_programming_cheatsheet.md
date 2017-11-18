# Socket Programming Cheatsheet

## `<sys/socket.h>`

### socket(2)
```c
int socket(int domain, int type, int protocol);
```

Creates endpoint and returns file descriptor that refers to that
endpoint.

- `domain`: selects the protocol family used for communication. Network
  Layer.
- `type`: specifies communication semantics. `SOCK_STREAM`(TCP) or
  `SOCK_DGRAM`(UDP). Transport Layer.
- `protocol`: particular protocol to be used with the socket.
  protocols(5).

### connect(3P)
```c
int connect(int socket, const struct sockaddr *address, socklen_t
address_len);
```
Attempts to make a connection to a connection-mode socket or sets or
resets the peer address of a connectionless-mode socket.

- `socket`: specifies the file descriptor associated with the socket.
- `address`: points to a `sockaddr` structure containing the peer
  address. Length & format are address family dependant.
- `address_len`: specifies the length of the `sockaddr` structure.

### send(3P)
```c
ssize_t send(int socket, const void *buffer, size_t length, int flags);
```
Shall initiate transmission of a message from the specified socket to
its peer.

- `socket`: specifies the socket file descriptor.
- `buffer`: points to the buffer containing the message to send.
- `length`: specifies the length of the message in bytes.
- `flags`: specifies the type of message transmission.
