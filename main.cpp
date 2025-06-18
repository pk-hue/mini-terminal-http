#include <iostream>
#include <string>
#include <curl/curl.h>

// Função de callback para armazenar a resposta da requisição
size_t write_callback(void* contents, size_t size, size_t nmemb, std::string* output) {
    output->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Função para fazer requisição e tratamento da url
std::string fazerRequisicaoGet(const std::string& url) {
    CURL* curl = curl_easy_init();
    std::string response;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        if (CURLcode res = curl_easy_perform(curl); res != CURLE_OK) std::cout << "Erro: " << curl_easy_strerror(res);
        curl_easy_cleanup(curl);
    }else {
        std::cerr << "Erro ao inicializar o CURL" << '\n';
    }
    return response;
}

//Função de inicialização e impressão da resposta no terminal
void inicializaTerminal() {
    std::string url;
    while (true) {
        std::cout << "URL >";
        std::cin >> url;

        if (url == "sair") {
            break;
        }

        std::string response = fazerRequisicaoGet(url);
        std::cout << "Resposta do Servidor: \n" << response << '\n';
    }
}

int main() {
    std::cout << "====== [ Mini Terminal HTTP com libcurl ] ======\n";
    inicializaTerminal();
    std::cout << "Encerrando programa!" << '\n';
    return 0;
}