#include <stdio.h>
#include <stdlib.h>
#include "Dados.h"
#include "Pilha.h"
#include "index.h"
#include "esqueleto.h"
#include "funcoes.h"

/*	Como recuperar os dados quando o programa é reaberto*/

int main()
{
	/*
	* Req 1) Imprimir todas as operacoes realizadas
	* Req 2) Cria arquivo de Indice
	*/

	/*	Criar Indice 	*/
	/*	Indices sao arrays de struct*/

	Pilha *PED = CriaPilha();
	Index1 *index = CriaIndex();
	Index2 *index2_op = CriaIndexSecundario();
	Index2 *index2_turma = CriaIndexSecundario();
	VetorRegistro *v_registro = CriaVRegistro();

	/*	Insercao no vetor correspondente*/
	CriarIndice(index, index2_op, index2_turma, PED, v_registro);



	while( 1 ){
		
		/*printf("***********************************\n");
		printf("1 - Arquivo 1\n");
		printf("2 - Arquivo 2\n");
		printf("***********************************\n");

		int arquivos;
		printf("Escolha qual arquivo deve ser alterado:\n");
		scanf("%d", &arquivos);
		getchar();*/


		/*	Menu  */
		printf("***********************************\n");
		printf("1 - Inclusao de registro\n");
		printf("2 - Excluir registro\n");
		printf("3 - Atualizar registro\n");
		printf("4 - Sair\n");
		printf("***********************************\n");

		int escolha;
		printf("Escolha a operacao desejada:\n");
		scanf("%d", &escolha);
		getchar();

		/*	Req 3) Regravar indece apos manipulacao*/

		switch ( escolha ){

			case 1:
				/*	Req 4) Incluasao registro*/
				registro_aluno registro;

				printf("Qual é a matrícula do novo aluno?\n");
				scanf("%[^\n]s", registro.matric);
				getchar();
				printf("Qual é o nome do novo aluno?\n");
				scanf("%[^\n]s", registro.nome);
				getchar();
				printf("Qual é o OP do novo aluno?\n");
				scanf("%[^\n]s", registro.op);
				getchar();
				printf("Qual é o curso do novo aluno?\n");
				scanf("%[^\n]s", registro.curso);
				getchar();
				printf("Qual é a turma do novo aluno?\n");
				scanf("%[^\n]s", registro.turma);
				getchar();
				//mostrar antes da modificacao

				printf("Antes de adicionar o registro:\n");
				Mostra_Index(index);


				InsereVRegistro(v_registro, registro);

				Inclusao(registro, index, index2_op, index2_turma, PED);

				printf("\nDepois de adicionar o registro:\n");
				Mostra_Index(index);
				printf("\n");

				break;

			case 2:
				/*	Req 5) Excluir registro*/

				printf("Antes de remover o registro:\n");
				Mostra_Index(index);

				Exclusao(index, index2_op, index2_turma, PED, v_registro);

				printf("\nDepois de remover o registro:\n");
				Mostra_Index(index);
				printf("\n");

				break;

			case 3:
				/*	Atualizar registro
				*	Muda chave primaria
				*	nao muda chave primaria
				*/

				printf("Antes de atualizar o registro:\n");
				Mostra_Index(index);

				Atualizacao(index, index2_op, index2_turma, v_registro);

				printf("\nDepois de atualizar o registro:\n");
				Mostra_Index(index);
				printf("\n");
				
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