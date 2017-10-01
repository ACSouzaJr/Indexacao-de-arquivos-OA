/*	Pilha estatica*/

struct Pilha
{
	int qtd;
	int nrr[20];
};
typedef strct Pilha Pilha;



Pilha * CriaPilha();
void InserePilha(Pilha *pi, int p);
int RemovePilha(Pilha *pi);