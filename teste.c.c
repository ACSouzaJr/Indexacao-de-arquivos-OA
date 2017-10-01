#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    struct Registro
{

    char matric[7];
    char nome[41];
    char op[6];
    char curso[10];
    char turma[3];

};


typedef struct Registro registro_aluno;

    FILE *fp;

    fp = fopen( "lista1.txt", "r" );

    registro_aluno registro;

    char c;


        fread(&registro.matric, sizeof(char), 6, fp);
        fread(&c, sizeof(char), 1, fp);/*    espacos*/
        fread(&registro.nome, sizeof(char), 40, fp);
        fread(&c, sizeof(char), 1, fp);
        fread(&registro.op, sizeof(char), 4, fp);
        fread(&c, sizeof(char), 1, fp);
        fread(&registro.curso, sizeof(char), 9, fp);
        fread(&c, sizeof(char), 1, fp);
        fread(&registro.turma, sizeof(char), 2, fp);
        fread(&c, sizeof(char), 1, fp);




/*
    registro.matric[7] = '\0';
    registro.nome[41]= '\0';
    registro.op[6]= '\0';
    registro.curso[10]= '\0';
    registro.turma[3]= '\0';
*/
    printf("%s\n", registro.matric);
    printf("%s\n", registro.nome);
    printf("%s\n", registro.op);
    printf("%s\n", registro.curso);
    printf("%s\n", registro.turma);

    return 0;
}