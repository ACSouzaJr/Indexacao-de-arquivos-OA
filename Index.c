#include <Dados.h>
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
        index[i-1] = index[i];

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

    index_sec->indice_sec[index_sec->tamanho] = indice2;

    index_sec->tamanho++;
}

void RemoveIndexSecundario(Index2 *index_sec, int posicao){

    for (int i = posicao+1; i < index_sec->tamanho; ++i)
        index_sec[i-1] = index_sec[i];

    index_sec->tamanho--;

}

