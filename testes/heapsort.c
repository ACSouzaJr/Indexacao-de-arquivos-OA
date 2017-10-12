#include <stdlib.h>

void BuildHeap( int vetor[], int tamanho );
void Heapify( int vetor[], int i, int tamanho );
void HeapSort( int vetor[] );

void HeapSort( int vetor[]){

	int tamanho = sizeof(vetor) / sizeof(vetor[0]);
	int aux;

	BuildHeap( vetor, tamanho );

	for ( int i = tamanho-1; i>=0; --i ) //i - indice
	{
		//swap
		aux = vetor[0];
		vetor[0] = vetor[i];
		vetor[i] = aux;

		Heapify( vetor, 0, i );
	}
}


void BuildHeap( int vetor[], int tamanho ){

	for (int i = tamanho/2 - 1; i>=0; --i)
		Heapify(vetor, i, tamanho);

}


void Heapify( int vetor[], int i, int tamanho ){

	int esquerda = 2*i+1;
	int direita = 2*i+2;
	int maior = i;
	int aux;

	if ( esquerda < tamanho && vetor[esquerda] > vetor[maior] )
		maior = esquerda;

	if ( direita < tamanho && vetor[direita] > vetor[maior] )
		maior = direita;

	if ( maior != i ){
		//swap
		aux = vetor[i];
		vetor[i] = vetor[maior];
		vetor[maior] = aux;

		Heapify( vetor, maior, tamanho );

	}
}



#include <stdio.h>

int main(int argc, char const *argv[])
{
	int vetor[] = {1,12,9,5,6,10};
	int n = sizeof(vetor) / sizeof(int);

	HeapSort(vetor);

	for (int i=0; i<n; ++i){
    	printf("%d\n", vetor[i]);
   	}
	return 0;
}