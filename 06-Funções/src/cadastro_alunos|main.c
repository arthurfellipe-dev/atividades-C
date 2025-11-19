#include <stdio.h>
#include "util.h"

#define QUANTIDADE 240

struct aluno dicente[QUANTIDADE];

int main() {
    int escolha, i = 0, alunos_cadastrados = 0, id;

    do {
        escolha = 0;
        setbuf(stdin, NULL);
        printf("\n1-Cadastrar aluno\n2-calcular média\n3-sair\n4-Todos alunos cadastrados\n5-Ver aluno por id\n");
        scanf("%d", &escolha);

        switch (escolha) {
        case 1:
            dicente[i].id = gerarID();
            cadastrar_aluno(dicente, i);
            alunos_cadastrados++;
            i++; // para mudar o indice de dicente
            break;
        case 2:
                for (int j = 0; j < 3; j++) {
                    setbuf(stdin, NULL);
                    printf("\ndigite suas notas\n");
                    scanf("%f", &dicente[i].nota[j]);
                }
                dicente[i].media = calcular_media(dicente[i].nota[0], dicente[i].nota[1], dicente[i].nota[2]);
                printf("media: %.2f\n", dicente[i].media);

                break;
        case 3:
                escolha = 3;
                break;
        case 4:
            mostrar_alunos(dicente, alunos_cadastrados);
            break;
        case 5:
            printf("\nDigite o id: ");
            scanf("%d", &id);

            int busca = buscarAluno(id, alunos_cadastrados, dicente);

            if (busca != -1){
                printf("\nAluno %d foi encontrada\n", busca + 1);
                printf("nome: %s\nturma: %s\nmedia: %.2f\n", dicente[busca].nome, dicente[busca].turma, dicente[busca].media);
            } else
               printf("id não encontrado\n");
            break;
        default:
            printf("\nOpcao invalida");
            break;
        }
    } while (escolha != 3);

    return 0;
}
