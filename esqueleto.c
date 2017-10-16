#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"
#include "Dados.h"
#include "index.h"
#include "funcoes.h"

/*	Falta comentar sobre os indices secundarios*/
/*	Refatorar repeticoes no codigo*/

/*
*	Index e o vetor de indices. Criar indicador de atualizacao?
*/
void Inclusao(registro_aluno registro, Index1 *index, Index2 *index2_op, Index2 *index2_turma, Pilha *PED){

	/*	Checar se houve mudancas anteriormente*/
	FILE *fp;

	struct IndicePrimario indice;

	if ( PED->qtd != 0){

	/*	Caso tenha ocorrido remocoes */
		/*
		*	Adiciona no lugar onde tem espaço? -> PED
		*	Adiciona o indice e usa sort
		*	flag de atualizacao ?
		*/

		/*	Registro*/

		int nrr = RemovePilha(PED);
		indice.nrr = nrr;

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
		fprintf(fp, "\n%-6.6s ", registro.matric);
		fprintf(fp, "%-40.40s ", registro.nome);
		fprintf(fp, "%-5.5s ", registro.op);
		fprintf(fp, "%-9.9s ", registro.curso);
		fprintf(fp, "%-2.2s\r", registro.turma);
        indice.nrr = index->tamanho;

	}


		fclose(fp);

		/* Indice Primario*/
		/*  Cria chave primaria*/
		char chave_primaria[31];
        strcpy(chave_primaria, registro.matric);
        strncat(chave_primaria, registro.nome, 24);

        strcpy(indice.chave_primaria, chave_primaria);

		InsereIndex(index, indice);
		HeapSort(index);


 		/*  Insere index secundario*/
 		struct IndiceSecundario indice_secundario;
        /*  OP*/
        strcpy(indice_secundario.chave_secundaria, registro.op);
        strcpy(indice_secundario.chave_primaria, chave_primaria);
        //strncat(indice_secundario.chave_primaria, registro.nome, 24);
        InsereIndexSecundario(index2_op, indice_secundario);

        /*  Turma*/
        strcpy(indice_secundario.chave_secundaria, registro.turma);
        strcpy(indice_secundario.chave_primaria, chave_primaria);
        //strncat(indice_secundario.chave_primaria, registro.nome, 24);
        InsereIndexSecundario(index2_turma, indice_secundario);

        HeapSortsec(index2_op);
        HeapSortsec(index2_turma);

		/*mostrar registro e index apos modificacao*/

		AtualizaIndice("indicelista1.ind", index);

        /*	Atualiza indeice secundario*/
        AtualizaIndiceSec("OP.ind", index2_op);
		AtualizaIndiceSec("turma.ind", index2_turma);

		//Como lidar corretamente com as flags_atualização
}


void Exclusao(Index1 *index, Index2 *index2_op, Index2 *index2_turma, Pilha *pi, VetorRegistro *v_registro){

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

	printf("\nEscolha o numero do registro a ser removido:\n");
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

	/*	Registro*/	//->entra n o arquivo e adiciona flag de remoção

	FILE *fp;
	fp = fopen("lista1.txt", "r+");
	fseek(fp, nrr*68, SEEK_SET);//A partir do começo //1 registro possui 68 chars
	fprintf(fp, "*");
	fclose(fp);

	InserePilha(pi, nrr);

	AtualizaIndice("indicelista1.ind", index);

	/*	Indice secundario*/
	/*	OP*/
	int chave_secundaria_pos = buscabinariasec( chave_primaria, index2_op, 0, index2_op->tamanho-1 );
	RemoveIndexSecundario(index2_op, chave_secundaria_pos);//baseado na chave primaria

	/*	Turma*/
	chave_secundaria_pos = buscabinariasec( chave_primaria, index2_turma, 0, index2_turma->tamanho-1 );
	RemoveIndexSecundario(index2_turma, chave_secundaria_pos);//baseado na chave primaria

	/*	Atualiza indice secundario*/
	AtualizaIndiceSec("OP.ind", index2_op);
	AtualizaIndiceSec("turma.ind", index2_turma);

}


void Atualizacao(Index1 *index, Index2 *index2_op, Index2 *index2_turma, VetorRegistro *v_registro){
	/*	Utilizar a chave primaria*/

	/*	Checar se muda chave primaria*/

	/*	Se mudar chave primaria*/
		/*
		*	Mudanca no campo indicado
		*	exclusao e adicao do index
		*/

		/*	Mostrar vetor registros*/
		Mostra_Registro(v_registro);

		printf("\nEscolha o numero do registro a ser atualizado:\n");
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

		/*	index 2*/
		int chave_secundaria_pos;
		struct IndiceSecundario indice_secundario;


	    /*	Escolha do campo*/
	    int campo;
	    char dado[50];
	    /*	Menu escolha do campo*/
	    printf("\n1 = MATRIC\n2 = NOME\n3 = OP\n4 = CURSO\n5 = TURMA\n");
		printf("\nQual o campo sera alterado? Escolha o campo de acordo com seu numero correspondente:\n");
		
		scanf("%d", &campo);
		getchar();

		printf("\nEscreva o valor do novo dado:\n");
		scanf("%[^\n]s", dado);

		char chave_primaria_nova[30];
		FILE *fp;

		switch(campo){

			case 1:
			/*	Mudar o vetor de registro*/
				strcpy(v_registro->registro[opcao-1].matric, dado);
			/*	Muda index -> geracao de chave primaria*/
				/* Indice Primario*/
				RemoveIndex(index, chave_primaria_pos);

				/*	gera novo indice a partir da posicao do registro*/
				strcpy(chave_primaria_nova, v_registro->registro[opcao-1].matric);
	    		strncat(chave_primaria_nova, v_registro->registro[opcao-1].nome, 24);

				strcpy(indice_primario.chave_primaria, chave_primaria_nova);

				InsereIndex(index, indice_primario);
				HeapSort(index);

			/*	Mudar index2*/
				chave_secundaria_pos = buscabinariasec( chave_primaria, index2_op, 0, index->tamanho-1 );
				strcpy(indice_secundario.chave_secundaria, index2_op->indice_secundario[chave_secundaria_pos].chave_secundaria);
				RemoveIndexSecundario(index2_op, chave_secundaria_pos);

				strcpy(indice_secundario.chave_primaria, chave_primaria_nova);

				InsereIndexSecundario(index2_op, indice_secundario);
				HeapSortsec(index2_op);
				/*	Turma*/
				chave_secundaria_pos = buscabinariasec( chave_primaria, index2_turma, 0, index->tamanho-1 );
				strcpy(indice_secundario.chave_secundaria, index2_turma->indice_secundario[chave_secundaria_pos].chave_secundaria);
				RemoveIndexSecundario(index2_turma, chave_secundaria_pos);

				strcpy(indice_secundario.chave_primaria, chave_primaria_nova);

				InsereIndexSecundario(index2_turma, indice_secundario);
				HeapSortsec(index2_turma);
			/*	Mudanca no arquivo de registros*/
				fp = fopen("lista1.txt", "r+");
				fseek(fp, nrr*68+0, SEEK_SET);//A partir do começo //1 registro possui 68 chars
				fprintf(fp, "%-6.6s", dado);
				fclose(fp);
				break;

			case 2:
			/*	Mudar o vetor de registro*/
				strcpy(v_registro->registro[opcao-1].nome, dado);
			/*	Muda index -> geracao de chave primaria*/
				/* Indice Primario*/
				RemoveIndex(index, chave_primaria_pos);

				/*	gera novo indice a partir da posicao do registro*/
				strcpy(chave_primaria_nova, v_registro->registro[opcao-1].matric);
	    		strncat(chave_primaria_nova, v_registro->registro[opcao-1].nome, 24);

				strcpy(indice_primario.chave_primaria, chave_primaria_nova);

				InsereIndex(index, indice_primario);
				HeapSort(index);

			/*	Mudar index2*/
				chave_secundaria_pos = buscabinariasec( chave_primaria, index2_op, 0, index->tamanho-1 );
				strcpy(indice_secundario.chave_secundaria, index2_op->indice_secundario[chave_secundaria_pos].chave_secundaria);
				RemoveIndexSecundario(index2_op, chave_secundaria_pos);

				strcpy(indice_secundario.chave_primaria, chave_primaria_nova);

				InsereIndexSecundario(index2_op, indice_secundario);
				HeapSortsec(index2_op);
				/*	Turma*/
				chave_secundaria_pos = buscabinariasec( chave_primaria, index2_turma, 0, index->tamanho-1 );
				strcpy(indice_secundario.chave_secundaria, index2_turma->indice_secundario[chave_secundaria_pos].chave_secundaria);
				RemoveIndexSecundario(index2_turma, chave_secundaria_pos);

				strcpy(indice_secundario.chave_primaria, chave_primaria_nova);

				InsereIndexSecundario(index2_turma, indice_secundario);
				HeapSortsec(index2_turma);

			/*	Mudanca no arquivo de registros*/
				fp = fopen("lista1.txt", "r+");
				fseek(fp, nrr*68+7, SEEK_SET);//A partir do começo //1 registro possui 68 chars
				fprintf(fp, "%-40.40s", dado);
				fclose(fp);
				break;

			case 3:
			/*	Mudar o vetor de registro*/
				strcpy(v_registro->registro[opcao-1].op, dado);
			/*	Lista invertida*/
				chave_secundaria_pos = buscabinariasec( chave_primaria, index2_op, 0, index->tamanho-1 );
				RemoveIndexSecundario(index2_op, chave_secundaria_pos);

				strcpy(indice_secundario.chave_primaria, chave_primaria);
				strcpy(indice_secundario.chave_secundaria, dado);

				InsereIndexSecundario(index2_op, indice_secundario);
				HeapSortsec(index2_op);
			/*	Mudanca no arquivo de registros*/
				fp = fopen("lista1.txt", "r+");
				fseek(fp, nrr*68+48, SEEK_SET);//A partir do começo //1 registro possui 68 chars
				fprintf(fp, "%-5.5s", dado);
				fclose(fp);
				break;
			case 4:
			/*	Mudar o vetor de registro*/
				strcpy(v_registro->registro[opcao-1].curso, dado);
			/*	Mudanca no arquivo de registros*/
				fp = fopen("lista1.txt", "r+");
				fseek(fp, nrr*68+54, SEEK_SET);//A partir do começo //1 registro possui 68 chars
				fprintf(fp, "%-9.9s", dado);
				fclose(fp);
				break;
			case 5:
			/*	Mudar o vetor de registro*/
				strcpy(v_registro->registro[opcao-1].turma, dado);
			/*	Lista invertida*/
				chave_secundaria_pos = buscabinariasec( chave_primaria, index2_turma, 0, index->tamanho-1 );
				RemoveIndexSecundario(index2_turma, chave_secundaria_pos);

				strcpy(indice_secundario.chave_primaria, chave_primaria);
				strcpy(indice_secundario.chave_secundaria, dado);

				InsereIndexSecundario(index2_turma, indice_secundario);
				HeapSortsec(index2_turma);
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

		/*	Atualiza indice secundario*/
		AtualizaIndiceSec("OP.ind", index2_op);
		AtualizaIndiceSec("turma.ind", index2_turma);

}