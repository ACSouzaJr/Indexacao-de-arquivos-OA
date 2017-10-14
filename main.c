#include <stdio.h>
#include <stdlib.h>
#include "Dados.h"
#include "Pilha.h"
#include "index.h"
#include "esqueleto.h"
#include "funcoes.h"

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
	Index2 *index2_op = CriaIndexSecundario();
	Index2 *index2_turma = CriaIndexSecundario();
	VetorRegistro *v_registro = CriaVRegistro();

	/*	Insercao no vetor correspondente*/
	CriarIndice(index, index2_op, index2_turma, PED, v_registro);



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
		printf("Escolha uma operacao\n");
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
				printf("Qual é a matrícula do novo aluno?\n");
				scanf("%s", registro.matric);
				printf("Qual é o nome do novo aluno?\n");
				scanf("%s", registro.nome);
				printf("Qual é o OP do novo aluno?\n");
				scanf("%s", registro.op);
				printf("Qual é o curso do novo aluno?\n");
				scanf("%s", registro.curso);
				printf("Qual é a turma do novo aluno?\n");
				scanf("%s", registro.turma);

				//mostrar antes da modificacao
				InsereVRegistro(v_registro, registro);

				Inclusao(registro, index, index2_op, index2_turma, PED);

				break;

			case 2:
				/*	Req 5) Excluir registro*/

				Exclusao(index, index2_op, index2_turma, PED, v_registro);
				
				break;

			case 3:
				/*	Atualizar registro
				*	Muda chave primaria
				*	nao muda chave primaria
				*/
				Atualizacao(index, index2_op, index2_turma, v_registro);	/*	Faco nem ideia como fazer */
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