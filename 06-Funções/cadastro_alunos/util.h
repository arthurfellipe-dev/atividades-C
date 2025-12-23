#ifndef ATIVIDADEC1_DADOSALUNO_H
#define ATIVIDADEC1_DADOSALUNO_H

#endif //ATIVIDADEC1_DADOSALUNO_H

struct aluno {
    char nome[50];
    char turma[9];
    float nota[3];
    float media;
    int id;
};

void mostrar_alunos(struct aluno dicente[], int alunos_cadastrados);
void cadastrar_aluno(struct aluno dicente[], int i);
float calcular_media(float n1, float n2, float n3);
int gerarID();
int buscarAluno(int id, int alunos_cadastrados, struct aluno dicente[]);
