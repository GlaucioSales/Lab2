#include <stdio.h>
#include <string.h>


#include "auxiliar.h"
#include "../models/agencia.h"
#include "../models/cliente.h"
#include "../models/conta.h"
#include "../models/transacao.h"

void sair(Agencias *agencias, Clientes *clientes, Contas *contas, Transacoes *transacoes);

void cadastrarUmaNovaAgencia(Agencias *agencias);

int colocarAgenciaNaListaDeAgencias(Agencias *agencias, Agencia *agencia);

void excluirUmaAgencia(Agencias *agencias, Contas *contas, Transacoes *transacoes);

void cadastrarUmNovoCliente(Clientes *clientes);

int colocarClienteNaListaDeClientes(Clientes *clientes, Cliente *cliente);

void excluirUmCliente(Clientes *clientes, Contas *contas, Transacoes *transacoes);

void cadastrarUmaNovaConta(Contas *contas, Agencias *agencias, Clientes *clientes);

int colocarContaNaListaDeContas(Contas *contas, Conta *conta);

void excluirUmaConta(Contas *contas, Transacoes *transacoes);

void verificarSaldo(Transacoes *transacoes, Agencias *agencias, Contas *contas);

void efetuaSaque(Transacoes *transacoes, Agencias *agencias, Contas *contas);

void efetuaTransferencia(Transacoes *transacoes, Agencias *agencias, Contas *contas);

void efetuaPagemento(Transacoes *transacoes, Agencias *agencias, Contas *contas);

void iniciaUmaTransacao(Transacoes *transacoes, int tipoTranscao, Agencias *agencias, Contas *contas);

int colocarTransacaoNaListaDeTransacoes(Transacoes *transacoes, Transacao *transacao);

void excluirUmaTransacao(Transacoes *transacoes);

Agencia* recuperaAgencia(Agencias *agencias);

Cliente* recuperaCliente(Clientes *clientes);

void listarTodasAsAgencias(Agencias *agencias);

void listarTodosOsClientes(Clientes *clientes);

void listarTodasAsContas(Contas *contas);

void listarTodasAsTransacoes(Transacoes *transacoes);

void listarNomeClientesEAgenciasEmQuePossuemContas(Contas *contas);

void listarAgenciasSemContasAbertas(Agencias *agencias, Contas *contas);

void listarTodosOsSaquesEfetuadosEmUmDeterminadoMes(Transacoes *transacoes);

void listarSaldoContasNaoNegativo(Contas *contas);

void listarTodasAsContasDeUmDeterminadoCliente(Clientes *clientes, Contas *contas);