#include <stdio.h>
#include <stdlib.h>
#include "Dados.h"
#include "Pilha.h"
#include <string.h>
#include "index.h"

/*	Falta comentar sobre os indeces secundarios*/

/*
*	Index e o vetor de indices. Criar indicador de atualizacao?
*/
void Inclusao(registro_aluno registro, Index *index, Pilha *PED){

	/*	Checar se houve mudancas anteriormente*/
	if ( PED->qtd != 0){

	/*	Caso tenha ocorrido remocoes */
		/*
		*	Adiciona no lugar onde tem espaço? -> PED
		*	Adiciona o indice e usa sort
		*	flag de atualizacao ?
		*/

		/*	Registro*/
		FILE *fp;

		int nrr = RemovePilha(PED);

		fp = fopen("lista1.txt", "a");
		fseek(fp, nrr*sizeof(registro), SEEK_SET);

		fprintf(fp, "%s\t", registro.matric);
		fprintf(fp, "%s\t", registro.nome);
		fprintf(fp, "%s\t", registro.op);
		fprintf(fp, "%s\t", registro.curso);
		fprintf(fp, "%s\t", registro.turma);

		fclose(fp);

	}else{

	/*	Caso nao ocorreram remocoes anteriomente*/
		/*
		*	Adiciona no final do registro
		*	Adiciona o indice final e usa sort
		*	flag de atualizacao ?
		*/


		/*	Registro*/
		FILE *fp;
		fp = fopen("lista1.txt", "a");

		fprintf(fp, "%s\t", registro.matric);
		fprintf(fp, "%s\t", registro.nome);
		fprintf(fp, "%s\t", registro.op);
		fprintf(fp, "%s\t", registro.curso);
		fprintf(fp, "%s\t", registro.turma);

		fclose(fp);
	}

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

/*	Remove elemeno do vetor
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









