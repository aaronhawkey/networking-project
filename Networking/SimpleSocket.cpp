#include "SimpleSocket.hpp"

HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface){

    // defined address structure
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    // establish socket
    sock = socket(domain, service, protocol);
    test_connection(sock);
    // establish connection
    connection = connect_to_network(sock, address);
    test_connection(connection);
}

void HDE::SimpleSocket::test_connection(int items_to_test) {
    if (items_to_test < 0) {
        perror("Failed to connect");
        exit(EXIT_FAILURE);
    }
}


// Getter
struct sockaddr_in HDE::SimpleSocket::get_address() {
    return address;
}

int HDE::SimpleSocket::get_sock() {
    return sock;
}

int HDE::SimpleSocket::get_connection() {
    return connection;
}