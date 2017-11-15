# TCP/IP

## Layers

TCP/IP is divided into four layers.

|LAYER         |TECHNOLOGY                      |
|:---:         | ---                            |
|Application   |Telnet, FTP, e-mail, etc.       |
|Transport     |TCP, UDP                        |
|Network       |IP, ICMP, IGMP                  |
|Link          |device driver and interface card|

1. **Link / Data-Link Layer**
    Includes drivers & network interface to handle the physical interface with the cable.

2. **Network Layer (also Internet Layer)**
    Handles the movement of packets around the network.

3. **Transport Layer**
    Segments and formats the data that is flowing between hosts.

4. **Application Layer**
    Parses the data and handles the particular details for application usage.

**Router**: special-purpose hardware box for connecting networks(L:2).

Networks can be connected by a *bridge*, but on a different layer(L:1).

## IP Addresses

### Classes
*([bits]net-host)*
- A([0]7-24)
- B([10]14-16)
- C([110]21-8)
- D([1110]28(multicast group ID))
- E([11110]27(for future use))

### Types

- **Unicast**: destined for a single host.
- **Broadcast**: destined for all hosts on a given network.
- **Multicast**: destined for a set of hosts that belong to a multicast group.
