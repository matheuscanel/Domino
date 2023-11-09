#include <stdio.h>
#include <stdlib.h>

typedef struct Domino{
    int right;
    int left;
}Domino;

typedef struct Node{
    Domino values;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct Player{
    Node *hand;
    char *name;  
}Player;

typedef struct Board{
    Node *game;
    int playersTurn;
    int NumberOfPlayers;
}Board;

Board *createBoard(int N);
void generatePieces(Node **stock);
void printStock(Node *stock);



int main(){

    //Menu
    int choice;

    printf("----------------------------------------\n");
    printf("Selecione a opcao desejada:\n");
    printf("(1) Jogar partida\n(2)Ranking\n(3)fechar\n");
    printf("----------------------------------------\n");
    scanf("%d", &choice);
    

    if(choice == 1){
        int numberOfPlayers;
        printf("Quantos jogadores irão jogar?");
        scanf("%d", &numberOfPlayers);//perguntar o numero de jogadores

        Board *board = createBoard(numberOfPlayers); //criar o board

        //criar peças

        Node *stock=NULL;
        generatePieces(&stock);
        printStock(stock);


        //embaralhar peças
        
        //criar jogadores

        //destribuir peças
        printf("Logica do jogo");
    }
    else if(choice == 2){
        printf("Ranking dos jogadores");
    }
    else if (choice == 3) {
        printf("Fechar programa");
        return 0;    
    }
    else{
        printf("Opção inválida, tente novamente");
    }


    return 0;
}

Board *createBoard(int N){
    Board *board = (Board*) malloc(sizeof(Board));

    board->game = NULL;  // Inicialmente, não há peças no tabuleiro
    board->playersTurn = 0;  // O primeiro jogador (índice 0) começa
    board->NumberOfPlayers = N;  // Define o número de jogadores

    return board;

}

void generatePieces(Node **stock){
    for (int left = 0; left <= 6; left++) {
        for (int right = left; right <= 6; right++) {
            // Alocar memória para um novo nó
            Node *newNode = (Node*) malloc(sizeof(Node));

            // Configurar os valores da peça de dominó
            newNode->values.left = left;
            newNode->values.right = right;
            newNode->next = NULL;
            newNode->prev = NULL;

            // Anexar o novo nó à lista de peças (stock)
            if (*stock == NULL) {
                // Primeira peça a ser inserida
                *stock = newNode;
            } else {
                // Anexar ao final da lista
                Node *current = *stock;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;
                newNode->prev = current;
            }
        }
    }
}

void printStock(Node *stock) {
    printf("Peças de dominó disponíveis:\n");
    while (stock != NULL) {
        printf("[%d|%d] ", stock->values.left, stock->values.right);
        stock = stock->next;
    }
    printf("\n");
}