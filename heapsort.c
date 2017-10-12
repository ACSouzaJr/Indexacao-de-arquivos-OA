#include <stdlib.h>
#include <string.h>
#include "Dados.h"

/*  Recebe como parametros o vetor de strings a ser ordenado
*   Retorna indiretamente o vetor ordenado
*/
void HeapSort( Index vetor[]){

    int tamanho = vetor->tamanho;
    struct IndicePrimario aux;

    BuildHeap( vetor, tamanho );

    for ( int i = tamanho-1; i>=0; --i ) //i - indice
    {
        //swap
        strcpy(aux.chave_primaria, vetor->indice_primario[0].chave_primaria);
        strcpy(vetor->indice_primario[0].chave_primaria, vetor->indice_primario[i].chave_primaria);
        strcpy(vetor->indice_primario[i].chave_primaria, aux.chave_primaria);

        Heapify( vetor, 0, i );
    }
}


void BuildHeap( Index vetor[], int tamanho ){

    for (int i = tamanho/2 - 1; i>=0; --i)
        Heapify(vetor, i, tamanho);

}


void Heapify( Index vetor[], int i, int tamanho ){

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
        strcpy(aux.chave_primaria, vetor->indice_primario[i].chave_primaria);
        strcpy(vetor->indice_primario[i].chave_primaria, vetor->indice_primario[maior].chave_primaria);
        strcpy(vetor->indice_primario[maior].chave_primaria, aux.chave_primaria);

        Heapify( vetor, maior, tamanho );

    }
}
