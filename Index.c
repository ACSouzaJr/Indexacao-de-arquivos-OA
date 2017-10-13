#include "Dados.h"
#include <stdio.h>
#include <stdlib.h>
#include "index.h"




Index* CriaIndex(){
    Index *index;
    index = (Index*) malloc(sizeof(Index));
    index->tamanho = 0;
    index->flag_atualizacao = 0;

    return index;
}


void InsereIndex(Index *index, struct IndicePrimario indice){

    index->indice_primario[index->tamanho] = indice;

    index->tamanho++;
}

void RemoveIndex(Index *index, int posicao){

    for (int i = posicao+1; i < index->tamanho; ++i)
        index->indice_primario[i-1] = index->indice_primario[i];

    index->tamanho--;

}



VetorRegistro* CriaVRegistro(){

    VetorRegistro *index;
    index = (VetorRegistro*) malloc(sizeof(VetorRegistro));
    index->tamanho = 0;

    return index;
}


void InsereVRegistro(VetorRegistro *index, registro_aluno indice){

    index->registro[index->tamanho] = indice;

    index->tamanho++;
}

void RemoveVRegistro(VetorRegistro *index, int posicao){

    for (int i = posicao+1; i < index->tamanho; ++i)
        index->registro[i-1] = index->registro[i];

    index->tamanho--;

}

void Mostra_Registro(VetorRegistro *v_registro){

    //Mostra na tela o conteudo dos registro e index

    printf("\n");

    for (int i = 0; i < v_registro->tamanho; ++i)
    {
        printf("%d\t", i+1);
        printf("%s\t", v_registro->registro[i].matric);
        printf("%s\t", v_registro->registro[i].nome);
        printf("%s\t", v_registro->registro[i].op);
        printf("%s\t", v_registro->registro[i].curso);
        printf("%s\n", v_registro->registro[i].turma);
    }

/*
    for (int i = 0; i < index->tamanho; ++i)
    {
        printf("%s\t", index[i]->indice.chave_primaria);
        printf("%s\n", index[i]->indice.nrr);
    }
*/

}