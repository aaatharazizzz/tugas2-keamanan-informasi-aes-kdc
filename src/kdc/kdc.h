#pragma once

#include <string>
#include <cinttypes>
#include <cstdio>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

enum class KDCScenario : int {
    RequestToKDC,
    KDCResponse,
    Forward,
    Handshake1,
    Handshake2
    
};

class User {
    int id;
    std::string ip_address;
    std::vector<uint8_t> key;
};

class KDC {
private:
    std::vector<uint8_t> key;
    std::vector<uint8_t> session_key;
    int socket_opt;
    int in_port;
    int server_socket;
public:
    KDC();
    void listen();
};