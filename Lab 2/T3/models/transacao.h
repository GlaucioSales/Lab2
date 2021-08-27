#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../controller/auxiliar.h"
#include "../models/agencia.h"
#include "../models/conta.h"

typedef struct transacao Transacao;

typedef struct transacoes Transacoes;

Transacoes* criaListaDeTransacoes();

Transacao* criaTransacao(int codigoTransacao, int dia, int mes, int ano, int tipoTranscao, Agencia *agencia, Conta *contaPrincipal, Conta *contaSecundaria);

void transacaoSolicitada(int tiposTransacao, Conta *contaPrincipal, Conta *contaSecundaria);

void transacaoDeSaldo(Conta *contaPrincipal);

void transacaoDeSaque(Conta *contaPrincipal);

void transacaoDeTransferencia(Conta *contaPrincipal, Conta *contaSecundaria);

void transacaoDePagamento(Conta *contaPrincipal);

void removerTransacoesDeUmaDeterminadaAgencia(Transacoes *transacoes, Agencia *agencia);

void removerTransacoesDeUmDeterminadoCliente(Transacoes *transacoes, Cliente *cliente);

void removerTransacoesDeUmaDeterminadaConta(Transacoes *transacoes, Conta *conta);

int insereNaListaDeTransacoesVazia (Transacoes* transacoes, Transacao *transacao);

int insereNoInicioDaListaDeTransacoes(Transacoes *transacoes, Transacao *transacao);

int insereNoFinalDaListaDeTransacoes(Transacoes *transacoes, Transacao *transacao);

int listaDeTransacoesVazia (Transacoes *transacoes);

int tamanhoListaDeTransacoes(Transacoes *transacoes);

int removeTransacaoDaListaDeTransacoes(Transacoes *transacoes, int pos);

int destruirListaDeTransacoes(Transacoes *transacoes);

int buscarPosicaoTransacaoPorCodigo(Transacoes *transacoes, int codigoTransacao);

void imprimeCodigoTransacao(Transacao *transacao);

void imprimeDataDaTransacao(Transacao *transacao);

void imprimeTipoDeTransacao(Transacao *transacao);

void imprimeTransacao(Transacao *transacao);

void imprimeListaDeTransacoes(Transacoes *transacoes);

void imprimeListaDeTransacoesDeUmDeterminadoMes(Transacoes *transacoes, int mes, int tipoTranscao);