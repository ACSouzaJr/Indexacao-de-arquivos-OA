#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"
#include "Dados.h"
#include "index.h"
#include "funcoes.h"


/*
*	Reescreve os indices primarios no arquivo de indices
*	Apaga o arquivo e reescreve
*/

void AtualizaIndice( const char *arquivo, Index1 *index ){

	FILE *fp;

	int tamanho = index->tamanho;



	fp = fopen( arquivo, "w" );

	/*lista cresce verticalmente*/
	for ( int i = 0; i < tamanho; ++i )
	{
		fprintf( fp, "%-30.30s ", index->indice_primario[i].chave_primaria );
		fprintf( fp, "%d\n", index->indice_primario[i].nrr );
	}

	fclose(fp);
}

void AtualizaIndiceSec( const char *arquivo, Index2 *index_sec ){

    FILE *fp;

    int tamanho = index_sec->tamanho;



    fp = fopen( arquivo, "w" );

    /*lista cresce verticalmente*/
    for ( int i = 0; i < tamanho; ++i )
    {
        fprintf( fp, "%-30.30s\t", index_sec->indice_secundario[i].chave_primaria );
        fprintf( fp, "%-5.5s\n", index_sec->indice_secundario[i].chave_secundaria );
    }

    fclose(fp);
}


/*  Checar se o registro possui * no comeco se sim adiciona na ped
*/

void CriarIndice(Index1 *index, Index2 *index2_op, Index2 *index2_turma, Pilha *PED, VetorRegistro *v_registro){

	FILE *fp;

    fp = fopen( "lista1.txt", "r" );


    registro_aluno registro;
    struct IndicePrimario indice_primario;
    struct IndiceSecundario indice_secundario;
    char chave_primaria[31];


    int i = 0;
    while( !feof(fp) ){

        fread(&registro.matric, sizeof(char), 7, fp);
        fread(&registro.nome, sizeof(char), 41, fp);
        fread(&registro.op, sizeof(char), 6, fp);
        fread(&registro.curso, sizeof(char), 10, fp);
        fread(&registro.turma, sizeof(char), 3, fp);
        fgetc(fp);

        if( registro.matric[0] == '*')
            InserePilha(PED, i);
        else{

        /*  Mostrar na tela*/
        /*  Comentar matric se quiser espaco na string
        */
        registro.matric[6] = '\0';
        registro.nome[40]= '\0';
        registro.op[5]= '\0';
        registro.curso[9]= '\0';
        registro.turma[2]= '\0';

        /*printf("%s\t", registro.matric);
        printf("%s\t", registro.nome);
        printf("%s\t", registro.op);
        printf("%s\t", registro.curso);
        printf("%s\n", registro.turma);*/




        /*  Cria chave primaria*/
        strcpy(chave_primaria, registro.matric);
        strncat(chave_primaria, registro.nome, 24);

        strcpy(indice_primario.chave_primaria, chave_primaria);
        //strncat(indice_primario.chave_primaria, registro.nome, 24);
        indice_primario.nrr = i;

        /*  Insere index primario*/
        InsereIndex(index, indice_primario);
        /*  Insere vetor registro*/
        InsereVRegistro(v_registro, registro);

        /*  Insere index secundario*/
        /*  OP*/
        strcpy(indice_secundario.chave_secundaria, registro.op);
        strcpy(indice_secundario.chave_primaria, chave_primaria);
        InsereIndexSecundario(index2_op, indice_secundario);


        /*  Turma*/
        strcpy(indice_secundario.chave_secundaria, registro.turma);
        strcpy(indice_secundario.chave_primaria, chave_primaria);
        InsereIndexSecundario(index2_turma, indice_secundario);


        //printf("%s\n", indice_primario.chave_primaria);
        }

        ++i;

    }

    fclose(fp);

    HeapSort(index);
    HeapSortsec(index2_op);
    HeapSortsec(index2_turma);
    AtualizaIndice("indicelista1.ind", index);
    AtualizaIndiceSec("OP.ind", index2_op);
    AtualizaIndiceSec("turma.ind", index2_turma);

}
