#include "util.h"
#include <stdio.h>
#include <stdlib.h>

struct Lista {
    int qntd;
    struct aluno dados[TAM];
};
int lista_tamanho(Lista* l) {
    if (l == NULL)
        return -1;
    return l->qntd;
}

Lista* criarLista() {
    Lista* l = malloc(sizeof(struct Lista));
    if (l != NULL)
        l->qntd = 0;
    return l;
}

int lista_vazia(Lista* l) {
    if (l == NULL)
        return -1;
    return (l->qntd == 0);
}

int lista_cheia(Lista* l)
{
    if (l == NULL)
        return -1;
    return (l->qntd == TAM);
}

int inserir_ordenado(Lista* l, struct aluno aluno) {
    if (l == NULL) return 0;
    if (lista_cheia(l)) return 0;

    int i = 0;
    while (i<l->qntd && l->dados[i].idade < aluno.idade)
        i++;
    for (int j = l->qntd - 1; j >= i; j--)
        l->dados[j+1] = l->dados[j];
    l->dados[i] = aluno;
    l->qntd++;
    return 1;
}

int inserir_final(Lista* l, struct aluno aluno){
    if (l == NULL || lista_cheia(l))
        return 0;
    l->dados[l->qntd] = aluno;
    l->qntd++;
    return 1;
}

int inserir_inicio(Lista* l, struct aluno aluno){
    if (l == NULL || lista_cheia(l))
        return 0;
    for (int i = l->qntd - 1; i >= 0; i--)
        l->dados[i + 1] = l->dados[i];
    l->dados[0] = aluno;
    l->qntd++;
    return 1;
}

int remover_final(Lista* l) {
    if (l == NULL || lista_vazia(l))
        return 0;
    l->qntd--;
    return 1;
}

int remover_inicio(Lista* l){
    if (l == NULL || lista_vazia(l))
        return 0;
    int i;
    for (i = 0; i < l->qntd - 1; i++)
        l->dados[i] = l->dados[i + 1];
    l->qntd--;
    return 1;
}

int remove_matricula(Lista* l, int matricula) {
    if (l == NULL || lista_vazia(l))
        return 0;
    int j, i = 0;
    while (i<l->qntd && l->dados[i].idade != matricula)
        i++;
    if (i == l->qntd)
        return 0;
    for (int k = i; k < l->qntd; k++)
        l->dados[k] = l->dados[k + 1];
    l->qntd--;
    return 1;
}
