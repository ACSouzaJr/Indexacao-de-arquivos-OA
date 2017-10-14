#include <stdlib.h>
#include <string.h>
#include "Dados.h"

/*  Recebe como parametros o vetor de strings a ser ordenado
*   Retorna indiretamente o vetor ordenado
*/
void HeapSort( Index1 vetor[]){

    int tamanho = vetor->tamanho;
    struct IndicePrimario aux;

    BuildHeap( vetor, tamanho );

    for ( int i = tamanho-1; i>=0; --i ) //i - indice
    {
        //swap
        aux = vetor->indice_primario[0];
        vetor->indice_primario[0] = vetor->indice_primario[i];
        vetor->indice_primario[i] = aux;

        Heapify( vetor, 0, i );
    }
}


void BuildHeap( Index1 vetor[], int tamanho ){

    for (int i = tamanho/2 - 1; i>=0; --i)
        Heapify(vetor, i, tamanho);

}


void Heapify( Index1 vetor[], int i, int tamanho ){

    int esquerda = 2*i+1;
    int direita = 2*i+2;
    int maior = i;
    struct IndicePrimario aux;

    if ( esquerda < tamanho && strcmp(vetor->indice_primario[esquerda].chave_primaria, vetor->indice_primario[maior].chave_primaria) > 0)
        maior = esquerda;

    if ( direita < tamanho && strcmp(vetor->indice_primario[direita].chave_primaria, vetor->indice_primario[maior].chave_primaria) > 0 )
        maior = direita;

    if ( maior != i ){
        //swap
        aux = vetor->indice_primario[i];
        vetor->indice_primario[i] = vetor->indice_primario[maior];
        vetor->indice_primario[maior] = aux;

        Heapify( vetor, maior, tamanho );

    }
}


void HeapSortsec( Index2 vetor[]){

    int tamanho = vetor->tamanho;
    struct IndiceSecundario aux;

    BuildHeapsec( vetor, tamanho );

    for ( int i = tamanho-1; i>=0; --i ) //i - indice
    {
        //swap
        aux = vetor->indice_secundario[0];
        vetor->indice_secundario[0] = vetor->indice_secundario[i];
        vetor->indice_secundario[i] = aux;

        Heapifysec( vetor, 0, i );
    }
}


void BuildHeapsec( Index2 vetor[], int tamanho ){

    for (int i = tamanho/2 - 1; i>=0; --i)
        Heapifysec(vetor, i, tamanho);

}


void Heapifysec( Index2 vetor[], int i, int tamanho ){

    int esquerda = 2*i+1;
    int direita = 2*i+2;
    int maior = i;
    struct IndiceSecundario aux;

    if ( esquerda < tamanho && strcmp(vetor->indice_secundario[esquerda].chave_primaria, vetor->indice_secundario[maior].chave_primaria) > 0)
        maior = esquerda;

    if ( direita < tamanho && strcmp(vetor->indice_secundario[direita].chave_primaria, vetor->indice_secundario[maior].chave_primaria) > 0 )
        maior = direita;

    if ( maior != i ){
        //swap
        aux = vetor->indice_secundario[i];
        vetor->indice_secundario[i] = vetor->indice_secundario[maior];
        vetor->indice_secundario[maior] = aux;

        Heapifysec( vetor, maior, tamanho );

    }
}
