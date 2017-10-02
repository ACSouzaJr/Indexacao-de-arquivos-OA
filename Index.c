#include <Dados.h>
#include <stdlib.h>

Index* criaIndex(){
    Index *index;
    index = (Index*) malloc(sizeof(Index));
    index->tamanho = 0;
    index->flag_atualizacao = 0;
}


int insereIndex(Index *index, struct IndicePrimario indice){

    index->indice_primario[index->tamanho] = indice;

    index->tamanho++;
}

int removeIndex(Index *index, int posicao){

    for (int i = posicao+1; i < index->tamanho; ++i)
        index[i-1] = index[i];

    index->tamanho--;

}