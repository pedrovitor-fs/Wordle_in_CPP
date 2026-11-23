#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

void dif(int list_comparation[], const char a[], const char b[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        // comparação simples
        list_comparation[i] = (a[i] == b[i]) ? 1 : 0;
    }
}

int main()
{
    srand(time(nullptr)); // Seed do random
    // ler arquivo txt e jogar tudo num vector porque sim
    std::vector<std::string> palavras;
    std::fstream file;
    file.open("palavras.txt");
    if (!file.is_open())
    {
        printf("ERRO: erro ao tentar abrir o arquivo 'palavras.txt'\n");
        return -1;
    }

    std::string linha;
    while (std::getline(file, linha))
    {
        // Remove \r do final (Windows CRLF)
        if (!linha.empty() && linha.back() == '\r')
        {
            linha.pop_back();
        }
        if (!linha.empty())
        {
            palavras.push_back(linha);
        }
    }
    file.close();

    if (palavras.empty())
    {
        printf("ERRO: nenhuma palavra carregada do arquivo\n");
        return -1;
    }

    // selecionar aleatoriamente uma palavra
    int id_word = rand() % palavras.size();
    std::string word_select = palavras[id_word];
    printf("PALAVRA SELECIONADA: %s\n", word_select.c_str());
    // LOOP DE JOGO
    int n_tentativas = 5;
    int list_result[5] = {0};
    while (n_tentativas > 0)
    {
        int n_acertos = 0;
        // entrada do usuario
        char palavra_digitada[6]; // 5 letras + \0
        printf("> ");
        scanf("%5s", palavra_digitada);
        // printf("PALAVRA DIGITADA: %s\n",palavra_digitada);
        // verificar se acertou alguma letra
        int list_comparation[5] = {0};
        dif(list_comparation, word_select.c_str(), palavra_digitada, 5);

        printf(">>");
        for(int i =0 ; i < 5 ; i ++){
            list_result[i] = list_comparation[i] == 1 && list_result[i] == 0 ? 1 : list_result[i] ;
            printf("%c", (list_comparation[i] ==1? palavra_digitada[i] : '_' ));
            
        }
        printf("  ");
        for(int i =0 ; i < 5 ; i ++){
            n_acertos += list_result[i];
            printf("%c", (list_result[i] ==1? word_select[i] : '_' ));
        }
        printf("\n");
        // mostrar resultado
        if(n_acertos == 5){
            printf("Parabens voce acertou a palavra\n");
            return 0;
        }
        // finalizar caso atinja 5 tentativas
        n_tentativas--;
    }
    printf("apalavra selecionada foi : %s\n", word_select);
    return 0;
}