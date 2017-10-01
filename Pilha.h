/*	Funcoes Pilha*/


Pilha * CriaPilha(){
	Pilha *pi;
	pi = (Pilha*) malloc(sizeof(Pilha));
	pi->qtd = 0;
	return pi;
}

void InserePilha(Pilha *pi, int p){

	/*	Pode estar cheia ou pi == null*/
	pi->nrr[pi->qtd] = p;
	pi->qtd++;
}

int RemovePilha(Pilha *pi){

	int topo = pi->nrr[pi->qtd-1];

	pi->qtd--;

	return topo;
}