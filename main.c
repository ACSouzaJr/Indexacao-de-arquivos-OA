#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{
	/*
	* Req 1) Imprimir todas as operacoes realizadas
	* Req 2) Cria arquivo de Indice
	*/

	/*	Criar Indice 	*/
	/*	Indices sao arrays de struct*/

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
		scanf("%d", escolha);
	
		/*	Req 3) Regravar indece apos manipulacao*/
	
		switch ( escolha ){
	
			case 1:
				/*	Req 4) Incluasao registro*/
				Inclusao();
				break;
	
			case 2:
				/*	Req 5) Excluir registro*/
				Exclusao();
				break;
	
			case 3:
				/*	Atualizar registro
				*	Muda chave primaria
				*	nao muda chave primaria
				*/
				Atualizacao();	/*	Faco nem ideia como fazer */
				break;
	
			case 4:
				return 0;
	
			default:
				printf("Nao tem essa opcao\n");
	

		}/*	Fim switch*/
	}/*	fim while*/
	
}