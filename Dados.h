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

typedef struct IndicePrimario indice_primario;

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
