
#include <string>
#include <cstdio>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <argparse/argparse.hpp>


int main(int argc, char *argv[]) {
    printf("KDC");
    argparse::ArgumentParser arg_parser("client");
    arg_parser.add_argument("--in-port")
        .help("Port ")
        .default_value(6767);
    arg_parser.parse_args(argc, argv);
    int opt = 1;
    int in_port = arg_parser.get<int>("--in-port");
    printf("Client");
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, 1);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(in_port);
    server_address.sin_addr.s_addr = INADDR_ANY;
    /*
    IP
    Name
    master key
    session_key
    OUTPUT FUNCTIONS:
        get_from_kdc(to kdc, id a, id b, nonce 1), INIT_KEY_FROMKDC
        initiate_to_client(to b, E(kb, [ks, id a])) INIT_KEY_TOCLIENT
        handshake1 E(ks, nonce 2) HANDSHAKE1
        handshake2 E(ks, f(nonce 2)) HANDSHAKE2

    REQUEST INPUT :
        KDCRESPONSE: got E(Ka, [Ks, IDa, IDb, N1]), E(Kb, [Ks, IDa])
            D(ka) => ks, ida, idb, n1 
            init_to_client(to b, E(Kb,[Ks, id a]))
        INIT_KEY_TOCLIENT: Got E(Kb, [Ks, IDa])
            D(kb) => Ks, IDa
            handshake1(to a, E(Ks, nonce2))
        HANDSHAKE1: Got E(ks, nonce 2)
            D(ks) => nonce 2
            handshake2(to b, f(nonce 2))
        HANDSHAKE2: Got E(ks, f(nonce 2))
            verify nonce 2 
            OK


    nonce1 (N1)
    get_auth() {
        request to KDC (IDa, IDb, N1)
        get from KDC (E(Ks, [Kb, IDa, IDb, N1]), E(Kb, [Ks, IDa]))
    }
    initiate_()
    */
    return 0;
    return 0;
}