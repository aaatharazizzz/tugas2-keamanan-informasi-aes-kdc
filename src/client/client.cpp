#include "aes.h"
#include "client.h"
#include "kdc_scenario_enum.h"

#include <string>
#include <cstdio>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <argparse/argparse.hpp>
#include <nlohmann/json.hpp>
#include <base64.hpp>
using nlohmann::json;



void listen() {

}

void handle_request(char* buffer) {
    json data = json::parse(buffer);
}

void Client::request_to_kdc(int id_b, int nonce) {
    json request = {
        {"type", static_cast<int>(KDCScenario::RequestToKDC)},
        {"id_a", this->id},
        {"id_b", id_b},
        {"nonce", nonce}
    };
}

void Client::handle_kdc_response(const char* buffer) {
    /*
    {
        {"type", static_cast<int>(KDCScenario::KDCResponse)},
        {"part_1", id_a},
        {"part_2", id_b}
    }
    */
   json response = json::parse(buffer);
   std::string part1_str;
   response.at("part1").get_to(part1_str);
   std::string part1 = base64::from_base64(part1_str);
   AES aes = AES(this->key, AESType::AES128, AESBlockMode::ECB);
   std::vector<uint8_t> decrypted_part1 = aes.decrypt(std::vector<uint8_t>(part1.begin(), part1.end()));
   //extract 
}

void initiate_transfer_key(int id_a, int id_b) {
    json request = {
        {"type", static_cast<int>(KDCScenario::RequestToKDC)},
        {"id_a", id_a},
        {"id_b", id_b}
    };
}

Client::Client() {
    this->client_socket = socket(AF_INET, SOCK_STREAM, 0);
    this->server_socket = socket(AF_INET, SOCK_STREAM, 0);
}
