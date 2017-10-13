#include <stdio.h>
#include <stdlib.h>
#include "Dados.h"
#include "Pilha.h"
#include <string.h>
#include "index.h"
#include "lista.h"

/*	Falta comentar sobre os indices secundarios*/

/*
*	Index e o vetor de indices. Criar indicador de atualizacao?
*/
void Inclusao(registro_aluno registro, Index *index, Pilha *PED){

	/*	Checar se houve mudancas anteriormente*/
	FILE *fp;

	if ( PED->qtd != 0){

	/*	Caso tenha ocorrido remocoes */
		/*
		*	Adiciona no lugar onde tem espaço? -> PED
		*	Adiciona o indice e usa sort
		*	flag de atualizacao ?
		*/

		/*	Registro*/

		int nrr = RemovePilha(PED);

		fp = fopen("lista1.txt", "a");
		fseek(fp, nrr*sizeof(registro), SEEK_SET);

	}else{

	/*	Caso nao ocorreram remocoes anteriomente*/
		/*
		*	Adiciona no final do registro
		*	Adiciona o indice final e usa sort
		*	flag de atualizacao ?
		*/


		/*	Registro*/
		fp = fopen("lista1.txt", "a");
	}

		/*	Escrita no arquivo*/
		fprintf(fp, "%-6.6s ", registro.matric);
		fprintf(fp, "%-40.40s ", registro.nome);
		fprintf(fp, "%-5.5s ", registro.op);
		fprintf(fp, "%-9.9s ", registro.curso);
		fprintf(fp, "%-2.2s\n", registro.turma);

		fclose(fp);

		/* Indice Primario*/
		/*  Cria chave primaria*/	//fazer funcao cria indice primerio
		struct IndicePrimario indice;
        strcpy(indice.chave_primaria, registro.matric);
        strncat(indice.chave_primaria, registro.nome, 24);
        indice.nrr = index->tamanho+1;

		InsereIndex(index, indice);
		HeapSort(index);

		/*	Indice Secundario*/
		//InsereIndexSec(indexsec, indice_sec);
		//HeapSort(indexsec);


		AtualizaIndice("indicelista1.ind", index);

		//Como lidar corretamente com as flags_atuaização
}


//void Exclusao(Index *index, Pilha *pi){

	/*
	*	Remove, adicionando flag de remoçao -> empilha PED
	*	remove indice
	*	flag de atualizacao ?
	*/


	/* Indice Primario*/
//	chave_primaria_pos = BuscaBinaria( index->chave_primaria[], index, 0, index->tamanho-1);
//	removeindex(index, chave_primaria_pos);

	/*	Registro*/	//->entra dentro do arquivo e adiciona flag de remoção
//	int nrr = index[chave_primaria_pos].nrr //posiçao relativa do resgistro. 1 registro possui 67 chars
//	FILE *fp;
//	fp = fopen("resgistro", "a");
//	fseek(fp, nrr*sizeof(registro), SEEK_SET);//A partir do começo
//	fprintf(fp, "*");
//	fclose(fp);

//	InserePilha(pi, nrr);

//	AtualizaIndice("arquivo", index);

	/*	Indice secundario*/
		//precisa remover o indice secundario.

//}

/*	Remove elemento do vetor
void remover (int posicao, int vetor[])
{

   tamanho = sizeof(vetor) / sizeof(vetor[0]);

   for (int i = posicao+1; i < tamanho; ++i)
   		vetor[i-1] = vetor[j];

}

*/





//void Atualizacao(){
	/*	Utilizar a chave primaria*/

	/*	Checar se muda chave primaria*/

	/*	Se mudar chave primaria*/
		/*
		*	Mudanca no campo indicado
		*	exclusao e adicao do index
		*/

		/*	mostrar registro*/

		/*	Indice*/
		//int matricula;

//		printf("Qual a :\n");
//		scanf("%d", matricula);

//		int chave_primaria_pos = BuscaBinaria(chave_primaria);
//		RemoveIndex(index, chave_primaria_pos);

		/*	Informar nova chave primaria*/
		//fazer nova chave

//		InsereIndex(index, chave_primaria);
//		HeapSort(index);

		/* Registro*/





	/*	Se nao mudar chave primaria*/
		/*	Fazer alteracao no campo*/

//}


	/*	informa o registro a ser modificado*/
/*switch ( opcao )

	case 'M':
	case 'N':

	1 -> index[1]
	2
	3
*/









