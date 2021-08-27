#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "agencia.h"
#include "cliente.h"

typedef struct conta Conta;

typedef struct contas Contas;

Contas* criaListaDeContas();

Conta* criaConta(int numeroDaConta, char dataDeCriacaoDaConta[11], double saldo, double limitePermitido, Agencia * agencia, Cliente * cliente);

Cliente* getCliente(Conta *conta);

int getNumeroDaConta(Conta *conta);

int agenciaPossuiConta(Contas *contas, Agencia *agencia);

int verificaSeExisteEmUmaContaComUmaDeterminadaAgencia(Contas *contas, Agencia *agencia);

int insereNaListaDeContasVazia (Contas *contas, Conta *conta);

int insereNoInicioDaListaDeContas(Contas *contas, Conta *conta);

int insereNoFinalDaListaDeContas(Contas *contas, Conta *conta);

int listaDeContasVazia(Contas *contas);

int tamanhoListaDeContas(Contas *contas);

int removeContaDaListaDeContas(Contas *contas, int pos);

int destruirListaDeContas(Contas *contas);

int buscarPosicaoPorNumeroConta(Contas *contas, int numeroDaConta);

void removerContasDeUmaDeterminadaAgencia(Contas *contas, Agencia *agencia);

void removerContasDeUmDeterminadoCliente(Contas *contas, Cliente *cliente);

Conta* obterContaPeloNumeroDaConta(Contas *contas, int numeroDaConta);

void debitarValorDaConta(Conta *conta, int valor);

void transferirValorEntreContas(Conta *contaPrincipal, Conta *contaSecundaria, double valor);

void imprimeNumeroDaConta(Conta* conta);

void imprimeDataDeCriacaoDaConta(Conta* conta);

void imprimeSaldoConta(Conta* conta);

void imprimeLimitePermitidoDaConta(Conta* conta);

void imprimeConta(Conta* conta);

void imprimeListaDeContas(Contas *contas);

void imprimeListaDeNomesDosClientesENomesDasAgenciasDeUmaConta(Contas *contas);

void imprimeListaDeContasComSaldoPositivo(Contas *contas);

void imprimeContasDoCliente(Contas *contas, Cliente *cliente);