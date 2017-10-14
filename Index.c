#include "Dados.h"
#include <stdio.h>
#include <stdlib.h>
#include "index.h"


Index1* CriaIndex(){
    Index1 *index;
    index = (Index1*) malloc(sizeof(Index1));
    index->tamanho = 0;
    index->flag_atualizacao = 0;

    return index;
}

void InsereIndex(Index1 *index, struct IndicePrimario indice1){

    index->indice_primario[index->tamanho] = indice1;

    index->tamanho++;
}

void RemoveIndex(Index1 *index, int posicao){

    for (int i = posicao+1; i < index->tamanho; ++i)
        index->indice_primario[i-1] = index->indice_primario[i];

    index->tamanho--;

}

Index2* CriaIndexSecundario(){
    Index2 *index_sec;
    index_sec = (Index2*) malloc(sizeof(Index2));
    index_sec->tamanho = 0;
    index_sec->flag_atualizacao = 0;

    return index_sec;
}

void InsereIndexSecundario(Index2 *index_sec, struct IndiceSecundario indice2){

    index_sec->indice_secundario[index_sec->tamanho] = indice2;

    index_sec->tamanho++;
}

void RemoveIndexSecundario(Index2 *index_sec, int posicao){

    for (int i = posicao+1; i < index_sec->tamanho; ++i)
        index_sec->indice_secundario[i-1] = index_sec->indice_secundario[i];

    index_sec->tamanho--;

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

