#pragma once

#include <string>
#include <cinttypes>
#include <cstdio>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

class Client {
private:
    int id;
    std::vector<uint8_t> key;
    std::vector<uint8_t> session_key;
    int socket_opt;
    int in_port;
    int server_socket;
    int client_socket;

    void request_to_kdc(int id_b, int nonce);
    void handle_kdc_response(const char* buffer);
public:
    Client();
    void listen();
    
};