#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../controller/auxiliar.h"

typedef struct grupo Grupo;

typedef struct fila Fila;

typedef struct elemento Elemento;

Fila* criaFila();

Grupo* criaGrupo(int numeroDePessoasNoGrupo);

void liberarFila(Fila *fila);

int tamanhoDaFila(Fila *fila);

bool filaVazia(Fila *fila);

Grupo* proximoGrupoDaFila(Fila *fila);

int quantidadeDePessoasNoGrupo(Grupo *grupo);

void subtrairDoGrupoAsPessoaQueVaoParaAMesa(Grupo *grupo, int numeroDePessoas);

bool inserirGrupoNaFila(Fila *fila, Grupo *grupo);

bool retirarGrupoDaFila(Fila *fila);

bool retirarUmDeterminadoGrupoDaFila(Fila *fila, int chaveDoGrupo);

void imprimirFila(Fila *fila);

void imprimirGrupo(Grupo *grupo);