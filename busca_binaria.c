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

int buscabinaria(char *busca, Index1 *vetor, int inicio, int fim)
{
    if (inicio > fim) return -1;
    else {
      int m = (inicio + fim)/2;
      if (strcmp(vetor->indice_primario[m].chave_primaria, busca) == 0) return m;
      if (strcmp(vetor->indice_primario[m].chave_primaria, busca) < 0)
         return buscabinaria(busca, vetor, m+1, fim);
      else
         return buscabinaria(busca, vetor, inicio, m-1);
    }
}


int buscabinariasec(char *busca, Index2 *vetor, int inicio, int fim)
{
    if (inicio > fim) return -1;
    else {
      int m = (inicio + fim)/2;
      if (strcmp(vetor->indice_secundario[m].chave_primaria, busca) == 0) return m;
      if (strcmp(vetor->indice_secundario[m].chave_primaria, busca) < 0)
         return buscabinariasec(busca, vetor, m+1, fim);
      else
         return buscabinariasec(busca, vetor, inicio, m-1);
    }
}
