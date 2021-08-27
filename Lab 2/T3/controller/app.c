#include "app.h"

void app(){
    Agencias *agencias = criaListaDeAgencias();
    Clientes *clientes = criaListaDeClientes();;
    Contas *contas  = criaListaDeContas();;
    Transacoes *transacoes = criaListaDeTransacoes();
    menuPrincial(agencias, clientes, contas, transacoes);
}

