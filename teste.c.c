#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dados.h"

Index* criaIndex();
int insereIndex(Index *index, struct IndicePrimario indice);

void AtualizaIndice( const char *arquivo, Index *index ){

    FILE *fp;

    int tamanho = index->tamanho;



    fp = fopen( arquivo, "w" );

    /*lista cresce verticalmente*/
    for ( int i = 0; i < tamanho; ++i )
    {
        //fwrite(&Index[i]->chave_primaria, sizeof(indice_primario), 1, fp);
        fprintf( fp, "%s\t", index->indice_primario[i].chave_primaria );
        fprintf( fp, "%d\n", index->indice_primario[i].nrr );
    }

    fclose(fp);
}

int main(int argc, char const *argv[])
{

    FILE *fp;

    fp = fopen( "lista1.txt", "r" );

    Index *index = criaIndex();

    registro_aluno registro;
    struct IndicePrimario indice;

    int i = 0;
    while( !feof(fp) ){

        fread(&registro.matric, sizeof(char), 7, fp);
        //fgetc(fp);
        fread(&registro.nome, sizeof(char), 41, fp);
        //fgetc(fp);
        fread(&registro.op, sizeof(char), 6, fp);
        //fgetc(fp);
        fread(&registro.curso, sizeof(char), 10, fp);
        //fgetc(fp);
        fread(&registro.turma, sizeof(char), 3, fp);
        fgetc(fp);


        /*  Mostrar na tela*/
        /*  Comentar matric se quiser espaco na string
        */
        registro.matric[6] = '\0';
        registro.nome[40]= '\0';
        registro.op[5]= '\0';
        registro.curso[9]= '\0';
        registro.turma[2]= '\0';

        printf("%s\t", registro.matric);
        printf("%s\t", registro.nome);
        printf("%s\t", registro.op);
        printf("%s\t", registro.curso);
        printf("%s\n", registro.turma);



        /*  Cria chave primaria*/
        strcpy(indice.chave_primaria, registro.matric);
        strncat(indice.chave_primaria, registro.nome, 24);
        indice.nrr = i;

        insereIndex(index, indice);

        printf("%s\n", indice.chave_primaria);

        ++i;


    }

    fclose(fp);

    AtualizaIndice("arquivo", index);



    return 0;
}