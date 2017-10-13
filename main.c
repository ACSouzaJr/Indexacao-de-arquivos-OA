#include <stdio.h>
#include <stdlib.h>
#include "Dados.h"
#include "Pilha.h"
#include "index.h"
#include "esqueleto.h"

/*	Como recuperar os dados quando o programa é reaberto*/

int main(int argc, char const *argv[])
{
	/*
	* Req 1) Imprimir todas as operacoes realizadas
	* Req 2) Cria arquivo de Indice
	*/

	/*	Criar Indice 	*/
	/*	Indices sao arrays de struct*/

	Pilha *PED = CriaPilha();
	Index1 *index = CriaIndex();

	CriarIndice(index);



	while( 1 ){

		/*	Menu	*/
		printf("***********************************\n");
		printf("Escolha a opercao desejada:\n");
		printf("1 - Inclusao de registro\n");
		printf("2 - Excluir registro\n");
		printf("3 - Atualizar registro\n");
		printf("4 - Sair\n");
		printf("***********************************\n");

		int escolha;
		scanf("%d", &escolha);
		getchar();

		/*	Req 3) Regravar indece apos manipulacao*/

		switch ( escolha ){

			case 1:
				/*	Req 4) Incluasao registro*/
				registro_aluno registro;

				/*	Forma melhor de pegar registros
				fgets(registro.matric, 6, stdin);
				fgets(registro.nome, 40, stdin);
				fgets(registro.op, 5, stdin);
				fgets(registro.curso, 9, stdin);
				fgets(registro.turma, 2, stdin);
				*/
				gets(registro.matric);
				gets(registro.nome);
				gets(registro.op);
				gets(registro.curso);
				gets(registro.turma);

				Inclusao(registro, index, PED);

				break;

			case 2:
				/*	Req 5) Excluir registro*/
				Exclusao(index, PED);
				break;

			case 3:
				/*	Atualizar registro
				*	Muda chave primaria
				*	nao muda chave primaria
				*/
				//Atualizacao();	/*	Faco nem ideia como fazer */
				break;

			case 4:
				return 0;
				break;

			default:
				printf("Nao tem essa opcao\n");


		fflush(stdin);
		}/*	Fim switch*/
	}/*	fim while*/

}