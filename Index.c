#include <Dados.h>
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
        index[i-1] = index[i];

    index->tamanho--;

}