
/*	Falta comentar sobre os indeces secundarios*/

/*	
*	Index e o vetor de indices. Criar indicador de atualizacao?
*/
void Inclusao(registro_aluno registro, Pilha pi){

	/*	Checar se houve mudancas anteriormente*/
	if ( pi->qtd != 0){

	/*	Caso nao ocorreram remocoes anteriomente*/
		/*	
		*	Adiciona no final do registro
		*	Adiciona o indice e usa sort
		*	flag de atualizacao ?
		*/

		/* Indice Primario*/
		FIlE = *fp;

		int nrr = RemovePilha(pi);

		fp = fopen("Arq_registro", "a");
		fseek(fp, nrr*sizeof(registro), SEKK_SET);

		fprintf(fp, "%s\t", registro.matric);
		fprintf(fp, "%s\t", registro.nome);
		fprintf(fp, "%s\t", registro.op);
		fprintf(fp, "%s\t", registro.curso);
		fprintf(fp, "%s\t", registro.turma);

		fclose(fp);

		/*	Registro*/	//como implementar index -> registro .c e .h



	}
	/*	Caso tenha ocorrido remocoes */
		/*	
		*	Adiciona no lugar onde tem espaço? -> PED
		*	Adiciona o indice e usa sort
		*	flag de atualizacao ?
		*/
	
}


void Exclusao(char *chave_primaria, Pilha *pi){

	/*	
	*	Remove, adicionando flag de remoçao -> empilha PED
	*	remove indice
	*	flag de atualizacao ?
	*/


	/* Indice Primario*/
	chave_primaria_pos = BuscaBinaria(Index, chave_primaria[]);
	remover(chave_primaria_pos, Index);

	/*	Registro*/	//->entra dentro do arquivo e adiciona flag de remoção
	int nrr = Index[chave_primaria_pos].nrr //posiçao relativa do resgistro. 1 registro possui 67 chars
	File *fp;
	fp = fopen("resgistro", "a");
	fseek(fp, nrr*sizeof(registro), SEKK_SET);//A partir do começo
	fprintf(fp, "*");
	fclose(fp);

	InserePilha(pi, nrr);

}

/*	Remove elemeno do vetor*/
void remover (int posicao, int vetor[])
{
   
   tamanho = sizeof(vetor) / sizeof(vetor[0]);

   for (int i = posicao+1; i < tamanho; ++i)
   		vetor[i-1] = vetor[j];
   
}







void Atualizacao(){	/*	Utilizar a chave primaria*/

	/*	Checar se muda chave primaria*/

	/*	Se mudar chave primaria*/
		/*	
		*	Mudanca no campo indicado
		*	exclusao e adicao do index
		*/

	/*	Se nao mudar chave primaria*/
		/*	Fazer alteracao no campo*/
}