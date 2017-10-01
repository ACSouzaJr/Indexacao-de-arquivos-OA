#include <stdlib.h>
#include<string.h>

struct IndicePrimario
{

	char chave_primaria[31];
	int nrr;

};

typedef struct IndicePrimario indice_primario;

void BuildHeap( indice_primario vetor[], int tamanho );
void Heapify( indice_primario vetor[], int i, int tamanho );
void HeapSort( indice_primario vetor[] );

void HeapSort( indice_primario vetor[]){

	int tamanho = sizeof(vetor) / sizeof(vetor[0]);
	indice_primario aux;

	BuildHeap( vetor, tamanho );

	for ( int i = tamanho-1; i>=0; --i ) //i - indice
	{
		//swap
		strcpy(aux.chave_primaria, vetor[0].chave_primaria);
		strcpy(vetor[0].chave_primaria, vetor[i].chave_primaria);
		strcpy(vetor[i].chave_primaria, aux.chave_primaria);

		Heapify( vetor, 0, i );
	}
}


void BuildHeap( indice_primario vetor[], int tamanho ){

	for (int i = tamanho/2 - 1; i>=0; --i)
		Heapify(vetor, i, tamanho);

}


void Heapify( indice_primario vetor[], int i, int tamanho ){

	int esquerda = 2*i+1;
	int direita = 2*i+2;
	int maior = i;
	indice_primario aux;

	if ( esquerda < tamanho && strcmp(vetor[esquerda].chave_primaria, vetor[maior].chave_primaria) > 0)
		maior = esquerda;

	if ( direita < tamanho && strcmp(vetor[direita].chave_primaria, vetor[maior].chave_primaria) > 0 )
		maior = direita;

	if ( maior != i ){
		//swap
		strcpy(aux.chave_primaria, vetor[i].chave_primaria);
		strcpy(vetor[i].chave_primaria, vetor[maior].chave_primaria);
		strcpy(vetor[maior].chave_primaria, aux.chave_primaria);

		Heapify( vetor, maior, tamanho );

	}
}



#include <stdio.h>


int main(int argc, char const *argv[])
{
	int n = 3;

	indice_primario vetor[3];

	strcpy(vetor[0].chave_primaria, "024312Leonardo");
    strcpy(vetor[2].chave_primaria, "031272Andreza");
    strcpy(vetor[1].chave_primaria, "035830Rogerio");

	HeapSort(vetor);

	for (int i=0; i<n; ++i){
	    vetor[i].chave_primaria[14] = '\0';
    	puts(vetor[i].chave_primaria);
   	}
	return 0;
}
