#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dados.h"
#include "Pilha.h"
#include "index.h"

/*	Falta comentar sobre os indeces secundarios*/

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

		fp = fopen("lista1.txt", "r+");
		fseek(fp, nrr*68, SEEK_SET);

		/*	Escrita no arquivo*/
		fprintf(fp, "%-6.6s ", registro.matric);
		fprintf(fp, "%-40.40s ", registro.nome);
		fprintf(fp, "%-5.5s ", registro.op);
		fprintf(fp, "%-9.9s ", registro.curso);
		fprintf(fp, "%-2.2s", registro.turma);

	}else{

	/*	Caso nao ocorreram remocoes anteriomente*/
		/*
		*	Adiciona no final do registro
		*	Adiciona o indice final e usa sort
		*	flag de atualizacao ?
		*/


		/*	Registro*/
		fp = fopen("lista1.txt", "a");
		/*	Escrita no arquivo*/
		fprintf(fp, "%-6.6s ", registro.matric);
		fprintf(fp, "%-40.40s ", registro.nome);
		fprintf(fp, "%-5.5s ", registro.op);
		fprintf(fp, "%-9.9s ", registro.curso);
		fprintf(fp, "%-2.2s\n", registro.turma);

	}


		fclose(fp);

		/* Indice Primario*/
		/*  Cria chave primaria*/	//fazer funcao cria indice primerio
		struct IndicePrimario indice;
        strcpy(indice.chave_primaria, registro.matric);
        strncat(indice.chave_primaria, registro.nome, 24);
        indice.nrr = index->tamanho+1;

		InsereIndex(index, indice);
		HeapSort(index);

		//mostrar registro e index apos modificacao

		AtualizaIndice("indicelista1.ind", index);

		/*	Indice Secundario*/
		//InsereIndexSec(indexsec, indice_sec);
		//HeapSort(indexsec);

		//Como lidar corretamente com as flags_atuaização
}


void Exclusao(Index *index, Pilha *pi, VetorRegistro *v_registro){

	/*
	*	Remove, adicionando flag de remoçao -> empilha PED
	*	remove indice
	*	flag de atualizacao ?
	*/

	/*	vetor com todos os registros inicialmente para mostrar na tela
	*	como forma de achar a chave primaria
	*/

	/*	Mostrar vetor registros*/
	Mostra_Registro(v_registro);

	int opcao;
	scanf("%d", &opcao);

	/*	Deduzir a chave primaria do indice*/
	char chave_primaria[30];
	strcpy(chave_primaria, v_registro->registro[opcao-1].matric);
    strncat(chave_primaria, v_registro->registro[opcao-1].nome, 24);

    RemoveVRegistro(v_registro, opcao-1);


	/* Indice Primario*/
	int chave_primaria_pos = buscabinaria( chave_primaria, index, 0, index->tamanho-1 );
	int nrr = index->indice_primario[chave_primaria_pos].nrr; //posiçao relativa do resgistro.

	RemoveIndex(index, chave_primaria_pos);

	/*	Registro*/	//->entra dentro do arquivo e adiciona flag de remoção

	FILE *fp;
	fp = fopen("lista1.txt", "r+");
	fseek(fp, nrr*68, SEEK_SET);//A partir do começo //1 registro possui 68 chars
	fprintf(fp, "*");
	fclose(fp);

	InserePilha(pi, nrr);

	AtualizaIndice("indicelista1.ind", index);

	/*	Indice secundario*/
		//removeIndexSec(indexsec, indice_sec);//baseado na chave primaria

}


void Atualizacao(Index *index, VetorRegistro *v_registro){
	/*	Utilizar a chave primaria*/

	/*	Checar se muda chave primaria*/

	/*	Se mudar chave primaria*/
		/*
		*	Mudanca no campo indicado
		*	exclusao e adicao do index
		*/

		/*	Mostrar vetor registros*/
		Mostra_Registro(v_registro);

		int opcao;
		scanf("%d", &opcao);

		/*	Deduzir a chave primaria do indice*/
		char chave_primaria[30];
		strcpy(chave_primaria, v_registro->registro[opcao-1].matric);
	    strncat(chave_primaria, v_registro->registro[opcao-1].nome, 24);

	    /*	posicao do registro na index*/
		int chave_primaria_pos = buscabinaria( chave_primaria, index, 0, index->tamanho-1 );
		int nrr = index->indice_primario[chave_primaria_pos].nrr; //posiçao relativa do resgistro.
		struct IndicePrimario indice_primario;
		indice_primario.nrr = nrr;

	    /*	Escolha do campo*/
	    int campo;
	    char dado[50];
		printf("Qual o campo?\n");
		scanf("%d",&campo);
		getchar();
		printf("Novo dado\n");
		gets(dado);

		char chave_primaria_nova[30];
				FILE *fp;

		switch(campo){

			case 1:
			/*	Mudar o vetor de registro*/
				strcat(v_registro->registro[opcao-1].matric, dado);
			/*	Muda index -> geracao de chave primaria*/
				/* Indice Primario*/
				RemoveIndex(index, chave_primaria_pos);

				/*	gera novo indice a partir da posicao do registro*/
				strcpy(chave_primaria, v_registro->registro[opcao-1].matric);
	    		strncat(chave_primaria, v_registro->registro[opcao-1].nome, 24);

				strcat(indice_primario.chave_primaria, chave_primaria_nova);

				InsereIndex(index, indice_primario);
				HeapSort(index);

			/*	Mudanca no arquivo de registros*/
				fp = fopen("lista1.txt", "r+");
				fseek(fp, nrr*68+0, SEEK_SET);//A partir do começo //1 registro possui 68 chars
				fprintf(fp, "%-6.6s", dado);
				fclose(fp);
				break;

			case 2:
			/*	Mudar o vetor de registro*/
				strcat(v_registro->registro[opcao-1].nome, dado);
			/*	Muda index -> geracao de chave primaria*/
				/* Indice Primario*/
				RemoveIndex(index, chave_primaria_pos);

				strcpy(chave_primaria, v_registro->registro[opcao-1].matric);
	    		strncat(chave_primaria, v_registro->registro[opcao-1].nome, 24);

				strcat(indice_primario.chave_primaria, chave_primaria_nova);

				InsereIndex(index, indice_primario);
				HeapSort(index);
			/*	Mudanca no arquivo de registros*/
				fp = fopen("lista1.txt", "r+");
				fseek(fp, nrr*68+7, SEEK_SET);//A partir do começo //1 registro possui 68 chars
				fprintf(fp, "%-40.40s", dado);
				fclose(fp);
				break;

			case 3:
			/*	Mudar o vetor de registro*/
			/*	Lista invertida*/
				//removeIndexSec();
				//adiconasec();
				//HeapSort();
			/*	Mudanca no arquivo de registros*/
				fp = fopen("lista1.txt", "r+");
				fseek(fp, nrr*68+48, SEEK_SET);//A partir do começo //1 registro possui 68 chars
				fprintf(fp, "%-5.5s", dado);
				fclose(fp);
				break;
			case 4:
			/*	Mudar o vetor de registro*/
			/*	Mudanca no arquivo de registros*/
				fp = fopen("lista1.txt", "r+");
				fseek(fp, nrr*68+54, SEEK_SET);//A partir do começo //1 registro possui 68 chars
				fprintf(fp, "%-9.9s", dado);
				fclose(fp);
				break;
			case 5:
			/*	Mudar o vetor de registro*/
			/*	Lista invertida*/
			/*	Mudanca no arquivo de registros*/
				fp = fopen("lista1.txt", "r+");
				fseek(fp, nrr*68+64, SEEK_SET);//A partir do começo //1 registro possui 68 chars
				fprintf(fp, "%-2.2s", dado);
				fclose(fp);
				break;
			default:
				printf("NAo tem esse campo\n");
				break;

		}

		AtualizaIndice("indicelista1.ind", index);

		//int chave_primaria_pos = BuscaBinaria(chave_primaria);
		//RemoveIndex(index, chave_primaria_pos);

		/*	Informar nova chave primaria*/
		//fazer nova chave

		//InsereIndex(index, chave_primaria);
		//HeapSort(index);

		/* Registro*/





	/*	Se nao mudar chave primaria*/
		/*	Fazer alteracao no campo*/

}


	/*	informa o registro a ser modificado*/
/*switch ( opcao )

	case 'M':
	case 'N':

	1 -> index[1]
	2
	3
*/