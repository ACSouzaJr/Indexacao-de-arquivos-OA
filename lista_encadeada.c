struct lista{
	int lugar;
	struct aluno dados[50]; // maximo de 50 alunos
};

Lista* cria_lista(){
	Lista * li = (Lista*) malloc(sizeof(struct lista));
	if(li != NULL)
		li->lugar = 0;
	return li;
}

void libera_lista(Lista *li){
	free(li);
}

int tamanho_lista(Lista* li){
	if(li == NULL) return -1;
	else
		return li->lugar;
}

int lista_vazia(Lista * li){
	if(li == NULL) return -1;
	return (li->dados == 0);
}

int insere_lista_final(Lista *li, struct aluno valor){
	if(li == NULL) return 0;
	li->dados[li->lugar] = valor;
	li->lugar++;
	return 1;  
}

int remove_lista_1(Lista * li, int dado_secundario1){
	if(li == NULL) return 0;
	if(li->lugar == 0) return 0;
	int k, i = 0;
	while(i < li->lugar && li->dados[i].OP != dado_secundario1)
		++i;
	if(li == li->lugar) return 0;
	for(k=i; k < li->lugar-1; k++)
		li->dados[k] = li->dados[k+1];
	li->lugar--;
	return 1;
}

int remove_lista_2(Lista * li, char dado_secundario2[2]){
	if(li == NULL) return 0;
	if(li->lugar == 0) return 0;
	int k, i = 0;
	while(i < li->lugar && li->dados[i].turma != dado_secundario2)
		++i;
	if(li == li->lugar) return 0;
	for(k=i; k < li->lugar-1; k++)
		li->dados[k] = li->dados[k+1];
	li->lugar--;
	return 1;
}


