# algoritmos_avancados.c

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
<img width="925" height="1525" alt="image" src="https://github.com/user-attachments/assets/7e4e1ce5-e5d0-4e2c-8cca-b4a65e78365f" />
