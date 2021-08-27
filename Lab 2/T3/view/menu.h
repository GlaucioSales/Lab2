#include <stdio.h>


#include "../models/agencia.h"
#include "../models/cliente.h"
#include "../models/conta.h"
#include "../models/transacao.h"
#include "../controller/controles.h"


void menuPrincial(Agencias *agencias, Clientes *clientes, Contas *contas, Transacoes *transacoes);

void controlePrincial(int acao, Agencias *agencias, Clientes *clientes, Contas *contas, Transacoes *transacoes);

void menuDeRelatorios(Agencias *agencias, Clientes *clientes, Contas *contas, Transacoes *transacoes);

void controleRelatorios(int acao, Agencias *agencias, Clientes *clientes, Contas *contas, Transacoes *transacoes);

void menuDeTransacao(Transacoes *transacoes, Agencias *agencias, Contas *contas);

void controleTranscao(int acao, Transacoes *transacoes, Agencias *agencias, Contas *contas);