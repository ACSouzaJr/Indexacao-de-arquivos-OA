/*
*	024312
*	Leonardo Nunes de Souza
*	34
*	G
*	AB
*/

struct Registro
{

	char matric[7];
	char nome[41];
	char op[6];
	char curso[10];
	char turma[3];

};

typedef struct Registro registro_aluno;

/*
*	matric + nome = 30 char (chave)
*	referencia ao registro (referencia)
*/
struct IndicePrimario
{

	char chave_primaria[31];
	int nrr;

};



struct Index
{
    int tamanho;
    bool flag_atualizacao;
    struct IndicePrimario indice_primario[100];

};

typedef struct Index Index;


/*
*	op	(chave)-> indice secundario
*	matric + nome = 30 char (referencia)
*
*	O indice secundaria e ordena pela chave primaria.
*/

struct IndiceSecundario
{
	char chave_secundaria[5];
	char chave_primaria[31];

};

struct IndexSec
{
    int tamanho;
    bool flag_atualizacao;
    struct IndiceSecundario indice_sec[100];
};

/*if(chave_secundaria == buscabinaria(arquivo))
    vet[]<<chave_primaria
*/



/*  Declaracao de funcoes*/

/*  funcoes.c*/
void CriarIndice(Index *index);
void AtualizaIndice( const char *arquivo, Index *Index );

/*  Heap*/
void BuildHeap( Index vetor[], int tamanho );
void Heapify( Index vetor[], int i, int tamanho );
void HeapSort( Index vetor[] );

/*  Busca binaria*/
int buscabinaria(char *busca, Index vetor[], int inicio, int fim);

/*  esqueleto.c*/