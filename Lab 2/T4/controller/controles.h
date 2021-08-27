#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "auxiliar.h"
#include "../models/mesa.h"
#include "../models/fila.h"

void sair(Mesa ***mesas, Fila *fila, int linhas, int colunas);

void imprimirDadosSobreMesa(Mesa ***mesas, int linhas, int colunas);

void imprimirDadosSobreTodasAsMesas(Mesa ***mesas, int linhas, int colunas);

void imprimirDadosSobreMesasVazias(Mesa ***mesas, int linhas, int colunas);

void cadastrarGrupoDePessoas(Mesa ***mesas, Fila *fila, int linhas, int colunas);

int alocarGrupoNaMesa(Mesa ***mesas, int linhas, int colunas, int numeroDePessoasNoGrupo);

void liberarMesa(Mesa ***mesas, Fila *fila, int linhas, int colunas);

void alocaPessoasDaFilaNasMesas(Mesa *mesa, Fila *fila);

void desistiuDeEsperar(Fila *fila);

void imprimirTodosOsGruposNaFinal(Fila *fila);

