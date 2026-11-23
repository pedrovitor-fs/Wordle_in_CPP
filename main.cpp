#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main(){
    srand(time(nullptr)); // Seed do random
    // ler arquivo txt e jogar tudo num vector porque sim 
    std::vector<std::string> palavras;
    std::fstream file;
    file.open("palavras.txt");
    if(!file.is_open()){
        printf("ERRO: erro ao tentar abrir o arquivo 'palavras.txt'\n");
        return -1;
    }

    std::string linha;
    while (std::getline(file, linha)) {
        // Remove \r do final (Windows CRLF)
        if (!linha.empty() && linha.back() == '\r') {
            linha.pop_back();
        }
        if (!linha.empty()) {
            palavras.push_back(linha);
        }
    }
    file.close();

    if (palavras.empty()) {
        printf("ERRO: nenhuma palavra carregada do arquivo\n");
        return -1;
    }

    // selecionar aleatoriamente uma palavra
    int id_word = rand() % palavras.size();
    std::string word_select = palavras[id_word];
    printf("PALAVRA SELECIONADA: %s\n", word_select.c_str());
    // LOOP DE JOGO
    // entrada do usuario
    // verificar se acertou alguma letra
    // finalizar caso atinja 5 tentativas
    return 0;
}