#include "aes.h"
#include "kdc.h"
#include <string>
#include <cstdio>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <argparse/argparse.hpp>
#include <nlohmann/json.hpp>
using nlohmann::json;



void listen() {

}

void handle_request(char* buffer) {
    json data = json::parse(buffer);
}

void request_to_kdc(int id_a, int id_b, int nonce) {
    json request = {
        {"type", static_cast<int>(KDCScenario::RequestToKDC)},
        {"id_a", id_a},
        {"id_b", id_b},
        {"nonce", nonce}
    };
}

void handle_kdc_response(const char* buffer) {
    /*
    {
        {"type", static_cast<int>(KDCScenario::KDCResponse)},
        {"part_1", id_a},
        {"part_2", id_b}
    }
    */
    
}

void request_to_kdc(int id_a, int id_b, int nonce) {
    json request = {
        {"type", static_cast<int>(KDCScenario::RequestToKDC)},
        {"id_a", id_a},
        {"id_b", id_b},
        {"nonce", nonce}
    };
}

KDC::KDC()
{
    this->server_socket = socket(AF_INET, SOCK_STREAM, 0);
}

void KDC::listen()
{
    while(true) {
        int client_socket = accept(server_socket, nullptr, nullptr);
        
    }
}
