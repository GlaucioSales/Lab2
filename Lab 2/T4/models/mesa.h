#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define NUM_MAX_PESSOAS_MESA 4

typedef struct mesa Mesa;

Mesa*** alocaMatrizDeMesas(int linhas, int colunas);

void liberarMesas(Mesa ***mesas, int linhas, int colunas);

void inicializarMesas(Mesa ***mesas, int linhas, int colunas);

void disponibilizarMesa(Mesa *mesa, int valor);

void liberarMesaQueEstavaOcupada(Mesa *mesa);

void imprimeNumeroDaMesa(Mesa *mesa);

void imprimeQuantidadeDePessoasSentadas(Mesa *mesa);

void imprimeNumeroDaComanda(Mesa *mesa);

void imprimeSeEstaLivre(Mesa *mesa);

void imprimeMesa(Mesa * mesa);

void imprimeTodasAsMesas(Mesa ***mesas, int linhas, int colunas);

void imprimeTodasAsMesasVazias(Mesa ***mesas, int linhas, int colunas);

bool mesaEstaLivre(Mesa *mesa);

bool colocarPessoasNaMesa(Mesa *mesa, int quantidadeDePessoas);

Mesa* localizarMesaLivre(Mesa ***mesas, int linhas, int colunas);

Mesa* localizarMesaPeloNumero(Mesa ***mesas, int linhas, int colunas, int numeroDaMesa);