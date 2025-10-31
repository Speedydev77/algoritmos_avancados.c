#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
DESAFIO NÍVEL NOVATO - ALGORITMOS AVANÇADOS
By Speedydev77

O que você vai fazer?
A Enigma Studios, desenvolvedora de jogos voltados para o ensino de lógica e programação, está desenvolvendo um novo título chamado Detective Quest, um jogo eletrônico em que o jogador precisa explorar uma mansão para encontrar o culpado.
 
Designado como desenvolvedor(a) técnico(a), você é responsável por implementar o sistema que controla o mapa da mansão, representado por uma árvore binária. O seu trabalho será garantir que o mapa seja criado com exatidão e que permita ao jogador explorá-lo a partir do Hall de entrada, escolhendo entre os caminhos à esquerda ou à direita em cada sala.
 
Você implementará um programa em C que simula o mapa da mansão como uma árvore binária com nome para cada cômodo. A árvore é montada de modo automático em alocação dinâmica, e o jogador poderá explorar esse mapa até chegar a um cômodo que não tenha mais caminhos.
Requisitos funcionais
Seu programa em C deverá:
 
Criar uma árvore binária para representar o mapa da mansão.
 
Permitir a exploração interativa da mansão a partir do Hall de entrada, escolhendo ir para a esquerda (e) ou para a direita (d).
 
Além disso, a estrutura da mansão já vem definida no código, e não é necessário inseri-la manualmente — afinal, ela é criada de modo automático pela função main(), usando a função criarSala().
 
Seu programa em C ainda deverá viabilizar a exploração continua até o jogador alcançar um cômodo que não possua caminhos à esquerda nem à direita (isto é, um nó-folha na árvore). Por fim, o programa exibe o nome de cada sala visitada durante a exploração.
 
Cada cômodo possui:
 
nome: uma string que identifica a sala (por exemplo: Sala de estar, Cozinha ou Jardim).
Requisitos não funcionais
Usabilidade: a saída do programa deve ser clara e direta, guiando o jogador na exploração.
 
Legibilidade: o código deve estar bem-organizado, com nomes intuitivos e identação apropriada.
 
Documentação: o código deve possuir comentários explicando o propósito das funções, como:
 
criarSala() – cria, de forma dinâmica, uma sala com nome.
 
explorarSalas() – permite a navegação do jogador pela árvore.
 
main() – monta o mapa inicial e dá início à exploração.
Simplificações para o nível novato
Utiliza apenas árvore binária (sem busca, inserção dinâmica ou remoção).
 
Há um menu de opções; a navegação acontece a partir das escolhas do usuário (e, d ou s para sair).
 
Cria-se a árvore de forma manual no código-fonte, e ela não é modificada em tempo de execução.
Conceitos trabalhados
Árvore binária: estrutura de dados hierárquica com dois filhos por nó.
 
Structs: Criação de um tipo personalizado (Sala) com campos para nome e ponteiros.
 
Alocação dinâmica: uso de malloc para criação de nós da árvore.
 
Operadores condicionais: controle das decisões do jogador (if, else).
 
Modularização: separação de funcionalidades em funções distintas, com responsabilidades claras.

*/



//Estrutura que representa uma sala (nó da árvore)
typedef struct sala {
    char nome[50];         //Nome do cômodo
    struct sala *esquerda; //Ponteiro para o caminho à esquerda
    struct sala *direita;  //Ponteiro para o caminho à direita
} Sala;

//========== Funções básicas da árvore ==========



// Função que cria dinamicamente uma sala com nome
Sala* criarSala(const char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}



// Função recursiva para liberar memória da árvore
void liberarSalas(Sala *raiz) {
    if (raiz == NULL) return;
    liberarSalas(raiz->esquerda);
    liberarSalas(raiz->direita);
    free(raiz);
}



// Função principal de exploração
void explorarSalas(Sala *atual) {
    char escolha;

    while (1) {
        printf("\nVocê está em: **%s**\n", atual->nome);

        // Se a sala atual não tem caminhos, fim da exploração
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Você chegou ao fim! Não há mais caminhos.\n");
            break;
        }

        printf("Deseja ir para (e) esquerda, (d) direita ou (s) sair da exploração? ");
        scanf(" %c", &escolha);

        if (escolha == 'e' || escolha == 'E') {
            if (atual->esquerda != NULL)
                atual = atual->esquerda;
            else
                printf("Não há caminho à esquerda!\n");
        } 
        else if (escolha == 'd' || escolha == 'D') {
            if (atual->direita != NULL)
                atual = atual->direita;
            else
                printf("Não há caminho à direita!\n");
        } 
        else if (escolha == 's' || escolha == 'S') {
            printf("Você decidiu sair da mansão.\n");
            break;
        } 
        else {
            printf("Opção inválida! Use 'e', 'd' ou 's'.\n");
        }
    }
}



/* 
Montagem do mapa da mansão (estrutura fixa)
    
         Hall de Entrada
         /            \
     Sala de Estar   Cozinha
    /      \        /      \
Biblioteca Jardim Despensa Porão
*/



//========== Função principal ==========
int main() {

    Sala *hall = criarSala("Hall de Entrada");
    Sala *salaEstar = criarSala("Sala de Estar");
    Sala *cozinha = criarSala("Cozinha");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *jardim = criarSala("Jardim");
    Sala *despensa = criarSala("Despensa");
    Sala *porao = criarSala("Porão");



    // Conexões da árvore
    hall->esquerda = salaEstar;
    hall->direita = cozinha;

    salaEstar->esquerda = biblioteca;
    salaEstar->direita = jardim;

    cozinha->esquerda = despensa;
    cozinha->direita = porao;



    // Início da exploração
    printf("Bem-vindo(a) ao Detective Quest!\n");
    printf("Explore a mansão para encontrar o culpado!\n");
    printf("============================================\n");

    explorarSalas(hall);



    // Libera a memória alocada
    liberarSalas(hall);

    printf("\nExploração encerrada. Até a próxima!\n");

    return 0;
}
