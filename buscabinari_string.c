#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct IndicePrimario
{

	char chave_primaria[31];
	int nrr;

};

typedef struct IndicePrimario indice_primario;


int buscabinaria(char *, indice_primario *, int, int);

int main(int argc, char const *argv[])
{

	indice_primario vetor[3];

	strcpy(vetor[0].chave_primaria, "024312Leonardo");
    strcpy(vetor[1].chave_primaria, "031272Andreza");
    strcpy(vetor[2].chave_primaria, "035830Rogerio");

	//int vetor[7] = {0, 2, 4, 6, 8, 10, 12};
	int result;
	char busca[] = "031272Andreza";

	result = buscabinaria(busca, vetor, 0, 2);
	printf("Local: v[%d] \n", result);

	return 0;
}

/*	Deve estar ordenado*/
int buscabinaria(char *busca, indice_primario *vetor, int inicio, int fim)
{
	if (strcmp(vetor[inicio+(fim-inicio)/2].chave_primaria, busca) == 0)
		return inicio+(fim-inicio)/2;

	else if (inicio == fim-1)
	{
		printf("Nao existe!\n");
		return 0;
	}
	else if (strcmp(vetor[(fim-inicio)/2].chave_primaria, busca) > 0)
		buscabinaria(busca, vetor, inicio, fim/2);

	else if (strcmp(vetor[inicio+(fim-inicio)/2].chave_primaria, busca) < 0)
		buscabinaria(busca, vetor, inicio+(fim-inicio)/2, fim);
}
