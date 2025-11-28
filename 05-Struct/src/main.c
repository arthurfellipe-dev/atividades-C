#include <stdio.h>

#define QNTD 200

typedef struct {
    char nome[50];
    float preco;
    int qntd, id;
    char placa[8];
} Dados;

Dados carro[QNTD];

void criar() {

}

void listar() {

}

void excluir() {

}

void atualizar() {

}
int main(void) {
    int opcao;

    do {
        printf("\n0 - Sair\n");
        printf("1- Cadastrar\n");
        printf("2- Listar\n");
        printf("3- Atualizar\n");
        printf("4- Excluir\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: criar(); break;
            case 2: listar(); break;
            case 3: atualizar(); break;
            case 4: excluir(); break;
            case 0: printf("\nvoce saiu\n"); break;
            default: printf("\nOpcao invalida\n");
        }
    } while (opcao != 0);

    return 0;
}