

/*  Index -> manipulcao da string de indices*/
Index* CriaIndex();
void InsereIndex(Index *index, struct IndicePrimario indice);
void RemoveIndex(Index *index, int posicao);

/*  Registro*/
VetorRegistro* CriaVRegistro();
void InsereVRegistro(VetorRegistro *index, registro_aluno indice);
void RemoveVRegistro(VetorRegistro *index, int posicao);
void Mostra_Registro(VetorRegistro v_registro[]);