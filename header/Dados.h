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

struct ConjuntoRegistro
{
    int tamanho;
    registro_aluno registro[100];
};

typedef struct ConjuntoRegistro VetorRegistro;


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

typedef struct Index Index1;

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
    struct IndiceSecundario indice_secundario[100];
};

typedef struct IndexSec Index2;


/*  Declaracao de funcoes*/

/*  funcoes.c*/
void CriarIndice(Index1 *index, Index2 *index2_op, Index2 *index2_turma, VetorRegistro *v_registro);
void AtualizaIndice( const char *arquivo, Index1 *Index );
void AtualizaIndiceSec( const char *arquivo, Index2 *index );

/*  Heap*/
void BuildHeap( Index1 vetor[], int tamanho );
void Heapify( Index1 vetor[], int i, int tamanho );
void HeapSort( Index1 vetor[] );

void BuildHeapsec( Index2 vetor[], int tamanho );
void Heapifysec( Index2 vetor[], int i, int tamanho );
void HeapSortsec( Index2 vetor[] );

/*  Busca binaria*/
int buscabinaria(char *busca, Index1 vetor[], int inicio, int fim);
int buscabinariasec(char *busca, Index2 *vetor, int inicio, int fim);
