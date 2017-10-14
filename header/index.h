/*  Index -> manipulcao da string de indices*/



/*  Index -> manipulcao da string de indices*/
Index1* CriaIndex();
void InsereIndex(Index1 *index, struct IndicePrimario indice1);
void RemoveIndex(Index1 *index, int posicao);
void Mostra_Index(Index1 *index);

/*  Index ->secundario*/
Index2* CriaIndexSecundario();
void InsereIndexSecundario(Index2 *index_sec, struct IndiceSecundario indice2);
void RemoveIndexSecundario(Index2 *index_sec, int posicao);

/*  Registro*/
VetorRegistro* CriaVRegistro();
void InsereVRegistro(VetorRegistro *index, registro_aluno indice);
void RemoveVRegistro(VetorRegistro *index, int posicao);
void Mostra_Registro(VetorRegistro v_registro[]);

/*  */
