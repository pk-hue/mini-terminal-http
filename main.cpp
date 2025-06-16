#include <iostream>
#include <string>
#include <curl/curl.h>

// Função de callback para armazenar a resposta da requisição
size_t write_callback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

int main() {
    std::string url;

    std::cout << "====== Mini Terminal HTTP com libcurl ======\n";
    std::cout << "Digite uma URL (ou 'sair' para encerrar):\n";

    while (true) {
        std::cout << "\nURL > ";
        std::cin >> url;

        if (url == "sair") {
            break;
        };


        CURL* curl = curl_easy_init();
        if (!curl) {
            std::cerr << "Falha ao iniciar o curl.\n";
            continue;
        }

        std::string response;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            std::cout << "\nResposta do servidor:\n";
            std::cout << response << "\n";
        } else {
            std::cerr << "\nErro na requisicao: " << curl_easy_strerror(res) << "\n";
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    std::cout << "Encerrado.\n";
    return 0;
}


