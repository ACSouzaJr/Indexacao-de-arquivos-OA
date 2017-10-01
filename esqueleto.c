
/*	Falta comentar sobre os indeces secundarios*/

/*
*	Index e o vetor de indices. Criar indicador de atualizacao?
*/
void Inclusao(registro_aluno registro, Pilha PED){

	/*	Checar se houve mudancas anteriormente*/
	if ( PED->qtd != 0){

	/*	Caso tenha ocorrido remocoes */
		/*
		*	Adiciona no lugar onde tem espaço? -> PED
		*	Adiciona o indice e usa sort
		*	flag de atualizacao ?
		*/

		/*	Registro*/
		FIlE = *fp;

		int nrr = RemovePilha(PED);

		fp = fopen("Arq_registro", "a");
		fseek(fp, nrr*sizeof(registro), SEKK_SET);

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
		FIlE = *fp;
		fp = fopen("Arq_registro", "a");

		fprintf(fp, "%s\t", registro.matric);
		fprintf(fp, "%s\t", registro.nome);
		fprintf(fp, "%s\t", registro.op);
		fprintf(fp, "%s\t", registro.curso);
		fprintf(fp, "%s\t", registro.turma);

		fclose(fp);
	}

		/* Indice Primario*/
		insereIndex(index, indice);
		HeapSort(index);

		/*	Indice Secundario*/
		insereIndexSec(indexsec, indice_sec);
		HeapSort(indexsec);


		AtualizaIndice("nome_arquivo", index);

		//Como lidar corretamente com as flags_atuaização
}


void Exclusao(char *chave_primaria, Pilha *pi){

	/*
	*	Remove, adicionando flag de remoçao -> empilha PED
	*	remove indice
	*	flag de atualizacao ?
	*/


	/* Indice Primario*/
	chave_primaria_pos = BuscaBinaria(index, chave_primaria[]);
	removeindex(index, chave_primaria_pos);

	/*	Registro*/	//->entra dentro do arquivo e adiciona flag de remoção
	int nrr = index[chave_primaria_pos].nrr //posiçao relativa do resgistro. 1 registro possui 67 chars
	File *fp;
	fp = fopen("resgistro", "a");
	fseek(fp, nrr*sizeof(registro), SEKK_SET);//A partir do começo
	fprintf(fp, "*");
	fclose(fp);

	InserePilha(pi, nrr);

	AtualizaIndice("arquivo", index);

	/*	Indice secundario*/
		//precisa remover o indice secundario.

}

/*	Remove elemeno do vetor
void remover (int posicao, int vetor[])
{

   tamanho = sizeof(vetor) / sizeof(vetor[0]);

   for (int i = posicao+1; i < tamanho; ++i)
   		vetor[i-1] = vetor[j];

}

*/





void Atualizacao(){	/*	Utilizar a chave primaria*/

	/*	Checar se muda chave primaria*/

	/*	Se mudar chave primaria*/
		/*
		*	Mudanca no campo indicado
		*	exclusao e adicao do index
		*/

		/*	mostrar registro*/

		/*	Indice*/
		int matricula;

		printf("Qual a :\n");
		scanf("%d", matricula);

		int chave_primaria_pos = BuscaBinaria(chave_primaria);
		removeIndex(index, chave_primaria_pos);
		/*	Informar nova chave primaria*/
		//fazer nova chave

		insereIndex(index, chave_primaria);
		HeapSort(index);

		/* Registro*/





	/*	Se nao mudar chave primaria*/
		/*	Fazer alteracao no campo*/

}



	/*	informa o registro a ser modificado*/
switch ( opcao )

	case 'M':
	case 'N':

	1 -> index[1]
	2
	3










