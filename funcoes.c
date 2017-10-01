/*
*	Reescreve os indices primarios no arquivo de indices
*	Apaga o arquivo e reescreve
*/

void AtualizaIndice( const char *arquivo, indice_primario *Index ){

	FILE *fp;

	int tamanho = sizeof(Index) / sizeof(Index[0]);

	fp = fopen( "arquivo", "w" );

	/*lista cresce verticalmente*/
	for ( int i = 0; i < tamanho; ++i )
	{
		//fwrite(&Index[i]->chave_primaria, sizeof(indice_primario), 1, fp);
		fprintf( fp, "%s\t", Index[i]->chave_primaria );
		fprintf( fp, "%d\n", Index[i]->nrr );
	}

	fclose(fp);
}


/*	NAO funciona*/
void CriarIndice( const char *arquivo ){

	FILE *fp;

	fp = fopen( "arquivo", "r" );

	registro_aluno registro;

	while( !feof(fp) ){

		fread(&registro.matric, sizeof(char), 6, fp);
		//fread(, sizeof(char), 1, fp);
		fread(&registro.nome, sizeof(char), 40, fp);
		fread(&registro.op, sizeof(char), 5, fp);
		fread(&registro.curso, sizeof(char), 9, fp);
		fread(&registro.turma, sizeof(char), 2, fp);

	}

	printf("%s\n", registro.matric);
	printf("%s\n", registro.nome);
	printf("%s\n", registro.op);
	printf("%s\n", registro.curso);
	printf("%s\n", registro.curso);

}