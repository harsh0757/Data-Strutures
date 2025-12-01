#include <iostream>
#include <thread>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>

void receiveMessages(int sock) {
    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytes = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes > 0) {
            std::cout << "\nMessage: " << buffer << "\n> ";
            fflush(stdout);
        }
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    connect(sock, (sockaddr*)&server_addr, sizeof(server_addr));

    std::thread(receiveMessages, sock).detach();

    std::string msg;
    while (true) {
        std::cout << "> ";
        getline(std::cin, msg);
        send(sock, msg.c_str(), msg.size(), 0);
    }
}
