/*
*	Reescreve os indices primarios no arquivo de indices
*	Apaga o arquivo e reescreve
*/

void AtualizaIndice( const char *arquivo, indice_primario *Index ){

	FILE *fp;

	int tamanho = Index->tamanho;



	fp = fopen( "arquivo", "w" );

	/*lista cresce verticalmente*/
	for ( int i = 0; i < tamanho; ++i )
	{
		//fwrite(&Index[i]->chave_primaria, sizeof(indice_primario), 1, fp);
		fprintf( fp, "%s\t", Index->indice_primario[i].chave_primaria );
		fprintf( fp, "%d\n", Index->indice_primario[i].nrr );
	}

	fclose(fp);
}


/*	NAO funciona*/
void CriarIndice( const char *arquivo ){

	FILE *fp;

	fp = fopen( "lista1.txt", "r" );

	registro_aluno registro;

	char c;

	while( !feof(fp) ){

		fread(&registro.matric, sizeof(char), 6, fp);
		fread(c, sizeof(char), 1, fp);/*	espacos*/
		fread(&registro.nome, sizeof(char), 40, fp);
		fread(c, sizeof(char), 1, fp);
		fread(&registro.op, sizeof(char), 5, fp);
		fread(c, sizeof(char), 1, fp);
		fread(&registro.curso, sizeof(char), 9, fp);
		fread(c, sizeof(char), 1, fp);
		fread(&registro.turma, sizeof(char), 2, fp);
		fread(c, sizeof(char), 1, fp);

	}

	registro.matric[7] = '\0';
	registro.nome[41]= '\0';
	registro.op[6]= '\0';
	registro.curso[10]= '\0';
	registro.turma[3]= '\0';

	printf("%s\n", registro.matric);
	printf("%s\n", registro.nome);
	printf("%s\n", registro.op);
	printf("%s\n", registro.curso);
	printf("%s\n", registro.curso);

}

024312 Leonardo Nunes de Souza                  34    G         AB