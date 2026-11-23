# Wordle em C++

Um clone do Wordle rodando no terminal, escrito em **C++ moderno** para fins educacionais.<br>
**Créditos**: Baseado no projeto [Wordle_in_C](https://github.com/NadolnyJoao/Wordle_in_C) de **João Nadolny** — Acredito que o meu esteja melho 😁.
## 🎮 Como funciona

- O jogo carrega uma lista de palavras de 5 letras do arquivo `palavras.txt`
- Uma palavra é sorteada aleatoriamente a cada execução
- Você tem **5 tentativas** para adivinhar a palavra
- A cada palpite, o jogo mostra um array de comparação:
  - `1` = letra correta na posição correta 🟩
  - `0` = letra errada ou na posição errada ⬜
- Vence se acertar todas as 5 posições (`1 1 1 1 1`)
- Perde se acabar as tentativas

## 🚀 Como compilar e rodar

```bash
g++ main.cpp -o main -std=c++17
./main
```

> **Nota**: Requer compilador com suporte a C++17 (GCC 7+, Clang 5+, MSVC 19.1+)

## 📸 Exemplo de execução

```text
PALAVRA SELECIONADA: itens
> casas
>>____s  ____s
> tenis
>>____s  ____s
> itens
>>itens  itens
Parabens voce acertou a palavra
```

Outro exemplo (derrota):

```text
PALAVRA SELECIONADA: barco
> furia
>>__r__  __r__
> casas
>>_a___  _ar__
> carta
>>_ar__  _ar__
> barca
>>barc_  barc_
> barce
>>barc_  barc_
apalavra selecionada foi : barco
```

> **Legenda**: `1` = letra certa no lugar certo | `0` = letra errada ou no lugar errado

## 📁 Estrutura do projeto

```
wordle/
├── main.cpp      # Código principal do jogo
├── palavras.txt  # Lista de palavras (uma por linha, 5 letras)
└── README.md     # Este arquivo
```

## 🔧 Detalhes técnicos

- **Linguagem**: C++17
- **Bibliotecas padrão**: `<vector>`, `<string>`, `<fstream>`, `<cstdlib>`, `<ctime>`, `<cstdio>`
- **Aleatoriedade**: `srand(time(nullptr))` + `rand()` para seleção da palavra secreta
- **Leitura de arquivo**: `std::getline` com remoção automática de `\r` (compatível Windows/Linux)
- **Entrada do usuário**: `scanf("%5s", buffer)` com proteção contra buffer overflow
- **Comparação**: Case-sensitive, posição a posição

## 📝 Regras do arquivo `palavras.txt`

- Uma palavra por linha
- Exatamente 5 letras (sem acentos, cedilha ou caracteres especiais)
- Linhas vazias são ignoradas automaticamente

Exemplo:
```
abril
abrir
abriu
casa
mesa
...
```

## ⚡ Melhorias em relação à versão base

Este projeto foi **baseado no [Wordle_in_C do NadolnyJoao](https://github.com/NadolnyJoao/Wordle_in_C)** (versão em C), mas com as seguintes melhorias:

| Característica | Wordle_in_C (C) | Este projeto (C++) |
|----------------|-----------------|-------------------|
| Tentativas | 10 | **5** (mais desafiador) |
| Feedback | Letras reveladas com `_` | **Array numérico 1/0** (mais limpo) |
| Comparação | Case-insensitive | **Case-sensitive** |
| Memória | `malloc`/`free` manual | **RAII** (`std::string`, `std::vector`) |
| Leitura | `fgets` + `strcspn` | **`std::getline`** (mais seguro) |
| Código | Monolítico em `main.c` | **Função separada** `dif()` |
| Padrão | C99 | **C++17 moderno** |

## 🎯 Próximos passos (ideias)

- [ ] Suporte a letras amarelas (letra certa, posição errada)
- [ ] Validação de palavras no dicionário
- [ ] Interface colorida no terminal (ANSI escape codes)
- [ ] Modo "hard" (obrigar usar letras reveladas)
- [ ] Contador de vitórias/derrotas persistente
- [ ] Makefile / CMake para build

---

