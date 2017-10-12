#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dados.h"

/*  Busca binaria*/
//int buscabinaria(char *busca, Index vetor[], int inicio, int fim);

/*  Vetor deve estar ordenado*/
/*  Recebe como parametros o valor a ser buscado o inicio e o fim do vetor
*   Retorna a posicao do valor buscado ou zero se nao foi achado
*/

int buscabinaria(char *busca, Index *vetor, int inicio, int fim)
{
    if (strcmp(vetor->indice_primario[inicio+(fim-inicio)/2].chave_primaria, busca) == 0)
        return inicio+(fim-inicio)/2;

    else if (inicio == fim-1)
    {
        printf("Nao existe!\n");
        return 0;
    }
    else if (strcmp(vetor->indice_primario[(fim-inicio)/2].chave_primaria, busca) > 0)
        buscabinaria(busca, vetor, inicio, fim/2);

    else if (strcmp(vetor->indice_primario[inicio+(fim-inicio)/2].chave_primaria, busca) < 0)
        buscabinaria(busca, vetor, inicio+(fim-inicio)/2, fim);
}