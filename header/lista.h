struct aluno{
	char matric[7];
	char nome[41];
	char op[6];
	char curso[10];
	char turma[3];
};

typedef struct lista Lista;

void libera_lista(Lista *li);
int tamanho_lista(Lista * li);
int lista_vazia(Lista * li);
int insere_lista_final(Lista *li, struct aluno valor);
int remove_lista_1(Lista * li, char dado_secundario1[6]);
int remove_lista_2(Lista * li, char dado_secundario2[2]);