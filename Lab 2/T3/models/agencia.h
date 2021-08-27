#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agencia Agencia;

typedef struct agencias Agencias;

Agencias* criaListaDeAgencias();

Agencia* criaAgencia(int codAgencia,char nome[81], char endereco[255], char nomeGerente[81]);

int getCodigoDaAgencia(Agencia *agencia);

Agencia* getInicioDaListaDeAgencias(Agencias *agencias);

Agencia* getProximaAgencia(Agencia *agencia);

int insereNaListaDeAgenciasVazia (Agencias* agencias, Agencia *agencia);

int insereNoInicioDaListaDeAgencias(Agencias *agencias, Agencia *agencia);

int insereNoFinalDaListaDeAgencias(Agencias *agencias, Agencia *agencia);

int listaDeAgenciasVazia (Agencias *agencias);

int tamanhoListaDeAgencias(Agencias *agencias);

int removeAgenciaDaListaDeAgencias(Agencias *agencias, int pos);

int destruirListaDeAgencias(Agencias *agencias);

int buscarPosicaoAgenciaPorCodigo(Agencias *agencias, int codAgencia);

Agencia* buscaAgenciaPorCodigo(Agencias *agencias, int codAgencia);

void imprimeCodigoAgencia(Agencia* agencia);

void imprimeNomeAgencia(Agencia* agencia);

void imprimeEnderecoAgencia(Agencia* agencia);

void imprimeNomeGerenteAgencia(Agencia* agencia);

void imprimeOTamanhoDaListaDeAgencias(Agencias* agencias);

void imprimeAgencia(Agencia *agencia);

void imprimeListaDeAgencias(Agencias *agencias);