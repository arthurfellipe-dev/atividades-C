#include <stdio.h>
#include "util.h"

int gerarID() {
    static int idAtual = 1;
    return idAtual++;
}

int buscarAluno(int id, int alunos_cadastrados, struct aluno dicente[]) {
    for (int i = 0; i < alunos_cadastrados; i++) {
        if (dicente[i].id == id) {
            return i;
        }
    }
    return -1;
}

float calcular_media(float n1, float n2, float n3) {
    float media = (n1 + n2 + n3) / 3;
    return media;
}

void cadastrar_aluno(struct aluno dicente[], int i) {
    setbuf(stdin, NULL);
    printf("seu id é: %d", dicente[i].id);
    printf("\nNome do dicente: ");
    fgets(dicente[i].nome, sizeof(dicente[i].nome), stdin);
    printf("\nTurma: ");
    fgets(dicente[i].turma, sizeof(dicente[i].turma), stdin);

}

void mostrar_alunos(struct aluno dicente[], int alunos_cadastrados) {
    if (alunos_cadastrados == 0) {
        printf("\nNao existe cadastros ainda\n");
    }
    for (int i = 0; i < alunos_cadastrados; i++) {
        printf("\ndicente: %s\nturma: %s\nmedia: %.2f", dicente[i].nome, dicente[i].turma, dicente[i].media);
    }
}
